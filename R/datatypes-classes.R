# Unlike Python Polars, the DataType object is defined on the Rust side, so this file provide wrappers

# The env for storing data type methods
polars_datatype__methods <- new.env(parent = emptyenv())

#' @export
wrap.PlRDataType <- function(x, ...) {
  self <- new.env(parent = emptyenv())
  self$`_dt` <- x
  dtype_names <- x$`_get_dtype_names`()

  lapply(names(polars_datatype__methods), function(name) {
    fn <- polars_datatype__methods[[name]]
    environment(fn) <- environment()
    assign(name, fn, envir = self)
  })

  ## Enum only method
  if ("polars_dtype_enum" %in% dtype_names) {
    fn <- function(other) {
      wrap({
        check_polars_dtype(other)
        if (!inherits(other, "polars_dtype_enum")) {
          abort("`other` must be a Enum data type")
        }

        PlRDataType$new_enum(unique(c(self$categories, other$categories)))
      })
    }
    environment(fn) <- environment()
    assign("union", fn, envir = self)
  }

  # Bindings mimic attributes of DataType classes of Python Polars
  env_bind(self, !!!x$`_get_datatype_fields`())

  ## _inner is a pointer now, so it should be wrapped
  if (exists("_inner", envir = self)) {
    makeActiveBinding("inner", function() {
      .savvy_wrap_PlRDataType(self$`_inner`) |>
        wrap()
    }, self)
  }

  ## _fields is a list of pointers now, so they should be wrapped
  if (exists("_fields", envir = self)) {
    makeActiveBinding("fields", function() {
      lapply(self$`_fields`, function(x) {
        .savvy_wrap_PlRDataType(x) |>
          wrap()
      })
    }, self)
  }

  class(self) <- c("polars_data_type", dtype_names, "polars_object")
  self
}

# Register data types without arguments as active bindings
on_load({
  c(
    "Int8",
    "Int16",
    "Int32",
    "Int64",
    "UInt8",
    "UInt16",
    "UInt32",
    "UInt64",
    "Float32",
    "Float64",
    "Boolean",
    "String",
    "Binary",
    "Date",
    "Time",
    "Null"
  ) |>
    lapply(function(name) {
      makeActiveBinding(name, function() PlRDataType$new_from_name(name) |> wrap(), pl)
    })
})

pl__Decimal <- function(precision = NULL, scale = 0L) {
  PlRDataType$new_decimal(scale = scale, precision = precision) |>
    wrap()
}

pl__Datetime <- function(time_unit = c("us", "ns", "ms"), time_zone = NULL) {
  wrap({
    time_unit <- arg_match0(time_unit, c("us", "ns", "ms"))
    PlRDataType$new_datetime(time_unit, time_zone)
  })
}

pl__Duration <- function(time_unit = c("us", "ns", "ms")) {
  wrap({
    time_unit <- arg_match0(time_unit, c("us", "ns", "ms"))
    PlRDataType$new_duration(time_unit)
  })
}

pl__Categorical <- function(ordering = c("physical", "lexical")) {
  wrap({
    ordering <- arg_match0(ordering, c("physical", "lexical"))
    PlRDataType$new_categorical(ordering)
  })
}

pl__Enum <- function(categories) {
  # TODO: impliment `issue_unstable_warning`
  wrap({
    check_character(categories, allow_na = FALSE)

    if (anyDuplicated(categories)) {
      abort(sprintf(
        "Enum categories must be unique; found duplicated: %s",
        toString(categories[which(duplicated(categories))])
      ))
    }

    PlRDataType$new_enum(categories)
  })
}

pl__Array <- function(inner, shape) {
  # TODO: impliment `issue_unstable_warning`
  wrap({
    check_polars_dtype(inner)
    PlRDataType$new_array(inner$`_dt`, shape)
  })
}

pl__List <- function(inner) {
  wrap({
    check_polars_dtype(inner)
    PlRDataType$new_list(inner$`_dt`)
  })
}

pl__Struct <- function(...) {
  parse_into_list_of_datatypes(...) |>
    PlRDataType$new_struct() |>
    wrap()
}

datatype__eq <- function(other) {
  wrap({
    check_polars_dtype(other)
    self$`_dt`$eq(other$`_dt`)
  })
}

datatype__ne <- function(other) {
  wrap({
    check_polars_dtype(other)
    self$`_dt`$ne(other$`_dt`)
  })
}

datatype__is_numeric <- function() {
  inherits(self, "polars_dtype_numeric")
}

datatype__is_decimal <- function() {
  inherits(self, "polars_dtype_decimal")
}

datatype__is_integer <- function() {
  inherits(self, "polars_dtype_integer")
}

datatype__is_signed_integer <- function() {
  inherits(self, "polars_dtype_signed_integer")
}

datatype__is_unsigned_integer <- function() {
  inherits(self, "polars_dtype_unsigned_integer")
}

datatype__is_float <- function() {
  inherits(self, "polars_dtype_float")
}

datatype__is_temporal <- function() {
  inherits(self, "polars_dtype_temporal")
}

datatype__is_nested <- function() {
  inherits(self, "polars_dtype_nested")
}

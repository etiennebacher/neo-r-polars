# Unlike Python Polars, the DataType object is defined on the Rust side, so this file provide wrappers

# The env for storing data type methods
polars_datatype__methods <- new.env(parent = emptyenv())

#' @export
is_polars_data_type <- function(x) {
  inherits(x, "polars_data_type")
}

#' @export
wrap.PlRDataType <- function(x, ...) {
  self <- new.env(parent = emptyenv())
  self$`_dt` <- x

  lapply(names(polars_datatype__methods), function(name) {
    fn <- polars_datatype__methods[[name]]
    environment(fn) <- environment()
    assign(name, fn, envir = self)
  })

  ## Enum only method
  if (self$`_dt`$is_enum()) {
    fn <- function(other) {
      wrap({
        if (!isTRUE(is_polars_data_type(other))) {
          abort("`other` must be a polars data type")
        }
        if (!other$`_dt`$is_enum()) {
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

  class(self) <- c("polars_data_type", "polars_object")
  self
}

pl__Decimal <- function(precision = NULL, scale = 0L) {
  PlRDataType$new_decimal(scale = scale, precision = precision) |>
    wrap()
}

pl__Datetime <- function(time_unit = "us", time_zone = NULL) {
  PlRDataType$new_datetime(time_unit, time_zone) |>
    wrap()
}

pl__Duration <- function(time_unit = "us") {
  PlRDataType$new_duration(time_unit) |>
    wrap()
}

pl__Categorical <- function(ordering = "physical") {
  PlRDataType$new_categorical(ordering) |>
    wrap()
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

  if (!isTRUE(is_polars_data_type(inner))) {
    abort("`inner` must be a polars data type")
  }

  PlRDataType$new_array(inner$`_dt`, shape) |>
    wrap()
}

pl__List <- function(inner) {
  if (!isTRUE(is_polars_data_type(inner))) {
    abort("`inner` must be a polars data type")
  }

  PlRDataType$new_list(inner$`_dt`) |>
    wrap()
}

pl__Struct <- function(...) {
  parse_into_list_of_datatypes(...) |>
    PlRDataType$new_struct() |>
    wrap()
}

datatype__eq <- function(other) {
  if (!isTRUE(is_polars_data_type(other))) {
    abort("`other` must be a polars data type")
  }

  self$`_dt`$eq(other$`_dt`) |>
    wrap()
}

datatype__ne <- function(other) {
  if (!isTRUE(is_polars_data_type(other))) {
    abort("`other` must be a polars data type")
  }

  self$`_dt`$ne(other$`_dt`) |>
    wrap()
}

datatype__is_temporal <- function() {
  self$`_dt`$is_temporal()
}

datatype__is_enum <- function() {
  self$`_dt`$is_enum()
}

datatype__is_categorical <- function() {
  self$`_dt`$is_categorical()
}

datatype__is_string <- function() {
  self$`_dt`$is_string()
}

datatype__is_logical <- function() {
  self$`_dt`$is_bool()
}

datatype__is_float <- function() {
  self$`_dt`$is_float()
}

datatype__is_numeric <- function() {
  self$`_dt`$is_numeric()
}

datatype__is_integer <- function() {
  self$`_dt`$is_integer()
}

datatype__is_signed_integer <- function() {
  self$`_dt`$is_signed_integer()
}

datatype__is_unsigned_integer <- function() {
  self$`_dt`$is_unsigned_integer()
}

datatype__is_null <- function() {
  self$`_dt`$is_null()
}

datatype__is_binary <- function() {
  self$`_dt`$is_binary()
}

datatype__is_primitive <- function() {
  self$`_dt`$is_primitive()
}

datatype__is_bool <- function() {
  self$`_dt`$is_bool()
}

datatype__is_array <- function() {
  self$`_dt`$is_list()
}

datatype__is_list <- function() {
  self$`_dt`$is_list()
}

datatype__is_nested <- function() {
  self$`_dt`$is_nested()
}

datatype__is_struct <- function() {
  self$`_dt`$is_struct()
}

datatype__is_ord <- function() {
  self$`_dt`$is_ord()
}

datatype__is_known <- function() {
  self$`_dt`$is_known()
}

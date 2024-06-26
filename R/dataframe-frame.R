# The env for storing dataframe methods
polars_dataframe__methods <- new.env(parent = emptyenv())

#' @export
wrap.PlRDataFrame <- function(x) {
  self <- new.env(parent = emptyenv())
  self$`_df` <- x

  lapply(names(polars_dataframe__methods), function(name) {
    fn <- polars_dataframe__methods[[name]]
    environment(fn) <- environment()
    assign(name, fn, envir = self)
  })

  class(self) <- "polars_data_frame"
  self
}

pl__DataFrame <- function(...) {
  list2(...) |>
    as_polars_df()
}

dataframe__to_struct <- function(name = "") {
  self$`_df`$to_struct(name) |>
    wrap()
}

dataframe__lazy <- function() {
  self$`_df`$lazy() |>
    wrap()
}

dataframe__get_columns <- function() {
  self$`_df`$get_columns() |>
    lapply(\(ptr) {
      .savvy_wrap_PlRSeries(ptr) |>
        wrap()
    })
}

dataframe__to_list <- function() {
  self$get_columns() |>
    lapply(as.vector)
}

dataframe__group_by <- function(..., maintain_order = FALSE) {
  wrap_to_group_by(self, list2(...), maintain_order)
}

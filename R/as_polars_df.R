# TODO: link to data type doc
#' Create a Polars DataFrame from an R object
#'
#' The [as_polars_df()] function creates a [polars DataFrame][DataFrame] from various R objects.
#' [Polars DataFrame][DataFrame] is based on a sequence of [Polars Series][Series],
#' so basically, the input object is converted to a [list] of
#' [Polars Series][Series] by [as_polars_series()],
#' then a [Polars DataFrame][DataFrame] is created from the list.
#'
#' The default method of [as_polars_df()] throws an error,
#' so we need to define methods for the classes we want to support.
#'
#' ## S3 method for [list]
#'
#' - The argument `...` (except `name`) is passed to [as_polars_series()] for each element of the list.
#' - All elements of the list must be converted to the same length of [Series] by [as_polars_series()].
#' - The name of the each element is used as the column name of the [DataFrame].
#'   For unnamed elements, the column name will be an empty string `""` or if the element is a [Series],
#'   the column name will be the name of the [Series].
#'
#' ## S3 method for [data.frame]
#'
#' - The argument `...` (except `name`) is passed to [as_polars_series()] for each column.
#' - All columns must be converted to the same length of [Series] by [as_polars_series()].
#'
#' ## S3 method for [polars_series][Series]
#'
#' This is a shortcut for [`<Series>$to_frame()`][series__to_frame] or
#' [`<Series>$struct$unnest()`][series_struct_unnest], depending on the `from_struct` argument and the [Series] data type.
#' The `column_name` argument is passed to the `name` argument of the [`$to_frame()`][series__to_frame] method.
#'
#' ## S3 method for [polars_lazy_frame][LazyFrame]
#'
#' This is a shortcut for [`<LazyFrame>$collect()`][lazyframe__collect].
#' @inherit pl__DataFrame return
#' @inheritParams as_polars_series
#' @inheritParams lazyframe__collect
#' @param column_name A character or `NULL`. If not `NULL`,
#' name/rename the [Series] column in the new [DataFrame].
#' If `NULL`, the column name is taken from the [Series] name.
#' @param from_struct A logical. If `TRUE` (default) and the [Series] data type is a struct,
#' the [`<Series>$struct$unnest()`][series_struct_unnest] method is used to create a [DataFrame]
#' from the struct [Series]. In this case, the `column_name` argument is ignored.
#' @seealso
#' - [`<DataFrame>$to_r_list()`][dataframe__to_r_list]: Export the DataFrame as an R list of R vectors.
#' @examples
#' # list
#' as_polars_df(list(a = 1:2, b = c("foo", "bar")))
#'
#' # data.frame
#' as_polars_df(data.frame(a = 1:2, b = c("foo", "bar")))
#'
#' # polars_series
#' s_int <- as_polars_series(1:2, "a")
#' s_struct <- as_polars_series(
#'   data.frame(a = 1:2, b = c("foo", "bar")),
#'   "struct"
#' )
#'
#' ## Use the Series as a column
#' as_polars_df(s_int)
#' as_polars_df(s_struct, column_name = "values", from_struct = FALSE)
#'
#' ## Unnest the struct data
#' as_polars_df(s_struct)
#' @export
as_polars_df <- function(x, ...) {
  UseMethod("as_polars_df")
}

#' @rdname as_polars_df
#' @export
as_polars_df.default <- function(x, ...) {
  abort(
    paste0("Unsupported class for `as_polars_df()`: ", toString(class(x))),
    call = parent.frame()
  )
}

#' @rdname as_polars_df
#' @export
as_polars_df.polars_series <- function(
    x, ...,
    column_name = NULL,
    from_struct = TRUE) {
  if (isTRUE(from_struct) && x$dtype$is_struct()) {
    x$struct$unnest()
  } else {
    x$to_frame(name = column_name)
  }
}

#' @rdname as_polars_df
#' @export
as_polars_df.polars_data_frame <- function(x, ...) {
  x
}

#' @rdname as_polars_df
#' @export
as_polars_df.polars_group_by <- function(x, ...) {
  x$df
}

#' @rdname as_polars_df
#' @export
as_polars_df.polars_lazy_frame <- function(
    x, ..., type_coercion = TRUE,
    predicate_pushdown = TRUE,
    projection_pushdown = TRUE,
    simplify_expression = TRUE,
    slice_pushdown = TRUE,
    comm_subplan_elim = TRUE,
    comm_subexpr_elim = TRUE,
    cluster_with_columns = TRUE,
    no_optimization = FALSE,
    streaming = FALSE) {
  x$collect(
    type_coercion = type_coercion,
    predicate_pushdown = predicate_pushdown,
    projection_pushdown = projection_pushdown,
    simplify_expression = simplify_expression,
    slice_pushdown = slice_pushdown,
    comm_subplan_elim = comm_subplan_elim,
    comm_subexpr_elim = comm_subexpr_elim,
    cluster_with_columns = cluster_with_columns,
    streaming = streaming
  )
}

#' @rdname as_polars_df
#' @export
as_polars_df.list <- function(x, ...) {
  .args <- list2(...)
  # Should not pass the `name` argument
  .args$name <- NULL
  lapply(x, \(column) eval(call2("as_polars_series", column, !!!.args))$`_s`) |>
    PlRDataFrame$init() |>
    wrap()
}

#' @rdname as_polars_df
#' @export
as_polars_df.data.frame <- as_polars_df.list

#' @rdname as_polars_df
#' @export
as_polars_df.NULL <- function(x, ...) {
  wrap({
    if (missing(x)) {
      abort("The `x` argument of `as_polars_df()` can't be missing")
    }
    PlRDataFrame$init(list())
  })
}

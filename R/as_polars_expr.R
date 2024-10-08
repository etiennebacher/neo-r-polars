# Same as Python Polars' `parse_into_expression`
# TODO: link to Expr class page
# TODO: link to data type page
# TODO: link to `expr__first`
#' Create a Polars Expression from an R object
#'
#' The [as_polars_expr()] function creates a polars Expression from various R objects.
#' This function is used internally by various polars functions that accept Expressions.
#' In most cases, users should use [`pl$lit()`][pl__lit] instead of this function, which is
#' a shorthand for `as_polars_expr(x, as_lit = TRUE)`.
#' (In other words, this function can be considered as an internal implementation to realize
#' the `lit` function of the Polars API in other languages.)
#'
#' Because R objects are typically mapped to [Series], this function often calls [as_polars_series()] internally.
#' However, unlike R, Polars has scalars of length 1, so if an R object is converted to a [Series] of length 1,
#' this function will use `<Expr>$first()` at the end to convert it to a scalar value.
#' If you want to implement your own conversion from an R class to a Polars object,
#' define an S3 method for [as_polars_series()] instead of this function.
#'
#' ## Default S3 method
#'
#' Create a [Series] by calling [as_polars_series()] and then convert that [Series] to an Expression.
#' If the length of the [Series] is `1`, it will be converted to a scalar value using `<Expr>$first()` at the end.
#'
#' Additional arguments `...` are passed to [as_polars_series()].
#'
#' ## S3 method for [character]
#'
#' If the `as_lit` argument is `FALSE` (default), this function will call [`pl$col()`][pl__col] and
#' the character vector is treated as column names.
#'
#' # Literal scalar mapping
#'
#' Since R has no scalar class, each of the following types of length 1 cases is specially
#' converted to a scalar literal.
#'
#' - character: String
#' - logical: Boolean
#' - integer: Int32
#' - double: Float64
#'
#' These types' `NA` is converted to a `null` literal with casting to the corresponding Polars type.
#'
#' The [raw] type vector is converted to a Binary scalar.
#'
#' - raw: Binary
#'
#' `NULL` is converted to a `null` literal.
#'
#' - NULL: null
#'
#' Other scalar values cannot be created directly, so we need to `$cast()` from other scalar values
#' or extract them with the `$first()` method from a [Series].
#' ([as_polars_expr()] and [`pl$lit()`][pl__lit] automatically apply the `$first()` method to extract scalar values
#' inside the default S3 method of [as_polars_expr()].)
#' @inheritParams as_polars_series
#' @param as_lit A logical value indicating whether to treat vector as literal values or not.
#' This argument is always set to `TRUE` when calling this function from [`pl$lit()`][pl__lit],
#' and expects to return literal values. See examples for details.
#' @return A polars Expression
#' @seealso
#' - [as_polars_series()]: R -> Polars type mapping is mostly defined by this function.
#' @examples
#' # character
#' ## as_lit = FALSE (default)
#' as_polars_expr("a") # Same as `pl$col("a")`
#' as_polars_expr(c("a", "b")) # Same as `pl$col("a", "b")`
#'
#' ## as_lit = TRUE
#' as_polars_expr(character(0), as_lit = TRUE)
#' as_polars_expr("a", as_lit = TRUE)
#' as_polars_expr(NA_character_, as_lit = TRUE)
#' as_polars_expr(c("a", "b"), as_lit = TRUE)
#'
#' # logical
#' as_polars_expr(logical(0))
#' as_polars_expr(TRUE)
#' as_polars_expr(NA)
#' as_polars_expr(c(TRUE, FALSE))
#'
#' # integer
#' as_polars_expr(integer(0))
#' as_polars_expr(1L)
#' as_polars_expr(NA_integer_)
#' as_polars_expr(c(1L, 2L))
#'
#' # double
#' as_polars_expr(double(0))
#' as_polars_expr(1)
#' as_polars_expr(NA_real_)
#' as_polars_expr(c(1, 2))
#'
#' # raw
#' as_polars_expr(raw(0))
#' as_polars_expr(charToRaw("foo"))
#'
#' # NULL
#' as_polars_expr(NULL)
#'
#' # default method (for list)
#' as_polars_expr(list())
#' as_polars_expr(list(1))
#' as_polars_expr(list(1, 2))
#'
#' # polars_series
#' ## Unlike the default method, this method does not call `$first()`
#' as_polars_series(1) |>
#'   as_polars_expr()
#' @export
as_polars_expr <- function(x, ...) {
  UseMethod("as_polars_expr")
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.default <- function(x, ...) {
  wrap({
    series <- as_polars_series(x, name = "literal", ...)

    if (series$len() == 1L) {
      # Treat as scalar
      lit_from_series(series$`_s`)$first()
    } else {
      lit_from_series(series$`_s`)
    }
  })
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.polars_expr <- function(x, ...) {
  x
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.polars_series <- function(x, ...) {
  lit_from_series(x$`_s`) |>
    wrap()
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.character <- function(x, ..., as_lit = FALSE) {
  wrap({
    if (isFALSE(as_lit)) {
      pl$col(x)
    } else {
      if (length(x) == 1L) {
        if (is.na(x)) {
          lit_null()$cast(pl$String$`_dt`, strict = TRUE)
        } else {
          lit_from_str(x)
        }
      } else {
        as_polars_expr.default(x)
      }
    }
  })
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.logical <- function(x, ...) {
  wrap({
    if (length(x) == 1L) {
      if (is.na(x)) {
        lit_null()$cast(pl$Boolean$`_dt`, strict = TRUE)
      } else {
        lit_from_bool(x)
      }
    } else {
      as_polars_expr.default(x)
    }
  })
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.integer <- function(x, ...) {
  wrap({
    if (length(x) == 1L) {
      if (is.na(x)) {
        lit_null()$cast(pl$Int32$`_dt`, strict = TRUE)
      } else {
        lit_from_i32(x)
      }
    } else {
      as_polars_expr.default(x)
    }
  })
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.double <- function(x, ...) {
  wrap({
    if (length(x) == 1L) {
      if (is.na(x)) {
        lit_null()$cast(pl$Float64$`_dt`, strict = TRUE)
      } else {
        lit_from_f64(x)
      }
    } else {
      as_polars_expr.default(x)
    }
  })
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.raw <- function(x, ...) {
  lit_from_raw(x) |>
    wrap()
}

#' @rdname as_polars_expr
#' @export
as_polars_expr.NULL <- function(x, ...) {
  wrap({
    if (missing(x)) {
      abort("The `x` argument of `as_polars_expr()` can't be missing")
    }
    lit_null()
  })
}

#' @export
`+.polars_expr` <- function(e1, e2) {
  if (missing(e2)) {
    e1
  } else {
    as_polars_expr(e1, as_lit = TRUE)$add(e2)
  }
}

#' @export
`-.polars_expr` <- function(e1, e2) {
  if (missing(e2)) {
    e1$neg()
  } else {
    as_polars_expr(e1, as_lit = TRUE)$sub(e2)
  }
}

#' @export
`*.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$mul(e2)
}

#' @export
`/.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$true_div(e2)
}

#' @export
`%%.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$mod(e2)
}

#' @export
# nolint start: object_name_linter
`%/%.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$floor_div(e2)
}
# nolint end

#' @export
`^.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$pow(e2)
}

#' @export
`<.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$lt(e2)
}

#' @export
`>.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$gt(e2)
}

#' @export
`<=.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$le(e2)
}

#' @export
`>=.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$ge(e2)
}

#' @export
`==.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$eq(e2)
}

#' @export
`!=.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$ne(e2)
}

#' @export
`!.polars_expr` <- function(e1) {
  as_polars_expr(e1, as_lit = TRUE)$invert()
}

#' @export
`&.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$and(e2)
}

#' @export
`|.polars_expr` <- function(e1, e2) {
  as_polars_expr(e1, as_lit = TRUE)$or(e2)
}

% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-list.R
\name{expr_list_get}
\alias{expr_list_get}
\title{Get the value by index in every sub-list}
\usage{
expr_list_get(index, ..., null_on_oob = TRUE)
}
\arguments{
\item{index}{An Expr or something coercible to an Expr, that must return a
single index. Values are 0-indexed (so index 0 would return the first item
of every sub-list) and negative values start from the end (index \code{-1}
returns the last item).}

\item{...}{These dots are for future extensions and must be empty.}

\item{null_on_oob}{If \code{TRUE}, return \code{null} if an index is out of bounds.
Otherwise, raise an error.}
}
\value{
A polars \link{expression}
}
\description{
This allows to extract one value per list only. To extract several values by
index, use \code{\link[=expr_list_gather]{$list$gather()}}.
}
\examples{
df <- pl$DataFrame(
  values = list(c(2, 2, NA), c(1, 2, 3), NA, NULL),
  idx = c(1, 2, NA, 3)
)
df$with_columns(
  using_expr = pl$col("values")$list$get("idx"),
  val_0 = pl$col("values")$list$get(0),
  val_minus_1 = pl$col("values")$list$get(-1),
  val_oob = pl$col("values")$list$get(10)
)
}

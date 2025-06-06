% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{expr__is_null}
\alias{expr__is_null}
\title{Check if elements are NULL}
\usage{
expr__is_null()
}
\value{
A polars \link{expression}
}
\description{
Check if elements are NULL
}
\examples{
df <- pl$DataFrame(
  a = c(1, 2, NA, 1, 5),
  b = c(1, 2, NaN, 1, 5)
)
df$with_columns(
  a_null = pl$col("a")$is_null(),
  b_null = pl$col("b")$is_null()
)
}

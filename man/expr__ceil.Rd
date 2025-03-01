% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{expr__ceil}
\alias{expr__ceil}
\title{Rounds up to the nearest integer value}
\usage{
expr__ceil()
}
\value{
A polars \link{expression}
}
\description{
This only works on floating point Series.
}
\examples{
df <- pl$DataFrame(a = c(0.3, 0.5, 1.0, 1.1))
df$with_columns(
  ceil = pl$col("a")$ceil()
)
}

% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/functions-aggregation-horizontal.R
\name{pl__sum_horizontal}
\alias{pl__sum_horizontal}
\title{Compute the sum horizontally across columns}
\usage{
pl__sum_horizontal(...)
}
\arguments{
\item{...}{<\code{\link[rlang:dyn-dots]{dynamic-dots}}> Columns to aggregate
horizontally. Accepts expressions. Strings are parsed as column
names, other non-expression inputs are parsed as literals.}
}
\value{
A polars \link{expression}
}
\description{
Compute the sum horizontally across columns
}
\examples{
df <- pl$DataFrame(
  a = c(1, 8, 3)
  b = c(4, 5, NA),
  c = c("x", "y", "z")
)
df$with_columns(
  sum = pl$sum_horizontal("a", "b")
)
}

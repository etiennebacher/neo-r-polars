% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{expr__not}
\alias{expr__not}
\title{Negate a boolean expression}
\usage{
expr__not()
}
\value{
A polars \link{expression}
}
\description{
Negate a boolean expression
}
\examples{
df <- pl$DataFrame(a = c(TRUE, FALSE, FALSE, NA))

df$with_columns(a_not = pl$col("a")$not())

# Same result with "!"
df$with_columns(a_not = !pl$col("a"))
}

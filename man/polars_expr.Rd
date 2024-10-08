% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{polars_expr}
\alias{polars_expr}
\alias{Expr}
\title{Polars Expression class (\code{polars_expr})}
\description{
An expression is a tree of operations that describe how to construct one or more \link{Series}.
As the outputs are \link{Series}, it is straightforward to apply a sequence of expressions each of
which transforms the output from the previous step.
See examples for details.
}
\examples{
# An expression, 'Select column `foo`'
pl$col("foo")

# Expressions will be evaluated inside a context, such as `<DataFrame>$select()`
df <- pl$DataFrame(
  foo = c(1, 2, 1, 2, 3),
  bar = c(5, 4, 3, 2, 1),
)

df$select(pl$col("foo"))
}
\seealso{
\itemize{
\item \code{\link[=pl__lit]{pl$lit()}}: Create a literal expression.
\item \code{\link[=pl__col]{pl$col()}}: Create an expression representing column(s) in a \link{DataFrame}.
}
}

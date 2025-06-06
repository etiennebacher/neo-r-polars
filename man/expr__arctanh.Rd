% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{expr__arctanh}
\alias{expr__arctanh}
\title{Compute inverse hyperbolic tangent}
\usage{
expr__arctanh()
}
\value{
A polars \link{expression}
}
\description{
Compute inverse hyperbolic tangent
}
\examples{
pl$DataFrame(a = c(-1, tanh(0.5), 0, 1, NA))$
  with_columns(arctanh = pl$col("a")$arctanh())
}

% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/lazyframe-frame.R
\name{lazyframe__first}
\alias{lazyframe__first}
\title{Get the first row of the LazyFrame}
\usage{
lazyframe__first()
}
\value{
A polars \link{LazyFrame}
}
\description{
Get the first row of the LazyFrame
}
\examples{
lf <- pl$LazyFrame(a = 1:4, b = c(1, 2, 1, 1))
lf$first()$collect()
}

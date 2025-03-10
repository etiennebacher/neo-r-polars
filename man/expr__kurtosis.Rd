% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-expr.R
\name{expr__kurtosis}
\alias{expr__kurtosis}
\title{Compute the kurtosis (Fisher or Pearson)}
\usage{
expr__kurtosis(..., fisher = TRUE, bias = TRUE)
}
\arguments{
\item{...}{These dots are for future extensions and must be empty.}

\item{fisher}{If \code{TRUE} (default), Fisher’s definition is used
(normal ==> 0.0). If \code{FALSE}, Pearson’s definition is used (normal ==> 3.0).}

\item{bias}{If \code{FALSE}, the calculations are corrected for statistical bias.}
}
\value{
A polars \link{expression}
}
\description{
Kurtosis is the fourth central moment divided by the square of the variance.
If Fisher’s definition is used, then 3.0 is subtracted from the result to
give 0.0 for a normal distribution. If \code{bias} is \code{FALSE} then the kurtosis
is calculated using \code{k} statistics to eliminate bias coming from biased
moment estimators.
}
\examples{
df <- pl$DataFrame(x = c(1, 2, 3, 2, 1))
df$select(pl$col("x")$kurtosis())
}

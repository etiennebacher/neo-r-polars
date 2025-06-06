% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/series-series.R
\name{series__alias}
\alias{series__alias}
\alias{series__rename}
\title{Rename the Series}
\usage{
series__alias(name)

series__rename(name)
}
\arguments{
\item{name}{The new name.}
}
\value{
A \link[=Series]{polars Series}
}
\description{
\code{\link[=series__rename]{<Series>$rename()}} is an alias for \code{\link[=series__alias]{<Series>$alias()}}.
}
\examples{
series <- pl$Series("a", 1:3)

series$alias("b")
series$rename("b")
}

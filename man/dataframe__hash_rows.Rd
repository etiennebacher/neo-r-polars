% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/dataframe-frame.R
\name{dataframe__hash_rows}
\alias{dataframe__hash_rows}
\title{Hash and combine the rows in this DataFrame}
\usage{
dataframe__hash_rows(seed = 0, seed_1 = NULL, seed_2 = NULL, seed_3 = NULL)
}
\arguments{
\item{seed}{Random seed parameter. Defaults to 0.}

\item{seed_1}{Random seed parameter. Defaults to \code{seed} if not set.}

\item{seed_2}{Random seed parameter. Defaults to \code{seed} if not set.}

\item{seed_3}{Random seed parameter. Defaults to \code{seed} if not set.}
}
\value{
A \link[=Series]{polars Series}
}
\description{
The hash value is of type \link[=polars_dtype]{UInt64}.
}
\details{
This implementation does not guarantee stable results across different
Polars versions. Its stability is only guaranteed within a single version.
}
\examples{
df <- pl$DataFrame(
  foo = c(1, NA, 3, 4),
  ham = c("a", "b", NA, "d")
)
df$hash_rows(seed = 42)
}

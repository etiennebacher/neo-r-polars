% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/infer_polars_dtype.R
\name{infer_polars_dtype}
\alias{infer_polars_dtype}
\alias{infer_polars_dtype.default}
\alias{infer_polars_dtype.polars_series}
\alias{infer_polars_dtype.polars_data_frame}
\alias{infer_polars_dtype.polars_lazy_frame}
\alias{infer_polars_dtype.NULL}
\alias{infer_polars_dtype.list}
\alias{infer_polars_dtype.AsIs}
\alias{infer_polars_dtype.data.frame}
\alias{infer_polars_dtype.vctrs_vctr}
\title{Infer Polars DataType corresponding to a given R object}
\usage{
infer_polars_dtype(x, ...)

\method{infer_polars_dtype}{default}(x, ...)

\method{infer_polars_dtype}{polars_series}(x, ...)

\method{infer_polars_dtype}{polars_data_frame}(x, ...)

\method{infer_polars_dtype}{polars_lazy_frame}(x, ...)

\method{infer_polars_dtype}{`NULL`}(x, ...)

\method{infer_polars_dtype}{list}(x, ..., strict = FALSE)

\method{infer_polars_dtype}{AsIs}(x, ...)

\method{infer_polars_dtype}{data.frame}(x, ...)

\method{infer_polars_dtype}{vctrs_vctr}(x, ...)
}
\arguments{
\item{x}{An R object.}

\item{...}{Additional arguments passed to the methods.}

\item{strict}{A logical value to indicate whether throwing an error when
the input \link{list}'s elements have different data types.
If \code{FALSE} (default), all elements are automatically cast to the super type, or,
casting to the super type is failed, the value will be \code{null}.
If \code{TRUE}, the first non-\code{NULL} element's data type is used as the data type of the inner Series.}
}
\value{
A \link[=DataType]{polars DataType}
}
\description{
This function is a helper function used to quickly find the \link{DataType} corresponding to an R object.
In many cases, this function simply performs something like \code{head(x, 0) |> as_polars_series()}.
It is much faster than actually constructing a \link{Series} using the entire object.
This function is similar to \code{\link[nanoarrow:as_nanoarrow_schema]{nanoarrow::infer_nanoarrow_schema()}}.
}
\details{
S3 objects based on atomic vectors or classes built on the vctrs package will work accurately
if the S3 method of the \code{\link[=as_polars_series]{as_polars_series()}} function is defined.
}
\examples{
infer_polars_dtype(1:10)

# The type inference is also fast for objects
# that would take a long time to construct a Series.
infer_polars_dtype(1:100000000)
}
\seealso{
\itemize{
\item \code{\link[=as_polars_series]{as_polars_series()}}
}
}

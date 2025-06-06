% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/expr-meta.R
\name{expr_meta_tree_format}
\alias{expr_meta_tree_format}
\title{Format the expression as a tree}
\usage{
expr_meta_tree_format()
}
\value{
A character vector
}
\description{
Format the expression as a tree
}
\examples{
my_expr <- (pl$col("foo") * pl$col("bar"))$sum()$over(pl$col("ham")) / 2
my_expr$meta$tree_format() |>
  cat()
}

# TODO: mimic the Python's one
#' @export
print.polars_lazy_frame <- function(x, ...) {
  cat(sprintf("<polars_lazy_frame>\n"))
  cat("NAIVE QUERY PLAN\n")
  cat(" Run `<LazyFrame>$explain()` to see the optimized version.\n\n")
  cat(x$explain(optimized = FALSE))
  cat("\n")
  invisible(x)
}

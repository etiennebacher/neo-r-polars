is_list_of_string <- function(
  x,
  ...,
  allow_empty = TRUE,
  allow_na = FALSE,
  allow_null = FALSE
) {
  is_list_of_string_impl <- function(
    x,
    ...,
    allow_empty = TRUE,
    allow_na = FALSE,
    allow_null = FALSE
  ) {
    for (i in seq_along(x)) {
      if (
        !.rlang_check_is_string(
          x[[i]],
          allow_empty = allow_empty,
          allow_na = allow_na,
          allow_null = allow_null
        )
      ) {
        return(FALSE)
      }
    }
    TRUE
  }

  is_list(x, n = NULL) &&
    is_list_of_string_impl(
      x,
      allow_empty = allow_empty,
      allow_na = allow_na,
      allow_null = allow_null
    )
}

check_list_of_string <- function(
  x,
  ...,
  allow_empty = TRUE,
  allow_na = FALSE,
  allow_null = FALSE,
  arg = caller_arg(x),
  call = caller_env()
) {
  if (!missing(x)) {
    if (
      is_list_of_string(
        x,
        allow_empty = allow_empty,
        allow_na = allow_na,
        allow_null = allow_null
      )
    ) {
      return(invisible(NULL))
    }
  }

  stop_input_type(
    x,
    "a list of single strings",
    ...,
    allow_na = allow_na,
    allow_null = allow_null,
    arg = arg,
    call = call
  )
}

# TODO: rename and rewrite to allow more types
check_date_or_datetime <- function(
  x,
  ...,
  allow_null = FALSE,
  arg = caller_arg(x),
  call = caller_env()
) {
  if (!missing(x)) {
    if (inherits(x, c("Date", "POSIXct", "polars_expr"))) {
      return(invisible(NULL))
    }
    if (allow_null && is_null(x)) {
      return(invisible(NULL))
    }
    if (is_character(x)) {
      return(invisible(NULL))
    }
  }

  stop_input_type(
    x,
    "a Date, POSIXct, character, or Polars expression",
    ...,
    allow_na = FALSE,
    allow_null = allow_null,
    arg = arg,
    call = call
  )
}


check_arg_is_1byte <- function(arg_name, arg, ..., can_be_empty = FALSE) {
  if (!is_string(arg)) {
    abort(paste0("`", arg_name, "` should be a single byte character."))
  }
  arg_byte_length <- nchar(arg, type = "bytes")
  if (isTRUE(can_be_empty)) {
    if (arg_byte_length > 1) {
      abort(paste0(
        "`",
        arg_name,
        "` = '",
        arg,
        "' should be a single byte character or empty, but is ",
        arg_byte_length,
        " bytes long."
      ))
    }
  } else if (arg_byte_length != 1) {
    abort(paste0(
      "`",
      arg_name,
      "` = '",
      arg,
      "' should be a single byte character, but is ",
      arg_byte_length,
      " bytes long."
    ))
  }
}

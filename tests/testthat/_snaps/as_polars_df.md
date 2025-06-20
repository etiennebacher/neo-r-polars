# as_polars_df works for classes polars_series

    Code
      print(pl_df)
    Output
      shape: (2, 1)
      ┌─────┐
      │ foo │
      │ --- │
      │ i32 │
      ╞═════╡
      │ 1   │
      │ 2   │
      └─────┘

# as_polars_df works for classes polars_series (struct)

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬─────┐
      │ x   ┆ y   │
      │ --- ┆ --- │
      │ i32 ┆ str │
      ╞═════╪═════╡
      │ 1   ┆ a   │
      │ 2   ┆ b   │
      └─────┴─────┘

# as_polars_df works for classes polars_data_frame

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬─────┐
      │ x   ┆ y   │
      │ --- ┆ --- │
      │ i32 ┆ str │
      ╞═════╪═════╡
      │ 1   ┆ a   │
      │ 2   ┆ b   │
      └─────┴─────┘

# as_polars_df works for classes polars_group_by

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬─────┐
      │ x   ┆ y   │
      │ --- ┆ --- │
      │ i32 ┆ str │
      ╞═════╪═════╡
      │ 1   ┆ a   │
      │ 2   ┆ b   │
      └─────┴─────┘

# as_polars_df works for classes polars_lazy_frame

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬─────┐
      │ x   ┆ y   │
      │ --- ┆ --- │
      │ i32 ┆ str │
      ╞═════╪═════╡
      │ 1   ┆ a   │
      │ 2   ┆ b   │
      └─────┴─────┘

# as_polars_df works for classes list

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬───────────┐
      │ x   ┆ y         │
      │ --- ┆ ---       │
      │ i32 ┆ list[str] │
      ╞═════╪═══════════╡
      │ 1   ┆ ["c"]     │
      │ 2   ┆ ["d"]     │
      └─────┴───────────┘

# as_polars_df works for classes list (length 1 and 2)

    Code
      print(pl_df)
    Output
      shape: (2, 2)
      ┌─────┬─────┐
      │ a   ┆ y   │
      │ --- ┆ --- │
      │ f64 ┆ i32 │
      ╞═════╪═════╡
      │ 1.0 ┆ 1   │
      │ 1.0 ┆ 2   │
      └─────┴─────┘

# as_polars_df works for classes list (length 0 and 1)

    Code
      print(pl_df)
    Output
      shape: (0, 2)
      ┌─────┬─────┐
      │ a   ┆ y   │
      │ --- ┆ --- │
      │ f64 ┆ i32 │
      ╞═════╪═════╡
      └─────┴─────┘

# as_polars_df works for classes data.frame

    Code
      print(pl_df)
    Output
      shape: (3, 2)
      ┌─────┬───────────┐
      │ x   ┆ y         │
      │ --- ┆ ---       │
      │ i32 ┆ list[str] │
      ╞═════╪═══════════╡
      │ 1   ┆ ["c"]     │
      │ 2   ┆ ["d"]     │
      │ 3   ┆ ["true"]  │
      └─────┴───────────┘

# as_polars_df works for classes NULL

    Code
      print(pl_df)
    Output
      shape: (0, 0)
      ┌┐
      ╞╡
      └┘

# as_polars_df.default throws an error

    Code
      as_polars_df(1)
    Condition
      Error in `as_polars_df()`:
      ! This object is not supported for the default method of `as_polars_df()`.
      * It requires `x` to be Series with struct type, got: f64.
      i Use `infer_polars_dtype()` to check the data type of the object.

---

    Code
      as_polars_df(0+1i)
    Condition
      Error in `as_polars_df()`:
      ! This object can't be converted to a Polars Series, and hence to a Polars DataFrame.
      * the complex number 0+1i can't be converted to a Polars Series by `as_polars_series()`.
      i The object must be converted to a struct type Series by `as_polars_series()` first.
      Caused by error in `infer_polars_dtype()`:
      ! Can't infer polars dtype of the complex number 0+1i
      Caused by error in `as_polars_series()`:
      ! an empty complex vector can't be converted to a polars Series.

# as_polars_df(<list>) raises an error if the list has different lengths

    Code
      as_polars_df(list(a = 1, b = 1:2, c = 1:3))
    Condition
      Error in `as_polars_df()`:
      ! Evaluation failed.
      Caused by error:
      ! lengths don't match: could not create a new DataFrame: height of column 'b' (2) does not match height of column 'a' (3)


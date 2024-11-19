SEXP savvy_all_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_any_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_max_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_min_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_sum_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_mean_horizontal__ffi(SEXP c_arg__exprs);
SEXP savvy_concat_df__ffi(SEXP c_arg__dfs);
SEXP savvy_concat_series__ffi(SEXP c_arg__series);
SEXP savvy_as_struct__ffi(SEXP c_arg__exprs);
SEXP savvy_datetime__ffi(SEXP c_arg__year, SEXP c_arg__month, SEXP c_arg__day, SEXP c_arg__time_unit, SEXP c_arg__ambiguous, SEXP c_arg__hour, SEXP c_arg__minute, SEXP c_arg__second, SEXP c_arg__microsecond, SEXP c_arg__time_zone);
SEXP savvy_duration__ffi(SEXP c_arg__time_unit, SEXP c_arg__weeks, SEXP c_arg__days, SEXP c_arg__hours, SEXP c_arg__minutes, SEXP c_arg__seconds, SEXP c_arg__milliseconds, SEXP c_arg__microseconds, SEXP c_arg__nanoseconds);
SEXP savvy_field__ffi(SEXP c_arg__names);
SEXP savvy_coalesce__ffi(SEXP c_arg__exprs);
SEXP savvy_col__ffi(SEXP c_arg__name);
SEXP savvy_cols__ffi(SEXP c_arg__names);
SEXP savvy_dtype_cols__ffi(SEXP c_arg__dtypes);
SEXP savvy_index_cols__ffi(SEXP c_arg__indices);
SEXP savvy_first__ffi(void);
SEXP savvy_last__ffi(void);
SEXP savvy_lit_from_bool__ffi(SEXP c_arg__value);
SEXP savvy_lit_from_i32__ffi(SEXP c_arg__value);
SEXP savvy_lit_from_f64__ffi(SEXP c_arg__value);
SEXP savvy_lit_from_str__ffi(SEXP c_arg__value);
SEXP savvy_lit_from_raw__ffi(SEXP c_arg__value);
SEXP savvy_lit_null__ffi(void);
SEXP savvy_lit_from_series__ffi(SEXP c_arg__value);
SEXP savvy_lit_from_series_first__ffi(SEXP c_arg__value);
SEXP savvy_concat_list__ffi(SEXP c_arg__s);
SEXP savvy_concat_df_diagonal__ffi(SEXP c_arg__dfs);
SEXP savvy_concat_df_horizontal__ffi(SEXP c_arg__dfs);
SEXP savvy_concat_lf__ffi(SEXP c_arg__lfs, SEXP c_arg__rechunk, SEXP c_arg__parallel, SEXP c_arg__to_supertypes);
SEXP savvy_concat_lf_horizontal__ffi(SEXP c_arg__lfs, SEXP c_arg__parallel);
SEXP savvy_concat_lf_diagonal__ffi(SEXP c_arg__lfs, SEXP c_arg__rechunk, SEXP c_arg__parallel, SEXP c_arg__to_supertypes);
SEXP savvy_int_range__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__step, SEXP c_arg__dtype);
SEXP savvy_int_ranges__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__step, SEXP c_arg__dtype);
SEXP savvy_date_range__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__interval, SEXP c_arg__closed);
SEXP savvy_date_ranges__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__interval, SEXP c_arg__closed);
SEXP savvy_datetime_range__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__every, SEXP c_arg__closed, SEXP c_arg__time_unit, SEXP c_arg__time_zone);
SEXP savvy_datetime_ranges__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__every, SEXP c_arg__closed, SEXP c_arg__time_unit, SEXP c_arg__time_zone);
SEXP savvy_time_range__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__every, SEXP c_arg__closed);
SEXP savvy_time_ranges__ffi(SEXP c_arg__start, SEXP c_arg__end, SEXP c_arg__every, SEXP c_arg__closed);
SEXP savvy_when__ffi(SEXP c_arg__condition);

// methods and associated functions for PlRChainedThen
SEXP savvy_PlRChainedThen_when__ffi(SEXP self__, SEXP c_arg__condition);
SEXP savvy_PlRChainedThen_otherwise__ffi(SEXP self__, SEXP c_arg__statement);

// methods and associated functions for PlRChainedWhen
SEXP savvy_PlRChainedWhen_then__ffi(SEXP self__, SEXP c_arg__statement);

// methods and associated functions for PlRDataFrame
SEXP savvy_PlRDataFrame_init__ffi(SEXP c_arg__columns);
SEXP savvy_PlRDataFrame_print__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_get_columns__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__length);
SEXP savvy_PlRDataFrame_head__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRDataFrame_tail__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRDataFrame_columns__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_set_column_names__ffi(SEXP self__, SEXP c_arg__names);
SEXP savvy_PlRDataFrame_dtypes__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_shape__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_height__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_width__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_to_series__ffi(SEXP self__, SEXP c_arg__index);
SEXP savvy_PlRDataFrame_equals__ffi(SEXP self__, SEXP c_arg__other, SEXP c_arg__null_equal);
SEXP savvy_PlRDataFrame_clone__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_lazy__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_to_struct__ffi(SEXP self__, SEXP c_arg__name);
SEXP savvy_PlRDataFrame_n_chunks__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_rechunk__ffi(SEXP self__);

// methods and associated functions for PlRDataType
SEXP savvy_PlRDataType_new_from_name__ffi(SEXP c_arg__name);
SEXP savvy_PlRDataType_new_decimal__ffi(SEXP c_arg__scale, SEXP c_arg__precision);
SEXP savvy_PlRDataType_new_datetime__ffi(SEXP c_arg__time_unit, SEXP c_arg__time_zone);
SEXP savvy_PlRDataType_new_duration__ffi(SEXP c_arg__time_unit);
SEXP savvy_PlRDataType_new_categorical__ffi(SEXP c_arg__ordering);
SEXP savvy_PlRDataType_new_enum__ffi(SEXP c_arg__categories);
SEXP savvy_PlRDataType_new_list__ffi(SEXP c_arg__inner);
SEXP savvy_PlRDataType_new_array__ffi(SEXP c_arg__inner, SEXP c_arg__shape);
SEXP savvy_PlRDataType_new_struct__ffi(SEXP c_arg__fields);
SEXP savvy_PlRDataType_print__ffi(SEXP self__);
SEXP savvy_PlRDataType__get_dtype_names__ffi(SEXP self__);
SEXP savvy_PlRDataType__get_datatype_fields__ffi(SEXP self__);
SEXP savvy_PlRDataType_max__ffi(SEXP self__);
SEXP savvy_PlRDataType_min__ffi(SEXP self__);
SEXP savvy_PlRDataType_eq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRDataType_ne__ffi(SEXP self__, SEXP c_arg__other);

// methods and associated functions for PlRExpr
SEXP savvy_PlRExpr_arr_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_sum__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_std__ffi(SEXP self__, SEXP c_arg__ddof);
SEXP savvy_PlRExpr_arr_var__ffi(SEXP self__, SEXP c_arg__ddof);
SEXP savvy_PlRExpr_arr_median__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_unique__ffi(SEXP self__, SEXP c_arg__maintain_order);
SEXP savvy_PlRExpr_arr_to_list__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_all__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_any__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_sort__ffi(SEXP self__, SEXP c_arg__descending, SEXP c_arg__nulls_last);
SEXP savvy_PlRExpr_arr_reverse__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_arg_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_arg_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_arr_get__ffi(SEXP self__, SEXP c_arg__index, SEXP c_arg__null_on_oob);
SEXP savvy_PlRExpr_arr_join__ffi(SEXP self__, SEXP c_arg__separator, SEXP c_arg__ignore_nulls);
SEXP savvy_PlRExpr_arr_contains__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_arr_count_matches__ffi(SEXP self__, SEXP c_arg__expr);
SEXP savvy_PlRExpr_arr_shift__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRExpr_arr_n_unique__ffi(SEXP self__);
SEXP savvy_PlRExpr_bin_contains__ffi(SEXP self__, SEXP c_arg__literal);
SEXP savvy_PlRExpr_bin_ends_with__ffi(SEXP self__, SEXP c_arg__suffix);
SEXP savvy_PlRExpr_bin_starts_with__ffi(SEXP self__, SEXP c_arg__prefix);
SEXP savvy_PlRExpr_bin_hex_decode__ffi(SEXP self__, SEXP c_arg__strict);
SEXP savvy_PlRExpr_bin_base64_decode__ffi(SEXP self__, SEXP c_arg__strict);
SEXP savvy_PlRExpr_bin_hex_encode__ffi(SEXP self__);
SEXP savvy_PlRExpr_bin_base64_encode__ffi(SEXP self__);
SEXP savvy_PlRExpr_bin_size_bytes__ffi(SEXP self__);
SEXP savvy_PlRExpr_cat_get_categories__ffi(SEXP self__);
SEXP savvy_PlRExpr_cat_set_ordering__ffi(SEXP self__, SEXP c_arg__ordering);
SEXP savvy_PlRExpr_dt_convert_time_zone__ffi(SEXP self__, SEXP c_arg__time_zone);
SEXP savvy_PlRExpr_dt_replace_time_zone__ffi(SEXP self__, SEXP c_arg__ambiguous, SEXP c_arg__non_existent, SEXP c_arg__time_zone);
SEXP savvy_PlRExpr_dt_truncate__ffi(SEXP self__, SEXP c_arg__every);
SEXP savvy_PlRExpr_dt_round__ffi(SEXP self__, SEXP c_arg__every);
SEXP savvy_PlRExpr_dt_time__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_date__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_combine__ffi(SEXP self__, SEXP c_arg__time, SEXP c_arg__time_unit);
SEXP savvy_PlRExpr_dt_to_string__ffi(SEXP self__, SEXP c_arg__format);
SEXP savvy_PlRExpr_dt_year__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_iso_year__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_quarter__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_month__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_week__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_weekday__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_day__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_ordinal_day__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_hour__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_minute__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_second__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_millisecond__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_microsecond__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_nanosecond__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_timestamp__ffi(SEXP self__, SEXP c_arg__time_unit);
SEXP savvy_PlRExpr_dt_epoch_seconds__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_with_time_unit__ffi(SEXP self__, SEXP c_arg__time_unit);
SEXP savvy_PlRExpr_dt_cast_time_unit__ffi(SEXP self__, SEXP c_arg__time_unit);
SEXP savvy_PlRExpr_dt_total_days__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_hours__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_minutes__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_seconds__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_milliseconds__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_microseconds__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_total_nanoseconds__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_offset_by__ffi(SEXP self__, SEXP c_arg__by);
SEXP savvy_PlRExpr_dt_is_leap_year__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_dst_offset__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_base_utc_offset__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_month_start__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_month_end__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_century__ffi(SEXP self__);
SEXP savvy_PlRExpr_dt_add_business_days__ffi(SEXP self__, SEXP c_arg__n, SEXP c_arg__week_mask, SEXP c_arg__holidays, SEXP c_arg__roll);
SEXP savvy_PlRExpr_print__ffi(SEXP self__);
SEXP savvy_PlRExpr_add__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_sub__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_mul__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_div__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_rem__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_floor_div__ffi(SEXP self__, SEXP c_arg__rhs);
SEXP savvy_PlRExpr_neg__ffi(SEXP self__);
SEXP savvy_PlRExpr_eq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_eq_missing__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_neq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_neq_missing__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_gt__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_gt_eq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_lt_eq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_lt__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_alias__ffi(SEXP self__, SEXP c_arg__name);
SEXP savvy_PlRExpr_not__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_null__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_not_null__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_infinite__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_finite__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_nan__ffi(SEXP self__);
SEXP savvy_PlRExpr_is_not_nan__ffi(SEXP self__);
SEXP savvy_PlRExpr_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_nan_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_nan_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_mean__ffi(SEXP self__);
SEXP savvy_PlRExpr_median__ffi(SEXP self__);
SEXP savvy_PlRExpr_sum__ffi(SEXP self__);
SEXP savvy_PlRExpr_cast__ffi(SEXP self__, SEXP c_arg__dtype, SEXP c_arg__strict, SEXP c_arg__wrap_numerical);
SEXP savvy_PlRExpr_sort_with__ffi(SEXP self__, SEXP c_arg__descending, SEXP c_arg__nulls_last);
SEXP savvy_PlRExpr_arg_sort__ffi(SEXP self__, SEXP c_arg__descending, SEXP c_arg__nulls_last);
SEXP savvy_PlRExpr_sort_by__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__descending, SEXP c_arg__nulls_last, SEXP c_arg__multithreaded, SEXP c_arg__maintain_order);
SEXP savvy_PlRExpr_first__ffi(SEXP self__);
SEXP savvy_PlRExpr_last__ffi(SEXP self__);
SEXP savvy_PlRExpr_filter__ffi(SEXP self__, SEXP c_arg__predicate);
SEXP savvy_PlRExpr_reverse__ffi(SEXP self__);
SEXP savvy_PlRExpr_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__length);
SEXP savvy_PlRExpr_over__ffi(SEXP self__, SEXP c_arg__partition_by, SEXP c_arg__order_by_descending, SEXP c_arg__order_by_nulls_last, SEXP c_arg__mapping_strategy, SEXP c_arg__order_by);
SEXP savvy_PlRExpr_and__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_or__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_xor__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_pow__ffi(SEXP self__, SEXP c_arg__exponent);
SEXP savvy_PlRExpr_diff__ffi(SEXP self__, SEXP c_arg__n, SEXP c_arg__null_behavior);
SEXP savvy_PlRExpr_reshape__ffi(SEXP self__, SEXP c_arg__dimensions);
SEXP savvy_PlRExpr_any__ffi(SEXP self__, SEXP c_arg__ignore_nulls);
SEXP savvy_PlRExpr_all__ffi(SEXP self__, SEXP c_arg__ignore_nulls);
SEXP savvy_PlRExpr_map_batches__ffi(SEXP self__, SEXP c_arg__lambda, SEXP c_arg__agg_list, SEXP c_arg__output_type);
SEXP savvy_PlRExpr_explode__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_len__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_contains__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_list_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_sum__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_mean__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_sort__ffi(SEXP self__, SEXP c_arg__descending, SEXP c_arg__nulls_last);
SEXP savvy_PlRExpr_list_reverse__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_unique__ffi(SEXP self__, SEXP c_arg__maintain_order);
SEXP savvy_PlRExpr_list_n_unique__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_gather__ffi(SEXP self__, SEXP c_arg__index, SEXP c_arg__null_on_oob);
SEXP savvy_PlRExpr_list_gather_every__ffi(SEXP self__, SEXP c_arg__n, SEXP c_arg__offset);
SEXP savvy_PlRExpr_list_get__ffi(SEXP self__, SEXP c_arg__index, SEXP c_arg__null_on_oob);
SEXP savvy_PlRExpr_list_join__ffi(SEXP self__, SEXP c_arg__separator, SEXP c_arg__ignore_nulls);
SEXP savvy_PlRExpr_list_arg_min__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_arg_max__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_diff__ffi(SEXP self__, SEXP c_arg__n, SEXP c_arg__null_behavior);
SEXP savvy_PlRExpr_list_shift__ffi(SEXP self__, SEXP c_arg__periods);
SEXP savvy_PlRExpr_list_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__length);
SEXP savvy_PlRExpr_list_eval__ffi(SEXP self__, SEXP c_arg__expr, SEXP c_arg__parallel);
SEXP savvy_PlRExpr_list_all__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_any__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_set_operation__ffi(SEXP self__, SEXP c_arg__other, SEXP c_arg__operation);
SEXP savvy_PlRExpr_list_sample_n__ffi(SEXP self__, SEXP c_arg__n, SEXP c_arg__with_replacement, SEXP c_arg__shuffle, SEXP c_arg__seed);
SEXP savvy_PlRExpr_list_sample_frac__ffi(SEXP self__, SEXP c_arg__frac, SEXP c_arg__with_replacement, SEXP c_arg__shuffle, SEXP c_arg__seed);
SEXP savvy_PlRExpr_list_median__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_std__ffi(SEXP self__, SEXP c_arg__ddof);
SEXP savvy_PlRExpr_list_var__ffi(SEXP self__, SEXP c_arg__ddof);
SEXP savvy_PlRExpr_list_to_array__ffi(SEXP self__, SEXP c_arg__width);
SEXP savvy_PlRExpr_list_drop_nulls__ffi(SEXP self__);
SEXP savvy_PlRExpr_list_count_matches__ffi(SEXP self__, SEXP c_arg__expr);
SEXP savvy_PlRExpr_meta_eq__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr_meta_pop__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_root_names__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_output_name__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_undo_aliases__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_has_multiple_outputs__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_is_regex_projection__ffi(SEXP self__);
SEXP savvy_PlRExpr_meta_is_column_selection__ffi(SEXP self__, SEXP c_arg__allow_aliasing);
SEXP savvy_PlRExpr__meta_selector_add__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr__meta_selector_and__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr__meta_selector_sub__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRExpr__meta_as_selector__ffi(SEXP self__);
SEXP savvy_PlRExpr_compute_tree_format__ffi(SEXP self__, SEXP c_arg__display_as_dot);
SEXP savvy_PlRExpr_meta_is_column__ffi(SEXP self__);
SEXP savvy_PlRExpr_name_keep__ffi(SEXP self__);
SEXP savvy_PlRExpr_name_prefix__ffi(SEXP self__, SEXP c_arg__prefix);
SEXP savvy_PlRExpr_name_suffix__ffi(SEXP self__, SEXP c_arg__suffix);
SEXP savvy_PlRExpr_name_to_lowercase__ffi(SEXP self__);
SEXP savvy_PlRExpr_name_to_uppercase__ffi(SEXP self__);
SEXP savvy_PlRExpr_name_prefix_fields__ffi(SEXP self__, SEXP c_arg__prefix);
SEXP savvy_PlRExpr_name_suffix_fields__ffi(SEXP self__, SEXP c_arg__suffix);
SEXP savvy_PlRExpr_serialize_binary__ffi(SEXP self__);
SEXP savvy_PlRExpr_serialize_json__ffi(SEXP self__);
SEXP savvy_PlRExpr_deserialize_binary__ffi(SEXP c_arg__data);
SEXP savvy_PlRExpr_deserialize_json__ffi(SEXP c_arg__data);
SEXP savvy_PlRExpr_str_len_bytes__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_len_chars__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_join__ffi(SEXP self__, SEXP c_arg__delimiter, SEXP c_arg__ignore_nulls);
SEXP savvy_PlRExpr_str_to_uppercase__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_to_lowercase__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_strip_chars__ffi(SEXP self__, SEXP c_arg__matches);
SEXP savvy_PlRExpr_str_strip_chars_end__ffi(SEXP self__, SEXP c_arg__matches);
SEXP savvy_PlRExpr_str_strip_chars_start__ffi(SEXP self__, SEXP c_arg__matches);
SEXP savvy_PlRExpr_str_zfill__ffi(SEXP self__, SEXP c_arg__alignment);
SEXP savvy_PlRExpr_str_pad_end__ffi(SEXP self__, SEXP c_arg__width, SEXP c_arg__fillchar);
SEXP savvy_PlRExpr_str_pad_start__ffi(SEXP self__, SEXP c_arg__width, SEXP c_arg__fillchar);
SEXP savvy_PlRExpr_str_contains__ffi(SEXP self__, SEXP c_arg__pat, SEXP c_arg__literal, SEXP c_arg__strict);
SEXP savvy_PlRExpr_str_ends_with__ffi(SEXP self__, SEXP c_arg__sub);
SEXP savvy_PlRExpr_str_starts_with__ffi(SEXP self__, SEXP c_arg__sub);
SEXP savvy_PlRExpr_str_json_path_match__ffi(SEXP self__, SEXP c_arg__pat);
SEXP savvy_PlRExpr_str_hex_encode__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_hex_decode__ffi(SEXP self__, SEXP c_arg__strict);
SEXP savvy_PlRExpr_str_base64_encode__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_base64_decode__ffi(SEXP self__, SEXP c_arg__strict);
SEXP savvy_PlRExpr_str_extract__ffi(SEXP self__, SEXP c_arg__pattern, SEXP c_arg__group_index);
SEXP savvy_PlRExpr_str_extract_all__ffi(SEXP self__, SEXP c_arg__pattern);
SEXP savvy_PlRExpr_str_extract_groups__ffi(SEXP self__, SEXP c_arg__pattern);
SEXP savvy_PlRExpr_str_count_matches__ffi(SEXP self__, SEXP c_arg__pat, SEXP c_arg__literal);
SEXP savvy_PlRExpr_str_to_date__ffi(SEXP self__, SEXP c_arg__strict, SEXP c_arg__exact, SEXP c_arg__cache, SEXP c_arg__format);
SEXP savvy_PlRExpr_str_to_datetime__ffi(SEXP self__, SEXP c_arg__strict, SEXP c_arg__exact, SEXP c_arg__cache, SEXP c_arg__ambiguous, SEXP c_arg__format, SEXP c_arg__time_unit, SEXP c_arg__time_zone);
SEXP savvy_PlRExpr_str_to_time__ffi(SEXP self__, SEXP c_arg__strict, SEXP c_arg__cache, SEXP c_arg__format);
SEXP savvy_PlRExpr_str_split__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__inclusive);
SEXP savvy_PlRExpr_str_split_exact__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__n, SEXP c_arg__inclusive);
SEXP savvy_PlRExpr_str_splitn__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__n);
SEXP savvy_PlRExpr_str_replace__ffi(SEXP self__, SEXP c_arg__pat, SEXP c_arg__value, SEXP c_arg__literal, SEXP c_arg__n);
SEXP savvy_PlRExpr_str_replace_all__ffi(SEXP self__, SEXP c_arg__pat, SEXP c_arg__value, SEXP c_arg__literal);
SEXP savvy_PlRExpr_str_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__length);
SEXP savvy_PlRExpr_str_to_integer__ffi(SEXP self__, SEXP c_arg__base, SEXP c_arg__strict);
SEXP savvy_PlRExpr_str_reverse__ffi(SEXP self__);
SEXP savvy_PlRExpr_str_contains_any__ffi(SEXP self__, SEXP c_arg__patterns, SEXP c_arg__ascii_case_insensitive);
SEXP savvy_PlRExpr_str_replace_many__ffi(SEXP self__, SEXP c_arg__patterns, SEXP c_arg__replace_with, SEXP c_arg__ascii_case_insensitive);
SEXP savvy_PlRExpr_str_extract_many__ffi(SEXP self__, SEXP c_arg__patterns, SEXP c_arg__ascii_case_insensitive, SEXP c_arg__overlapping);
SEXP savvy_PlRExpr_str_find__ffi(SEXP self__, SEXP c_arg__pat, SEXP c_arg__literal, SEXP c_arg__strict);
SEXP savvy_PlRExpr_str_head__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRExpr_str_tail__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRExpr_struct_field_by_index__ffi(SEXP self__, SEXP c_arg__index);
SEXP savvy_PlRExpr_struct_multiple_fields__ffi(SEXP self__, SEXP c_arg__names);
SEXP savvy_PlRExpr_struct_rename_fields__ffi(SEXP self__, SEXP c_arg__names);
SEXP savvy_PlRExpr_struct_json_encode__ffi(SEXP self__);
SEXP savvy_PlRExpr_struct_with_fields__ffi(SEXP self__, SEXP c_arg__fields);

// methods and associated functions for PlRLazyFrame
SEXP savvy_PlRLazyFrame_describe_plan__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_describe_optimized_plan__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_describe_plan_tree__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_describe_optimized_plan_tree__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_optimization_toggle__ffi(SEXP self__, SEXP c_arg__type_coercion, SEXP c_arg__predicate_pushdown, SEXP c_arg__projection_pushdown, SEXP c_arg__simplify_expression, SEXP c_arg__slice_pushdown, SEXP c_arg__comm_subplan_elim, SEXP c_arg__comm_subexpr_elim, SEXP c_arg__cluster_with_columns, SEXP c_arg__streaming, SEXP c_arg___eager);
SEXP savvy_PlRLazyFrame_filter__ffi(SEXP self__, SEXP c_arg__predicate);
SEXP savvy_PlRLazyFrame_select__ffi(SEXP self__, SEXP c_arg__exprs);
SEXP savvy_PlRLazyFrame_group_by__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__maintain_order);
SEXP savvy_PlRLazyFrame_collect__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__len);
SEXP savvy_PlRLazyFrame_tail__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRLazyFrame_drop__ffi(SEXP self__, SEXP c_arg__columns, SEXP c_arg__strict);
SEXP savvy_PlRLazyFrame_cast__ffi(SEXP self__, SEXP c_arg__dtypes, SEXP c_arg__strict);
SEXP savvy_PlRLazyFrame_cast_all__ffi(SEXP self__, SEXP c_arg__dtype, SEXP c_arg__strict);
SEXP savvy_PlRLazyFrame_collect_schema__ffi(SEXP self__);
SEXP savvy_PlRLazyFrame_sort_by_exprs__ffi(SEXP self__, SEXP c_arg__by, SEXP c_arg__descending, SEXP c_arg__nulls_last, SEXP c_arg__maintain_order, SEXP c_arg__multithreaded);
SEXP savvy_PlRLazyFrame_with_columns__ffi(SEXP self__, SEXP c_arg__exprs);
SEXP savvy_PlRLazyFrame_new_from_ipc__ffi(SEXP c_arg__source, SEXP c_arg__cache, SEXP c_arg__rechunk, SEXP c_arg__try_parse_hive_dates, SEXP c_arg__retries, SEXP c_arg__row_index_offset, SEXP c_arg__n_rows, SEXP c_arg__row_index_name, SEXP c_arg__storage_options, SEXP c_arg__hive_partitioning, SEXP c_arg__hive_schema, SEXP c_arg__file_cache_ttl, SEXP c_arg__include_file_paths);

// methods and associated functions for PlRLazyGroupBy
SEXP savvy_PlRLazyGroupBy_agg__ffi(SEXP self__, SEXP c_arg__aggs);
SEXP savvy_PlRLazyGroupBy_head__ffi(SEXP self__, SEXP c_arg__n);
SEXP savvy_PlRLazyGroupBy_tail__ffi(SEXP self__, SEXP c_arg__n);

// methods and associated functions for PlRSeries
SEXP savvy_PlRSeries_add__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRSeries_sub__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRSeries_div__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRSeries_mul__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRSeries_rem__ffi(SEXP self__, SEXP c_arg__other);
SEXP savvy_PlRSeries_new_null__ffi(SEXP c_arg__name, SEXP c_arg__length);
SEXP savvy_PlRSeries_new_f64__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_i32__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_i64__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_bool__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_str__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_single_binary__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_binary__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_series_list__ffi(SEXP c_arg__name, SEXP c_arg__values, SEXP c_arg__strict);
SEXP savvy_PlRSeries_new_i32_from_date__ffi(SEXP c_arg__name, SEXP c_arg__values);
SEXP savvy_PlRSeries_new_i64_from_numeric_and_multiplier__ffi(SEXP c_arg__name, SEXP c_arg__values, SEXP c_arg__multiplier, SEXP c_arg__rounding);
SEXP savvy_PlRSeries_new_i64_from_clock_pair__ffi(SEXP c_arg__name, SEXP c_arg__left, SEXP c_arg__right, SEXP c_arg__precision);
SEXP savvy_PlRSeries_to_r_vector__ffi(SEXP self__, SEXP c_arg__ensure_vector, SEXP c_arg__int64, SEXP c_arg__date, SEXP c_arg__time, SEXP c_arg__struct, SEXP c_arg__decimal, SEXP c_arg__as_clock_class, SEXP c_arg__ambiguous, SEXP c_arg__non_existent, SEXP c_arg__local_time_zone);
SEXP savvy_PlRSeries_print__ffi(SEXP self__);
SEXP savvy_PlRSeries_struct_unnest__ffi(SEXP self__);
SEXP savvy_PlRSeries_struct_fields__ffi(SEXP self__);
SEXP savvy_PlRSeries_cat_uses_lexical_ordering__ffi(SEXP self__);
SEXP savvy_PlRSeries_cat_is_local__ffi(SEXP self__);
SEXP savvy_PlRSeries_cat_to_local__ffi(SEXP self__);
SEXP savvy_PlRSeries_reshape__ffi(SEXP self__, SEXP c_arg__dimensions);
SEXP savvy_PlRSeries_clone__ffi(SEXP self__);
SEXP savvy_PlRSeries_name__ffi(SEXP self__);
SEXP savvy_PlRSeries_rename__ffi(SEXP self__, SEXP c_arg__name);
SEXP savvy_PlRSeries_dtype__ffi(SEXP self__);
SEXP savvy_PlRSeries_equals__ffi(SEXP self__, SEXP c_arg__other, SEXP c_arg__check_dtypes, SEXP c_arg__check_names, SEXP c_arg__null_equal);
SEXP savvy_PlRSeries_len__ffi(SEXP self__);
SEXP savvy_PlRSeries_cast__ffi(SEXP self__, SEXP c_arg__dtype, SEXP c_arg__strict);
SEXP savvy_PlRSeries_slice__ffi(SEXP self__, SEXP c_arg__offset, SEXP c_arg__length);
SEXP savvy_PlRSeries_n_chunks__ffi(SEXP self__);

// methods and associated functions for PlRThen
SEXP savvy_PlRThen_when__ffi(SEXP self__, SEXP c_arg__condition);
SEXP savvy_PlRThen_otherwise__ffi(SEXP self__, SEXP c_arg__statement);

// methods and associated functions for PlRWhen
SEXP savvy_PlRWhen_then__ffi(SEXP self__, SEXP c_arg__statement);
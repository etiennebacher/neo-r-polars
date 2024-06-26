SEXP savvy_col__ffi(SEXP name);
SEXP savvy_cols__ffi(SEXP names);
SEXP savvy_lit_from_bool__ffi(SEXP value);
SEXP savvy_lit_from_i32__ffi(SEXP value);
SEXP savvy_lit_from_f64__ffi(SEXP value);
SEXP savvy_lit_from_str__ffi(SEXP value);
SEXP savvy_lit_null__ffi(void);
SEXP savvy_lit_from_series__ffi(SEXP value);

// methods and associated functions for PlRDataFrame
SEXP savvy_PlRDataFrame_init__ffi(SEXP columns);
SEXP savvy_PlRDataFrame_print__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_get_columns__ffi(SEXP self__);
SEXP savvy_PlRDataFrame_to_struct__ffi(SEXP self__, SEXP name);
SEXP savvy_PlRDataFrame_lazy__ffi(SEXP self__);

// methods and associated functions for PlRDataType
SEXP savvy_PlRDataType_print__ffi(SEXP self__);
SEXP savvy_PlRDataType_new_from_name__ffi(SEXP name);
SEXP savvy_PlRDataType_new_categorical__ffi(SEXP ordering);
SEXP savvy_PlRDataType_new_datetime__ffi(SEXP time_unit, SEXP time_zone);
SEXP savvy_PlRDataType_new_duration__ffi(SEXP time_unit);
SEXP savvy_PlRDataType_is_temporal__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_enum__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_categorical__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_string__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_logical__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_float__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_numeric__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_integer__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_signed_integer__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_unsigned_integer__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_null__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_binary__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_primitive__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_bool__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_array__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_list__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_nested__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_struct__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_ord__ffi(SEXP self__);
SEXP savvy_PlRDataType_is_known__ffi(SEXP self__);

// methods and associated functions for PlRExpr
SEXP savvy_PlRExpr_print__ffi(SEXP self__);
SEXP savvy_PlRExpr_add__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_sub__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_mul__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_div__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_rem__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_floor_div__ffi(SEXP self__, SEXP rhs);
SEXP savvy_PlRExpr_neg__ffi(SEXP self__);
SEXP savvy_PlRExpr_cast__ffi(SEXP self__, SEXP data_type, SEXP strict);

// methods and associated functions for PlRLazyFrame
SEXP savvy_PlRLazyFrame_select__ffi(SEXP self__, SEXP exprs);
SEXP savvy_PlRLazyFrame_group_by__ffi(SEXP self__, SEXP by, SEXP maintain_order);
SEXP savvy_PlRLazyFrame_collect__ffi(SEXP self__);

// methods and associated functions for PlRLazyGroupBy
SEXP savvy_PlRLazyGroupBy_agg__ffi(SEXP self__, SEXP aggs);
SEXP savvy_PlRLazyGroupBy_head__ffi(SEXP self__, SEXP n);
SEXP savvy_PlRLazyGroupBy_tail__ffi(SEXP self__, SEXP n);

// methods and associated functions for PlRSeries
SEXP savvy_PlRSeries_print__ffi(SEXP self__);
SEXP savvy_PlRSeries_struct_unnest__ffi(SEXP self__);
SEXP savvy_PlRSeries_clone__ffi(SEXP self__);
SEXP savvy_PlRSeries_name__ffi(SEXP self__);
SEXP savvy_PlRSeries_rename__ffi(SEXP self__, SEXP name);
SEXP savvy_PlRSeries_dtype__ffi(SEXP self__);
SEXP savvy_PlRSeries_cast__ffi(SEXP self__, SEXP dtype, SEXP strict);
SEXP savvy_PlRSeries_add__ffi(SEXP self__, SEXP other);
SEXP savvy_PlRSeries_sub__ffi(SEXP self__, SEXP other);
SEXP savvy_PlRSeries_div__ffi(SEXP self__, SEXP other);
SEXP savvy_PlRSeries_mul__ffi(SEXP self__, SEXP other);
SEXP savvy_PlRSeries_rem__ffi(SEXP self__, SEXP other);
SEXP savvy_PlRSeries_new_empty__ffi(SEXP name, SEXP dtype);
SEXP savvy_PlRSeries_new_f64__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_new_i32__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_new_bool__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_new_str__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_new_categorical__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_new_series_list__ffi(SEXP name, SEXP values);
SEXP savvy_PlRSeries_to_r_vector__ffi(SEXP self__);
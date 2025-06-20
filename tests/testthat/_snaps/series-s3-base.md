# .DollarNames(<series>)

    Code
      .DollarNames(as_polars_series(NULL))
    Output
        [1] "arr"                    "bin"                    "cat"                   
        [4] "dt"                     "dtype"                  "flags"                 
        [7] "list"                   "name"                   "shape"                 
       [10] "str"                    "struct"                 "to_frame"              
       [13] "add"                    "alias"                  "cast"                  
       [16] "len"                    "n_chunks"               "rename"                
       [19] "gt"                     "eq"                     "clone"                 
       [22] "chunk_lengths"          "sub"                    "true_div"              
       [25] "serialize"              "to_r_vector"            "reshape"               
       [28] "gt_eq"                  "lt"                     "rechunk"               
       [31] "eq_missing"             "neq_missing"            "slice"                 
       [34] "mul"                    "mod"                    "equals"                
       [37] "lt_eq"                  "neq"                    "std"                   
       [40] "last"                   "value_counts"           "bitwise_count_zeros"   
       [43] "rolling_mean"           "unique"                 "forward_fill"          
       [46] "explode"                "replace"                "rolling_std_by"        
       [49] "floor_div"              "cum_count"              "rolling_min"           
       [52] "round_sig_figs"         "upper_bound"            "peak_max"              
       [55] "rolling_quantile_by"    "shrink_dtype"           "rank"                  
       [58] "shift"                  "kurtosis"               "rolling_max_by"        
       [61] "mode"                   "truediv"                "sum"                   
       [64] "floordiv"               "product"                "cos"                   
       [67] "rolling_mean_by"        "cot"                    "bitwise_leading_zeros" 
       [70] "count"                  "hash"                   "bottom_k"              
       [73] "ewm_std"                "cum_prod"               "rolling_sum"           
       [76] "exp"                    "arg_max"                "cosh"                  
       [79] "is_null"                "sinh"                   "n_unique"              
       [82] "rolling_std"            "bitwise_trailing_ones"  "sort"                  
       [85] "is_not_nan"             "is_finite"              "is_between"            
       [88] "unique_counts"          "shuffle"                "drop_nans"             
       [91] "log1p"                  "replace_strict"         "le"                    
       [94] "search_sorted"          "ceil"                   "rolling_median"        
       [97] "gather_every"           "has_nulls"              "log"                   
      [100] "cum_min"                "flatten"                "approx_n_unique"       
      [103] "first"                  "min"                    "drop_nulls"            
      [106] "top_k_by"               "sqrt"                   "is_duplicated"         
      [109] "extend_constant"        "is_nan"                 "backward_fill"         
      [112] "entropy"                "map_batches"            "arg_true"              
      [115] "ewm_mean_by"            "reinterpret"            "tail"                  
      [118] "clip"                   "median"                 "set_sorted"            
      [121] "cbrt"                   "get"                    "bitwise_and"           
      [124] "ewm_mean"               "xor"                    "ewm_var"               
      [127] "ne"                     "append"                 "arctan"                
      [130] "implode"                "floor"                  "rolling_skew"          
      [133] "arctanh"                "nan_max"                "neg"                   
      [136] "rolling_median_by"      "sign"                   "quantile"              
      [139] "qcut"                   "null_count"             "peak_min"              
      [142] "top_k"                  "skew"                   "rle"                   
      [145] "rolling_quantile"       "bitwise_xor"            "arccosh"               
      [148] "all"                    "rolling_var_by"         "rle_id"                
      [151] "bitwise_trailing_zeros" "not"                    "bottom_k_by"           
      [154] "abs"                    "max"                    "fill_nan"              
      [157] "to_physical"            "is_infinite"            "head"                  
      [160] "or"                     "interpolate_by"         "invert"                
      [163] "degrees"                "is_in"                  "dot"                   
      [166] "cut"                    "arg_min"                "arcsin"                
      [169] "tan"                    "is_first_distinct"      "sort_by"               
      [172] "fill_null"              "and"                    "sample"                
      [175] "bitwise_or"             "gather"                 "interpolate"           
      [178] "limit"                  "rolling_min_by"         "diff"                  
      [181] "radians"                "pow"                    "arcsinh"               
      [184] "cumulative_eval"        "cum_max"                "ge"                    
      [187] "bitwise_count_ones"     "is_last_distinct"       "ne_missing"            
      [190] "lower_bound"            "round"                  "is_unique"             
      [193] "reverse"                "arg_unique"             "nan_min"               
      [196] "filter"                 "any"                    "cum_sum"               
      [199] "rolling_max"            "log10"                  "is_not_null"           
      [202] "arccos"                 "rolling_sum_by"         "tanh"                  
      [205] "hist"                   "var"                    "sin"                   
      [208] "pct_change"             "bitwise_leading_ones"   "rolling_var"           
      [211] "arg_sort"               "repeat_by"              "mean"                  

# as.vector() suggests $to_r_vector() for datatypes that need attributes

    Code
      as.vector(pl$Series("a", as.Date("2020-01-01")))
    Message
      i `as.vector()` on a Polars Series of type date may drop some useful attributes.
      i Use `$to_r_vector()` instead for finer control of the conversion from Polars to R.
    Output
      [1] 18262

---

    Code
      as.vector(pl$Series("a", as.POSIXct("2020-01-01", tz = "UTC")))
    Message
      i `as.vector()` on a Polars Series of type datetime[ms, UTC] may drop some useful attributes.
      i Use `$to_r_vector()` instead for finer control of the conversion from Polars to R.
    Output
      [1] 1577836800

---

    Code
      as.vector(s_struct)
    Message
      i `as.vector()` on a Polars Series of type struct[1] may drop some useful attributes.
      i Use `$to_r_vector()` instead for finer control of the conversion from Polars to R.
    Output
      $x
      [1] "2020-01-01"
      

---

    Code
      as.vector(pl$Series("a", 1:2)$cast(pl$Int64))
    Message
      `int64` is overridden by the option "polars.to_r_vector.int64" with the string "integer64"
      i `as.vector()` on a Polars Series of type i64 may drop some useful attributes.
      i Use `$to_r_vector()` instead for finer control of the conversion from Polars to R.
    Output
      [1] 4.940656e-324 9.881313e-324

---

    Code
      as.vector(pl$Series("a", hms::hms(1, 2, 3)))
    Message
      i `as.vector()` on a Polars Series of type time may drop some useful attributes.
      i Use `$to_r_vector()` instead for finer control of the conversion from Polars to R.
    Output
      [1] 10921


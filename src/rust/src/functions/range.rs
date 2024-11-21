use crate::{datatypes::PlRDataType, prelude::*, PlRExpr, RPolarsErr};
use polars::lazy::dsl;
use savvy::{savvy, NumericScalar, Result};

#[savvy]
pub fn int_range(
    start: &PlRExpr,
    end: &PlRExpr,
    step: NumericScalar,
    dtype: &PlRDataType,
) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let dtype = dtype.dt.clone();
    let step = <Wrap<i64>>::try_from(step)?.0;
    Ok(dsl::int_range(start, end, step, dtype).into())
}

#[savvy]
pub fn int_ranges(
    start: &PlRExpr,
    end: &PlRExpr,
    step: &PlRExpr,
    dtype: &PlRDataType,
) -> Result<PlRExpr> {
    let dtype = dtype.dt.clone();
    if !dtype.is_integer() {
        return Err(RPolarsErr::from(
            polars_err!(ComputeError: "non-integer `dtype` passed to `int_ranges`: {:?}", dtype),
        )
        .into());
    }

    let mut result = dsl::int_ranges(start.inner.clone(), end.inner.clone(), step.inner.clone());

    if dtype != DataType::Int64 {
        result = result.cast(DataType::List(Box::new(dtype)))
    }

    Ok(result.into())
}

#[savvy]
pub fn date_range(start: &PlRExpr, end: &PlRExpr, interval: &str, closed: &str) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let interval = Duration::parse(interval);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    Ok(dsl::date_range(start, end, interval, closed).into())
}

#[savvy]
pub fn date_ranges(
    start: &PlRExpr,
    end: &PlRExpr,
    interval: &str,
    closed: &str,
) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let interval = Duration::parse(interval);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    Ok(dsl::date_ranges(start, end, interval, closed).into())
}

#[savvy]
pub fn datetime_range(
    start: &PlRExpr,
    end: &PlRExpr,
    every: &str,
    closed: &str,
    time_unit: Option<&str>,
    time_zone: Option<&str>,
) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let every = Duration::parse(every);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    let time_unit: Option<TimeUnit> = match time_unit {
        Some(x) => Some(<Wrap<TimeUnit>>::try_from(x)?.0),
        None => None,
    };
    let time_zone: Option<PlSmallStr> = time_zone.map(|x| x.into());
    Ok(dsl::datetime_range(start, end, every, closed, time_unit, time_zone).into())
}

#[savvy]
pub fn datetime_ranges(
    start: &PlRExpr,
    end: &PlRExpr,
    every: &str,
    closed: &str,
    time_unit: Option<&str>,
    time_zone: Option<&str>,
) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let every = Duration::parse(every);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    let time_unit: Option<TimeUnit> = match time_unit {
        Some(x) => Some(<Wrap<TimeUnit>>::try_from(x)?.0),
        None => None,
    };
    let time_zone: Option<PlSmallStr> = time_zone.map(|x| x.into());
    Ok(dsl::datetime_ranges(start, end, every, closed, time_unit, time_zone).into())
}

#[savvy]
pub fn time_range(start: &PlRExpr, end: &PlRExpr, every: &str, closed: &str) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let every = Duration::parse(every);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    Ok(dsl::time_range(start, end, every, closed).into())
}

#[savvy]
pub fn time_ranges(start: &PlRExpr, end: &PlRExpr, every: &str, closed: &str) -> Result<PlRExpr> {
    let start = start.inner.clone();
    let end = end.inner.clone();
    let every = Duration::parse(every);
    let closed = <Wrap<ClosedWindow>>::try_from(closed)?.0;
    Ok(dsl::time_ranges(start, end, every, closed).into())
}

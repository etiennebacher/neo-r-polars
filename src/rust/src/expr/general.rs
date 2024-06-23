use crate::datatypes::PlRDataType;
use crate::PlRExpr;
use polars::lazy::dsl;
use polars::prelude::*;
use polars::series::ops::NullBehavior;
use polars_core::series::IsSorted;
use polars_core::utils::arrow::compute::cast::CastOptions;
use savvy::{r_println, savvy, Result};
use std::io::Cursor;
use std::ops::Neg;

#[savvy]
impl PlRExpr {
    fn print(&self) -> Result<()> {
        r_println!("{:?}", self.inner);
        Ok(())
    }

    fn add(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::Plus, rhs.inner).into())
    }

    fn sub(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::Minus, rhs.inner).into())
    }

    fn mul(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::Multiply, rhs.inner).into())
    }

    fn div(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::TrueDivide, rhs.inner).into())
    }

    fn rem(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::Modulus, rhs.inner).into())
    }

    fn floor_div(&self, rhs: PlRExpr) -> Result<Self> {
        Ok(dsl::binary_expr(self.inner.clone(), Operator::FloorDivide, rhs.inner).into())
    }

    fn neg(&self) -> Result<Self> {
        Ok(self.inner.clone().neg().into())
    }

    fn eq(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().eq(other.inner).into())
    }

    fn eq_missing(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().eq_missing(other.inner).into())
    }

    fn neq(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().neq(other.inner).into())
    }

    fn neq_missing(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().neq_missing(other.inner).into())
    }

    fn gt(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().gt(other.inner).into())
    }

    fn gt_eq(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().gt_eq(other.inner).into())
    }

    fn lt_eq(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().lt_eq(other.inner).into())
    }

    fn lt(&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().lt(other.inner).into())
    }

    fn alias(&self, name: &str) -> Result<Self> {
        Ok(self.inner.clone().alias(name).into())
    }

    fn not(&self) -> Result<Self> {
        Ok(self.inner.clone().not().into())
    }

    fn is_null(&self) -> Result<Self> {
        Ok(self.inner.clone().is_null().into())
    }

    fn is_not_null(&self) -> Result<Self> {
        Ok(self.inner.clone().is_not_null().into())
    }

    fn is_infinite(&self) -> Result<Self> {
        Ok(self.inner.clone().is_infinite().into())
    }

    fn is_finite(&self) -> Result<Self> {
        Ok(self.inner.clone().is_finite().into())
    }

    fn is_nan(&self) -> Result<Self> {
        Ok(self.inner.clone().is_nan().into())
    }

    fn is_not_nan(&self) -> Result<Self> {
        Ok(self.inner.clone().is_not_nan().into())
    }

    fn cast(&self, data_type: PlRDataType, strict: bool) -> Result<Self> {
        let dt = data_type.dt;

        let expr = if strict {
            self.inner.clone().strict_cast(dt)
        } else {
            self.inner.clone().cast(dt)
        };

        Ok(expr.into())
    }

    fn and (&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().and(other.inner).into())
    }

    fn or (&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().or(other.inner).into())
    }

    fn xor (&self, other: PlRExpr) -> Result<Self> {
        Ok(self.inner.clone().xor(other.inner).into())
    }
}

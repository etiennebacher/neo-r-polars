use crate::{prelude::*, PlRExpr};
use savvy::{savvy, Result};

#[savvy]
impl PlRExpr {
    fn dt_convert_time_zone(&self, time_zone: &str) -> Result<Self> {
        Ok(self
            .inner
            .clone()
            .dt()
            .convert_time_zone(time_zone.into())
            .into())
    }

    fn dt_replace_time_zone(
        &self,
        ambiguous: &PlRExpr,
        non_existent: &str,
        time_zone: Option<&str>,
    ) -> Result<Self> {
        Ok(self
            .inner
            .clone()
            .dt()
            .replace_time_zone(
                time_zone.map(|x| x.into()),
                ambiguous.inner.clone(),
                <Wrap<NonExistent>>::try_from(non_existent)?.0,
            )
            .into())
    }
}

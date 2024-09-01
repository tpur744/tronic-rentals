#include "InsuranceAddOn.h"

#include "Date.h"

InsuranceAddOn::InsuranceAddOn() {}

int InsuranceAddOn::GetCost(int days_rented) const { return 0; }

bool InsuranceAddOn::IsRentalValid(const Date& system_date,
                                   const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}
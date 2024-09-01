#include "ChildSeatAddOn.h"

#include "Date.h"

ChildSeatAddOn::ChildSeatAddOn() {}

int ChildSeatAddOn::GetCost(int days_rented) const {
  return std::min(daily_cost * days_rented, max_cost);
}

bool ChildSeatAddOn::IsRentalValid(const Date& system_date,
                                   const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}

#include "ChildSeatAddOn.h"

#include "Date.h"

ChildSeatAddOn::ChildSeatAddOn() : AddOn(AddOn::ChildSeat) {}

int ChildSeatAddOn::GetCost(int days_rented, int daily_rental_fee) const {
  return std::min(daily_cost_ * days_rented, max_cost_);
}

bool ChildSeatAddOn::IsRentalValid(const Date& system_date,
                                   const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}

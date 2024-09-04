#include "GpsAddOn.h"

#include "AddOn.h"
#include "Date.h"

GPSAddOn::GPSAddOn() : AddOn(AddOn::GPS) {}

int GPSAddOn::GetCost(int days_rented, int daily_rental_fee) const {
  return std::min(daily_cost_ * days_rented, max_cost_);
}

bool GPSAddOn::IsRentalValid(const Date& system_date,
                             const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}

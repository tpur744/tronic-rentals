#include "GpsAddOn.h"

#include "AddOn.h"
#include "Date.h"

GPSAddOn::GPSAddOn() {}

int GPSAddOn::GetCost(int days_rented) const {
  return std::min(daily_cost * days_rented, max_cost);
}

bool GPSAddOn::IsRentalValid(const Date& system_date,
                             const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}
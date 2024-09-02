#include "InsuranceAddOn.h"

#include "Date.h"

InsuranceAddOn::InsuranceAddOn() : AddOn(AddOn::Insurance) {}

int InsuranceAddOn::GetCost(int days_rented, int daily_rental_fee) const {
  int car_rental_cost;
  if (days_rented <= 4) {
    car_rental_cost = daily_rental_fee * days_rented;
  } else {
    int discounted_days = days_rented - 4;
    car_rental_cost =
        (daily_rental_fee * 4) + (daily_rental_fee / 2) * discounted_days;
  }
  return car_rental_cost * insurance_rate;
}
bool InsuranceAddOn::IsRentalValid(const Date& system_date,
                                   const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}

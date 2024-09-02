#include "InsuranceAddOn.h"

#include "Date.h"

InsuranceAddOn::InsuranceAddOn() : AddOn(AddOn::Insurance) {}

int InsuranceAddOn::GetCost(int days_rented, int daily_rental_fee) const {
  int total_rental_fee = days_rented * daily_rental_fee;
  return total_rental_fee * insurance_rate;
}

bool InsuranceAddOn::IsRentalValid(const Date& system_date,
                                   const Date& start_date) const {
  return !start_date.IsBefore(system_date);
}
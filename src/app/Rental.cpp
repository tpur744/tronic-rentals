#include "Rental.h"

#include <cstdio>  // for sscanf
#include <string>

#include "Car.h"
Rental::Rental(const std::string &registration_plate, const std::string &make,
               const std::string &daily_rental_fee,
               const std::string &start_date, const std::string &end_date,
               const std::string &customer_id,
               const std::string &rental_reference)
    : Car(registration_plate, make, daily_rental_fee) {
  start_date_ = start_date;
  end_date_ = end_date;
  customer_id_ = customer_id;
  rental_reference_ = rental_reference;
}

std::string Rental::GetStartDate() const { return start_date_; }


std::string Rental::GetEndDate() const { return end_date_; }

std::string Rental::GetCustomerId() const { return customer_id_; }
std::string Rental::GetRentalReference() const { return rental_reference_; }



bool Rental::OverlapsWith(const std::string &r_start_date,
                          const std::string &r_end_date,
                          const std::string &new_start_date,
                          const std::string &new_end_date) const {
  int r_start_day, r_start_month, r_start_year;
  int r_end_day, r_end_month, r_end_year;
  int new_start_day, new_start_month, new_start_year;
  int new_end_day, new_end_month, new_end_year;

  // Parse the dates
  sscanf(r_start_date.c_str(), "%d/%d/%d", &r_start_day, &r_start_month,
         &r_start_year);
  sscanf(r_end_date.c_str(), "%d/%d/%d", &r_end_day, &r_end_month, &r_end_year);
  sscanf(new_start_date.c_str(), "%d/%d/%d", &new_start_day, &new_start_month,
         &new_start_year);
  sscanf(new_end_date.c_str(), "%d/%d/%d", &new_end_day, &new_end_month,
         &new_end_year);

  // Check if the years and months are the same
  if (r_start_year != new_start_year || r_start_month != new_start_month ||
      r_end_month != new_end_month) {
    return false;
  }

  // Check if the ranges overlap
  return (r_start_day <= new_end_day && r_end_day >= new_start_day);
}


void Rental::AddGPSUnitCost(int gps_cost) {
    gps_unit_cost_ = gps_cost; 
}

void Rental::AddChildSeatCost(int seat_cost) {
    child_seat_cost_ = seat_cost; 
}


// int Rental::GetTotalCost() const {
//     int daily_fee = std::stoi(GetRentalFee());
//     int rental_days = DaysBetweenDates(start_date_, end_date_);
//     int base_cost = daily_fee * rental_days;
//     return base_cost + gps_unit_cost_; // Total cost including GPS Unit
// }
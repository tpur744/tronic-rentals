#include "Rental.h"

#include <vector>

#include "Car.h"
#include "Date.h"
Rental::Rental(const std::string &registration_plate, const std::string &make,
               const std::string &daily_rental_fee, const Date &start_date,
               const Date &end_date, const std::string &customer_id,
               const std::string &rental_reference)
    : Car(registration_plate, make, daily_rental_fee),
      start_date_(start_date),
      end_date_(end_date),
      customer_id_(customer_id),
      rental_reference_(rental_reference) {}

std::string Rental::GetStartDate() const { return start_date_.ToString(); }

std::string Rental::GetEndDate() const { return end_date_.ToString(); }

std::string Rental::GetCustomerId() const { return customer_id_; }

std::string Rental::GetRentalReference() const { return rental_reference_; }

std::string Rental::GetNumberPlate() const {
  return Car::GetNumberPlate();  // Call base class method or provide a new
                                 // implementcation
}

bool Rental::OverlapsWith(const Date &start_date1, const Date &end_date1,
                          const Date &start_date2,
                          const Date &end_date2) const {
  return !(end_date1 < start_date2 || end_date2 < start_date1);
}

void Rental::AddAddOn(AddOn *add_on) { add_ons_.push_back(add_on); }

#include "Rental.h"

Rental::Rental(const std::string &registration_plate, const std::string &make,
               const std::string &daily_rental_fee,
               const std::string &start_date, const std::string &end_date,
               const std::string &customer_id,
               const std::string &rental_reference)
    : Car(registration_plate, make, daily_rental_fee),
      start_date_(start_date),
      end_date_(end_date),
      customer_id_(customer_id),
      rental_reference_(rental_reference) {}

std::string Rental::GetStartDate() const { return start_date_; }

std::string Rental::GetEndDate() const { return end_date_; }

std::string Rental::GetCustomerId() const { return customer_id_; }

std::string Rental::GetRentalReference() const { return rental_reference_; }

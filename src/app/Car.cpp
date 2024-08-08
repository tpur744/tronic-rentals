#include "Car.h"

Car::Car(const std::string &registration_plate, const std::string &make,
         double daily_rental_fee) {
  registration_plate_ = registration_plate;
  make_ = make;
  daily_rental_fee_ = daily_rental_fee;
  is_available_ = true;
}

std::string Car::get_number_plate() const { return registration_plate_; }

std::string Car::get_model() const { return make_; }

double Car::get_rental_fee() const { return daily_rental_fee_; }

bool Car::is_available() const { return is_available_; }
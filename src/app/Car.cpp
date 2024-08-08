#include "Car.h"

Car::Car(const std::string &number_plate, const std::string &model,
         double rental_fee) {
  number_plate_ = number_plate;
  model_ = model;
  rental_fee_ = rental_fee;
  is_available_ = true;
}

std::string Car::get_number_plate() const { return number_plate_; }

std::string Car::get_model() const { return model_; }

double Car::get_rental_fee() const { return rental_fee_; }

bool Car::is_available() const { return is_available_; }
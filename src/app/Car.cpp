#include "Car.h"

Car::Car(const std::string &number_plate, const std::string &model,
         double rental_fee) {
  number_plate_ = number_plate;
  model_ = model;
  rental_fee_ = rental_fee;
  is_available_ = true;
}

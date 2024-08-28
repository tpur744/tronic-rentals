#include "Car.h"

#include <iostream>
#include <string>

using namespace std;

Car::Car(const std::string &registration_plate, const std::string &make,
         const std::string &daily_rental_fee) {
  registration_plate_ = registration_plate;
  make_ = make;
  daily_rental_fee_ = daily_rental_fee;
  is_available_ = true;
}

std::string Car::GetNumberPlate() const { return registration_plate_; }

std::string Car::GetModel() const { return make_; }

std::string Car::GetRentalFee() const { return daily_rental_fee_; }

bool Car::IsAvailable() const { return is_available_; }

void Car::SetAvailability(bool availability) { is_available_ = availability; }
#include "Car.h"

#include <iostream>
#include <string>
using namespace std;

Car::Car(const std::string &registration_plate, const std::string &make,
         std::string daily_rental_fee) {
  registration_plate_ = registration_plate;
  make_ = make;
  daily_rental_fee_ = daily_rental_fee;
  is_available_ = true;
  cout << "creating a car with plate " << registration_plate_ << endl;
}

std::string Car::GetNumberPlate() const { return registration_plate_; }

std::string Car::GetModel() const { return make_; }

std::string Car::GetRentalFee() const { return daily_rental_fee_; }

bool Car::IsAvailable() const { return is_available_; }

void Car::PrintCarDetails() const {
  cout << "Registration Plate: " << registration_plate_ << endl;
  cout << "Make: " << make_ << endl;
  cout << "Daily Rental Fee: " << daily_rental_fee_ << endl;
}

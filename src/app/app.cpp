#include "app.h"

#include <iostream>
#include <string>

#include "Car.h"
#include "message.h"
#include "utils.h"

using namespace std;

/*
----------------------------------------------------------------------------
  This is where you start.
  However, make sure you do not not write all your code in a single file!
----------------------------------------------------------------------------
*/

App::App() {
  // TODO implement
}

bool App::IsValidRegistrationPlate(const std::string &registration_plate) {
  std::string trimmed_plate = Utils::TrimString(registration_plate);
  if (trimmed_plate.length() != 6) return false;
  for (int i = 0; i < 3; i++) {
    if (!isalpha(trimmed_plate[i])) return false;
  }
  for (int i = 3; i < 6; i++) {
    if (!isdigit(trimmed_plate[i])) return false;
  }
  return true;
}

bool App::IsUniqueRegistrationPlate(
    const std::string &registration_plate) const {
  std::string upper_plate = Utils::GetUppercase(registration_plate);
  int count = cars_.size();
  for (size_t i = 0; i < count; i++) {
    if (Utils::GetUppercase(cars_[i]->GetNumberPlate()) == registration_plate)
      return false;
  }
  return true;
}

void App::CreateCar(const std::string &registration_plate,
                    const std::string &make,
                    const std::string &daily_rental_fee) {
  std::string upper_plate = Utils::GetUppercase(registration_plate);

  if (!IsValidRegistrationPlate(upper_plate)) {
    cout << "invalid plate" << endl;
    return;
  }

  if (!IsUniqueRegistrationPlate(upper_plate)) {
    cout << "duplicate plate" << endl;
    return;
  }
  Car *new_car = new Car(upper_plate, make, daily_rental_fee);
  cars_.push_back(new_car);
}

void App::DisplayCars() const {
  int count = cars_.size();
  for (size_t i = 0; i < count; i++) {
    // Ensure cars_[i] is not null before dereferencing
    if (cars_[i] != nullptr) {
      cout << cars_[i]->GetNumberPlate() << endl;
      cout << "CAR CREATED" << endl;
    }
  }
}

void App::ConfigureDate(const std::string &date) {
  // TODO implement
}

void App::DisplayDate() const {
  // TODO implement
}

void App::CreateRental(const std::vector<std::string> options) {
  // TODO implement
}

void App::DisplayRentals(const std::string &registration_plate) const {
  // TODO implement
}

void App::AddGPSUnit(const std::string &rental_reference) {
  // TODO implement
}

void App::AddChildSeat(const std::string &rental_reference) {
  // TODO implement
}

void App::AddInsurance(const std::string &rental_reference) {
  // TODO implement
}

void App::DisplayReceipt(const std::string &rental_reference) const {
  // TODO implement
}
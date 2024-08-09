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

void App::CreateCar(const std::string &registration_plate,
                    const std::string &make,
                    const std::string &daily_rental_fee) {
  // Create a new Car object on the heap and store the pointer in the vector
  Car *new_car = new Car(registration_plate, make, daily_rental_fee);
  cars_.push_back(new_car);
}

void App::DisplayCars() const {
  int count = cars_.size();
  for (size_t i = 0; i < count; i++) {
    // Ensure cars_[i] is not null before dereferencing
    if (cars_[i] != nullptr) {
      cout << cars_[i]->GetNumberPlate() << endl;
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

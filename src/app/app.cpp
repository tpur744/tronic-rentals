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
  std::string formatted_make = make;

  if (!formatted_make.empty()) {
    formatted_make[0] = toupper(formatted_make[0]);
    for (size_t i = 1; i < formatted_make.length(); i++) {
      formatted_make[i] = tolower(formatted_make[i]);
    }
  }

  if (!IsValidRegistrationPlate(upper_plate)) {
    cout << "Invalid registration plate '" << upper_plate
         << "'. Car not created." << endl;
    return;
  }
  if (!IsUniqueRegistrationPlate(upper_plate)) {
    cout << "Car with registration plate '" << upper_plate
         << "' already exists." << endl;
    return;
  }

  if (!Utils::IsInteger(daily_rental_fee)) {
    cout << "Rental fee must be numeric. Car not created." << endl;
    return;
  }

  int fee;
  fee = stoi(daily_rental_fee);
  if (fee <= 0) {
    cout << "Rental fee must be greater than 0. Car not created." << endl;
    return;
  }

  Car *new_car = new Car(upper_plate, formatted_make, daily_rental_fee);
  cars_.push_back(new_car);
  cout << "Car with registration plate '" << upper_plate << "' created."
       << endl;
}

void App::DisplayCars() const {
  int count = cars_.size();
  if (count == 0) {
    cout << "No cars available." << endl;
    return;
  }

  // Display the number of cars with correct grammar
  if (count == 1) {
    cout << "There is 1 car in the system: " << endl;
  } else {
    cout << "There are " << count << " cars in the system:" << endl;
  }

  for (size_t i = 0; i < count; i++) {
    // Ensure cars_[i] is not null before dereferencing
    if (cars_[i] != nullptr) {
      cout << "* '" << cars_[i]->GetNumberPlate() << "' - "
           << cars_[i]->GetModel() << ", " << "$" << cars_[i]->GetRentalFee()
           << "/day, " << "available" << endl;
    }
  }
}

void App::ConfigureDate(const std::string &date) {
  if (system_date_.empty()) {
    system_date_ = date;
    std::cout << "Date configured to '" << system_date_ << "'." << std::endl;
    return;
  }

  int new_day, new_month, new_year;
  int current_day, current_month, current_year;

  sscanf(date.c_str(), "%d/%d/%d", &new_day, &new_month, &new_year);
  sscanf(system_date_.c_str(), "%d/%d/%d", &current_day, &current_month,
         &current_year);

  // Compare years, months, and days
  if (new_year > current_year ||
      (new_year == current_year && new_month > current_month) ||
      (new_year == current_year && new_month == current_month &&
       new_day >= current_day)) {
    system_date_ = date;
    std::cout << "Current date configured to '" << system_date_ << "'."
              << std::endl;
  } else {
    std::cout << "Cannot configure to a date before the current date."
              << std::endl;
  }
}
void App::DisplayDate() const {
  if (system_date_.empty()) {
    std::cout << "Date has not been configured." << std::endl;
  } else {
    std::cout << "Current system date is '" << system_date_ << "'."
              << std::endl;
  }
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

#include "app.h"

#include <iostream>
#include <string>

#include "Car.h"
#include "Rental.h"
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

bool App::IsDateBefore(const std::string &date1,
                       const std::string &date2) const {
  int day1, month1, year1;
  int day2, month2, year2;

  // Parse the dates
  sscanf(date1.c_str(), "%d/%d/%d", &day1, &month1, &year1);
  sscanf(date2.c_str(), "%d/%d/%d", &day2, &month2, &year2);

  // Compare years, months, and days
  if (year1 < year2) return true;
  if (year1 == year2 && month1 < month2) return true;
  if (year1 == year2 && month1 == month2 && day1 < day2) return true;

  return false;
}
void App::ConfigureDate(const std::string &date) {
  if (system_date_.empty()) {
    system_date_ = date;
    std::cout << "Date configured to '" << system_date_ << "'." << std::endl;
    return;
  }

  if (IsDateBefore(date, system_date_)) {
    std::cout << "Cannot configure to a date before the current date."
              << std::endl;
    return;
  }

  system_date_ = date;
  std::cout << "Current date configured to '" << system_date_ << "'."
            << std::endl;
}
void App::DisplayDate() const {
  if (system_date_.empty()) {
    std::cout << "Date has not been configured." << std::endl;
  } else {
    std::cout << "Current system date is '" << system_date_ << "'."
              << std::endl;
  }
}

void App::CreateRental(const std::vector<std::string> options) {}
/* if (system_date_.empty()) {
   std::cout << "Date has not been configured." << std::endl;
   return;
 }
 if (options.size() != 4) {
   std::cout << "Error: Incorrect number of arguments provided." << std::endl;
   return;
 }

 std::string registration_plate = Utils::GetUppercase(options[0]);
 std::string start_date = options[1];
 std::string end_date = options[2];
 std::string customer_id = Utils::GetLowercase(options[3]);

 Car *car = nullptr;
 for (size_t i = 0; i < cars_.size(); i++) {
   if (cars_[i]->GetNumberPlate() == registration_plate) {
     car = cars_[i];
     break;  // Exit the loop once the car is found
   }
 }

 if (start_date < system_date_) {
   std::cout << "Error: Start date cannot be in the past." << std::endl;
   return;
 }

 if (end_date < start_date) {
   std::cout << "Error: End date cannot be before start date." << std::endl;
   return;
 }
 for (size_t i = 0; i < rentals_.size(); ++i) {
   if (rentals_[i]->GetNumberPlate() == registration_plate &&
       rentals_[i]->OverlapsWith(start_date, end_date)) {
     std::cout
         << "Error: Car is already rented during the specified date range."
         << std::endl;
     return;
   }
 }
}
*/

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

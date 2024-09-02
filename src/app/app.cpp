#include "app.h"

#include <iostream>
#include <string>
#include <vector>

#include "Car.h"
#include "ChildSeatAddOn.h"
#include "Date.h"
#include "GpsAddOn.h"
#include "InsuranceAddOn.h"
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

App::App() : system_date_("01/01/0000"), date_set_(false) {}

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
    if (Utils::GetUppercase(cars_[i]->GetNumberPlate()) == upper_plate)
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
      std::cout << "  * '" << cars_[i]->GetNumberPlate() << "' - "
                << cars_[i]->GetModel() << ", " << "$"
                << cars_[i]->GetRentalFee() << "/day, "
                << (cars_[i]->IsAvailable() ? "available" : "not available")
                << std::endl;
    }
  }
}

void App::ConfigureDate(const std::string &date_str) {
  Date new_date(date_str);

  if (date_set_ && new_date.IsBefore(system_date_)) {
    std::cout << "Cannot configure to a date before the current date."
              << std::endl;
    return;
  }

  // Update system date
  system_date_ = new_date;
  date_set_ = true;

  int day = system_date_.GetDay();
  int month = system_date_.GetMonth();
  int year = system_date_.GetYear();

  std::string day_string =
      (day < 10) ? "0" + std::to_string(day) : std::to_string(day);
  std::string month_string =
      (month < 10) ? "0" + std::to_string(month) : std::to_string(month);

  std::cout << "Date configured to '" << day_string << "/" << month_string
            << "/" << year << "'." << std::endl;
}

void App::DisplayDate() const {
  if (date_set_) {
    std::cout << "Current system date is '" << system_date_.ToString() << "'."
              << endl;
  } else {
    std::cout << "Date has not been configured." << std::endl;
  }
}

void App::CreateRental(const std::vector<std::string> options) {
  if (!date_set_) {
    std::cout << "Date has not been configured." << std::endl;
    return;
  }

  std::string registration_plate = Utils::GetUppercase(options[0]);
  Date start_date = options[1];
  Date end_date = options[2];
  std::string customer_id = Utils::GetLowercase(options[3]);

  Car *car = nullptr;
  for (size_t i = 0; i < cars_.size(); ++i) {
    if (cars_[i]->GetNumberPlate() == registration_plate) {
      car = cars_[i];
      break;
    }
  }

  if (car == nullptr) {
    std::cout << "There is no car with the registration plate '"
              << registration_plate << "'." << std::endl;
    return;
  }
  if (start_date.IsBefore(system_date_)) {
    std::cout << "Start date must be today (" << system_date_.ToString()
              << ") or later." << std::endl;
    return;
  }
  if (end_date.IsBefore(start_date)) {
    std::cout << "End date must be on or after the start date ("
              << start_date.ToString() << ")." << std::endl;
    return;
  }
  for (size_t i = 0; i < rentals_.size(); ++i) {
    // Convert rental start and end dates from strings to Date objects
    Date rental_start_date(rentals_[i]->GetStartDate());
    Date rental_end_date(rentals_[i]->GetEndDate());

    if (rentals_[i]->GetNumberPlate() == registration_plate &&
        rentals_[i]->OverlapsWith(rental_start_date, rental_end_date,
                                  start_date, end_date)) {
      std::cout << "Car with registration plate '" << registration_plate
                << "' is already rented at this time ("
                << rentals_[i]->GetRentalReference() << ")." << std::endl;
      return;
    }
  }

  int rental_count = 0;
  for (Rental *rental : rentals_) {
    if (rental->GetNumberPlate() == registration_plate) {
      rental_count++;
    }
  }
  std::string rental_reference = "RR-" +
                                 Utils::GetUppercase(registration_plate) + "-" +
                                 std::to_string(rental_count + 1);

  Rental *new_rental =
      new Rental(registration_plate, car->GetModel(), car->GetRentalFee(),
                 start_date, end_date, customer_id, rental_reference);
  rentals_.push_back(new_rental);

  int days_rented = start_date.DaysBetween(end_date);

  std::cout << "Car with registration plate '" << registration_plate
            << "' is now rented to '" << customer_id << "' for " << days_rented
            << " day" << (days_rented > 1 ? "s" : "")
            << " with reference number '" << rental_reference << "'."
            << std::endl;
}

void App::DisplayRentals(const std::string &registration_plate) const {
  if (!date_set_) {
    std::cout << "Date has not been configured." << std::endl;
    return;
  }

  std::string upper_registration_plate =
      Utils::GetUppercase(registration_plate);

  bool rental_found = false;
  bool upcoming_rentals_found = false;
  bool car_exists = false;

  // Check if the car exists
  for (const Car *car : cars_) {
    if (car->GetNumberPlate() == upper_registration_plate) {
      car_exists = true;
      break;
    }
  }
  for (const Rental *rental : rentals_) {
    if (rental->GetNumberPlate() == upper_registration_plate) {
      rental_found = true;
      Date start_date(rental->GetStartDate());
      Date end_date(rental->GetEndDate());

      bool is_current =
          !(end_date < system_date_) && !(system_date_ < start_date);
      bool is_upcoming = start_date > system_date_;

      if (is_current || is_upcoming) {
        upcoming_rentals_found = true;
        int days_rented = start_date.DaysBetween(end_date);
        std::cout << "  * " << start_date.ToString() << " - "
                  << end_date.ToString() << " (" << days_rented << " days) - "
                  << rental->GetRentalReference() << std::endl;
      }
    }
  }
  if (!car_exists) {
    std::cout << "There is no car with the registration plate '"
              << upper_registration_plate << "'." << std::endl;
  } else if (!upcoming_rentals_found) {
    std::cout << "No upcoming rentals." << std::endl;
  }
}

void App::AddGPSUnit(const std::string &rental_reference) {
  Rental *rental = nullptr;
  for (Rental *r : rentals_) {
    if (r->GetRentalReference() == rental_reference) {
      rental = r;
      break;
    }
  }
  if (!rental) {
    std::cout << "Rental reference '" << rental_reference
              << "' not found, GPS Unit not added." << std::endl;
    return;
  }

  Date rental_start_date(rental->GetStartDate());
  if (rental_start_date.IsBefore(system_date_)) {
    std::cout << "Rental '" << rental_reference
              << "' is in the past, too late to add GPS Unit." << std::endl;
    return;
  }

  GPSAddOn *gps_add_on = new GPSAddOn();
  int days_rented = rental_start_date.DaysBetween(Date(rental->GetEndDate()));
  int cost = gps_add_on->GetCost(days_rented, stoi(rental->GetRentalFee()));
  rental->AddAddOn(gps_add_on);
  std::cout << "GPS Unit added to rental '" << rental_reference << "'."
            << std::endl;
}

void App::AddChildSeat(const std::string &rental_reference) {
  // Find the rental by reference
  Rental *rental = nullptr;
  for (Rental *r : rentals_) {
    if (r->GetRentalReference() == rental_reference) {
      rental = r;
      break;
    }
  }

  // If rental reference is not found
  if (!rental) {
    std::cout << "Rental reference '" << rental_reference
              << "' not found, Child Seat not added." << std::endl;
    return;
  }

  // Check if the rental start date is before the system date
  Date rental_start_date(rental->GetStartDate());
  if (rental_start_date.IsBefore(system_date_)) {
    std::cout << "Rental '" << rental_reference
              << "' is in the past, too late to add Child Seat." << std::endl;
    return;
  }

  // Create a new ChildSeatAddOn object
  ChildSeatAddOn *child_seat_add_on = new ChildSeatAddOn();

  // Calculate the cost based on the number of days rented
  int days_rented = rental_start_date.DaysBetween(Date(rental->GetEndDate()));
  int cost =
      child_seat_add_on->GetCost(days_rented, stoi(rental->GetRentalFee()));

  // Add the child seat add-on to the rental
  rental->AddAddOn(child_seat_add_on);

  std::cout << "Child Seat added to rental '" << rental_reference << "'."
            << std::endl;
}

void App::AddInsurance(const std::string &rental_reference) {
  Rental *rental = nullptr;
  for (Rental *r : rentals_) {
    if (r->GetRentalReference() == rental_reference) {
      rental = r;
      break;
    }
  }
  if (!rental) {
    std::cout << "Rental reference '" << rental_reference
              << "' not found, Insurance not added." << std::endl;
    return;
  }

  Date rental_start_date(rental->GetStartDate());
  if (rental_start_date.IsBefore(system_date_)) {
    std::cout << "Rental '" << rental_reference
              << "' is in the past, too late to add Insurance." << std::endl;
    return;
  }
  int daily_rental_fee = stoi(rental->GetRentalFee());
  int days_rented = rental_start_date.DaysBetween(Date(rental->GetEndDate()));
  InsuranceAddOn *insurance_add_on = new InsuranceAddOn();
  int cost = insurance_add_on->GetCost(days_rented, daily_rental_fee);
  rental->AddAddOn(insurance_add_on);
  std::cout << "Insurance added to rental '" << rental_reference << "'."
            << std::endl;
}

void App::DisplayReceipt(const std::string &rental_reference) const {
  Rental *rental = nullptr;
  for (Rental *r : rentals_) {
    if (r->GetRentalReference() == rental_reference) {
      rental = r;
      break;
    }
  }
  if (!rental) {
    std::cout << "Rental reference '" << rental_reference
              << "' not found, no receipt to display." << std::endl;
    return;
  }
  Date start_date(rental->GetStartDate());
  Date end_date(rental->GetEndDate());
  int days_rented = start_date.DaysBetween(end_date);

  int daily_rental_fee = std::stoi(rental->GetRentalFee());
  int car_rental_cost;
  if (days_rented <= 4) {
    car_rental_cost = daily_rental_fee * days_rented;
  } else {
    int discounted_days = days_rented - 4;
    car_rental_cost =
        (daily_rental_fee * 4) + (daily_rental_fee / 2) * discounted_days;
  }
  int gps_cost = 0;
  int child_seat_cost = 0;
  int insurance_cost = 0;

  std::vector<AddOn *> add_ons =
      rental->GetAddOns();  // Accessing add_ons_ directly
  for (size_t i = 0; i < add_ons.size(); ++i) {
    AddOn *add_on = add_ons[i];
    int cost = add_on->GetCost(days_rented, daily_rental_fee);
    switch (add_on->GetType()) {
      case AddOn::GPS:
        gps_cost = cost;
        break;
      case AddOn::ChildSeat:
        child_seat_cost = cost;
        break;
      case AddOn::Insurance:
        insurance_cost = cost;
        break;
    }
  }
  int grand_total =
      car_rental_cost + gps_cost + child_seat_cost + insurance_cost;

  // Print receipt
  std::cout
      << "\n===============================================================\n"
      << "                           RECEIPT\n"
      << "             -------------------------------------\n\n"
      << "Booking Reference: " << rental_reference << "\n\n"
      << "Booking Details:\n"
      << "  Customer ID: " << rental->GetCustomerId() << "\n\n"
      << "Rental Details:\n"
      << "  Pickup Date: " << start_date.ToString() << "\n"
      << "  Return Date: " << end_date.ToString() << "\n"
      << "  Number of Days: " << days_rented << "\n\n"
      << "Cost Breakdown:\n"
      << "  Car Rental: $" << car_rental_cost << "\n";

  // Print addon costs
  if (gps_cost > 0) {
    std::cout << "  GPS Unit Add-on: $" << gps_cost << "\n";
  }
  if (child_seat_cost > 0) {
    std::cout << "  Child Seat Add-on: $" << child_seat_cost << "\n";
  }
  if (insurance_cost > 0) {
    std::cout << "  Insurance Add-on: $" << insurance_cost << "\n";
  }

  // Print grand total
  std::cout
      << "\nGRAND TOTAL: $" << grand_total << "\n\n"
      << "Thank you for choosing TronicRentals!\n"
      << "For any inquiries, please contact support@tronicrentals.co.nz\n"
      << "===============================================================\n";
}

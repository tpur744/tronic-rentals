#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

#include "Car.h"
#include "Date.h"
#include "Rental.h"

/*
----------------------------------------------------------------------------
  This is where you start.
  However, make sure you do not not write all your code in a single file!
----------------------------------------------------------------------------
*/

class App {
 private:
  std::vector<Car *> cars_;
  std::vector<Rental *> rentals_;
  Date system_date_;
  bool date_set_;

  bool IsValidRegistrationPlate(const std::string &registration_plate);
  bool IsUniqueRegistrationPlate(const std::string &registration_plate) const;

 public:
  App();
  void CreateCar(const std::string &registration_plate, const std::string &make,
                 const std::string &daily_rental_fee);
  void DisplayCars() const;
  void ConfigureDate(const std::string &date);
  void DisplayDate() const;
  void CreateRental(const std::vector<std::string> options);
  void DisplayRentals(const std::string &registration_plate) const;
  void AddGPSUnit(const std::string &rental_reference);
  void AddChildSeat(const std::string &rental_reference);
  void AddInsurance(const std::string &rental_reference);
  void DisplayReceipt(const std::string &rental_reference) const;
};

#endif  // APP_H

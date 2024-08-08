#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
 public:
  Car(const std::string &registration_plate, const std::string &make,
      double daily_rental_fee);

  // getter methods
  std::string get_number_plate() const;
  std::string get_model() const;
  double get_rental_fee() const;
  bool is_available() const;

 private:
  std::string registration_plate_;
  std::string make_;
  double daily_rental_fee_;
  bool is_available_;
};

#endif
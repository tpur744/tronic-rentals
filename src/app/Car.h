#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
 public:
  Car(const std::string& number_plate, const std::string& model,
      double rental_fee);

  // getter methods
  std::string get_number_plate() const;
  std::string get_model() const;
  double get_rental_fee() const;
  bool is_available() const;

 private:
  std::string number_plate_;
  std::string model_;
  double rental_fee_;
  bool is_available_;
};

#endif
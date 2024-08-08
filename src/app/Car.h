#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
 public:
  Car(const std::string& number_plate, const std::string& model,
      double rental_fee);

 private:
  std::string number_plate_;
  std::string model_;
  double rental_fee_;
  bool is_available_;
};

#endif
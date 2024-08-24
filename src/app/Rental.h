#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"

class Rental : public Car {
 public:
  Rental(const std::string &registration_plate, const std::string &make,
         const std::string &daily_rental_fee);

 private:
};

#endif
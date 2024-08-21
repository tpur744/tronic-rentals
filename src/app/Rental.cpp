#include "Rental.h"
#include "Car.h"
Rental::Rental (const std::string &registration_plate, const std::string &make, const std::string &daily_rental_fee):Car(registration_plate, make, daily_rental_fee) {}


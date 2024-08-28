#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>

class Car {
 public:
  Car(const std::string &registration_plate, const std::string &make,
      const std::string &daily_rental_fee);

  // getter methods
  std::string GetNumberPlate() const;
  std::string GetModel() const;
  std::string GetRentalFee() const;
  bool IsAvailable() const;
  void SetAvailability(bool availability);

 private:
  std::string registration_plate_;
  std::string make_;
  std::string daily_rental_fee_;
  bool is_available_;
};

#endif

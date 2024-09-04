#ifndef RENTAL_H
#define RENTAL_H
#include <string>
#include <vector>

#include "AddOn.h"
#include "Car.h"
#include "Date.h"

class Rental : public Car {
 public:
  Rental(const std::string &registration_plate, const std::string &make,
         const std::string &daily_rental_fee, const Date &start_date,
         const Date &end_date, const std::string &customer_id,
         const std::string &rental_reference);

  std::string GetStartDate() const;
  std::string GetEndDate() const;
  std::string GetCustomerId() const;
  std::string GetRentalFee() const override;
  std::string GetRentalReference() const;
  std::string GetNumberPlate() const override;
  bool OverlapsWith(const Date &start_date1, const Date &end_date1,
                    const Date &start_date2, const Date &end_date2) const;
  void AddAddOn(AddOn *add_on);
  std::vector<AddOn*> GetAddOns() const;

 private:
  Date start_date_;
  Date end_date_;
  std::string customer_id_;
  std::string rental_reference_;
  std::vector<AddOn *> add_ons_;
};

#endif  // RENTAL_H

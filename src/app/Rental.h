#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"

class Rental : public Car {
 public:
  Rental(const std::string &registration_plate, const std::string &make,
         const std::string &daily_rental_fee, const std::string &start_date,
         const std::string &end_date, const std::string &customer_id,
         const std::string &rental_reference);

  std::string GetStartDate() const;
  std::string GetEndDate() const;
  std::string GetCustomerId() const;
  std::string GetRentalReference() const;
  bool OverlapsWith(const std::string &r_start_date, const std::string &r_end_date,
	const std::string &new_start_date,const std::string &new_end_date) const;
	void AddGPSUnitCost(int cost); // Method to add GPS cost
	void AddChildSeatCost(int seat_cost);


 private:
  std::string start_date_;
  std::string end_date_;
  std::string customer_id_;
  std::string rental_reference_;
	int gps_unit_cost_ = 0;
	int child_seat_cost_ = 0;
};

#endif
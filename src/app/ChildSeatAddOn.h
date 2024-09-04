#ifndef CHILDSEATADDON_H
#define CHILDSEATADDON_H

#include "AddOn.h"
#include "Date.h"

class ChildSeatAddOn : public AddOn {
 public:
  // Corrected constructor definition
  ChildSeatAddOn();

  int GetCost(int days_rented, int daily_rental_fee) const override;
  bool IsRentalValid(const Date& system_date,
                     const Date& start_date) const override;

 private:
  const int max_cost_ = 10;   // Max cost of Child Seat add-on
  const int daily_cost_ = 2;  // Daily cost of Child Seat add-on
};

#endif  // CHILDSEATADDON_H

#ifndef CHILDSEATADDON_H
#define CHILDSEATADDON_H

#include "AddOn.h"
#include "Date.h"

class ChildSeatAddOn : public AddOn {
 public:
  ChildSeatAddOn();

  int GetCost(int days_rented) const override;
  bool IsRentalValid(const Date& system_date,
                     const Date& start_date) const override;

 private:
  const int max_cost = 10;   // Max cost of Child Seat add-on
  const int daily_cost = 2;  // Daily cost of Child Seat add-on
};

#endif  // CHILDSEATADDON_H
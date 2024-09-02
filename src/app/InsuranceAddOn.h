#ifndef INSURANCEADDON_H
#define INSURANCEADDON_H

#include "AddOn.h"

class InsuranceAddOn : public AddOn {
 public:
  InsuranceAddOn();

  int GetCost(int days_rented, int daily_rental_fee) const override;

  bool IsRentalValid(const Date& system_date,
                     const Date& start_date) const override;
  const double insurance_rate = 0.05;  // 5% of the total rental fee
};

#endif  // INSURANCEADDON_H

#ifndef GPSADDON_H
#define GPSADDON_H
#include "AddOn.h"
#include "Date.h"

class GPSAddOn : public AddOn {
 public:
  GPSAddOn();

  int GetCost(int days_rented, int daily_rental_fee) const override;
  bool IsRentalValid(const Date& system_date,
                     const Date& start_date) const override;

 private:
  const int max_cost_ = 25;   // Max cost of GPS add-on
  const int daily_cost_ = 5;  // Daily cost of GPS add-on
};

#endif  // GPSADDON_H

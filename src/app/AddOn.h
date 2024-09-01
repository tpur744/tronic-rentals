#ifndef ADDON_H
#define ADDON_H
#include <string>

#include "Date.h"

class AddOn {
 public:
  virtual int GetCost(int days_rented) const = 0;

  virtual bool IsRentalValid(const Date& system_date,
                             const Date& start_date) const = 0;
};

#endif  // ADDON_H

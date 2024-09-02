#ifndef ADDON_H
#define ADDON_H

#include "Date.h"

class AddOn {
 public:
  enum AddOnType { GPS, ChildSeat, Insurance };

  AddOn(AddOnType type) : type_(type) {}

  virtual int GetCost(int days_rented, int daily_rental_fee) const = 0;
  virtual bool IsRentalValid(const Date& system_date,
                             const Date& start_date) const = 0;

  AddOnType GetType() const { return type_; }

 private:
  AddOnType type_;
};

#endif  // ADDON_H

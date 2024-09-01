#include "Date.h"

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {}

int Date::GetDay() const { return day_; }

int Date::GetMonth() const { return month_; }

int Date::GetYear() const { return year_; }

bool Date::IsBefore(const Date& other) const {
  if (year_ < other.year_) return true;
  if (year_ == other.year_ && month_ < other.month_) return true;
  if (year_ == other.year_ && month_ == other.month_ && day_ < other.day_)
    return true;
  return false;
}

int Date::DaysBetween(const Date& other) const {
  // Calculate the difference in days
  return std::abs(day_ - other.day_);
}

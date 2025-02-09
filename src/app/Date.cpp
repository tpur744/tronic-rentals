#include "Date.h"

#include <iomanip>
#include <sstream>

Date::Date() : day_(0), month_(0), year_(0) {}

Date::Date(const std::string& date_str) { ParseDate(date_str); }

void Date::ParseDate(const std::string& date_str) {
  sscanf(date_str.c_str(), "%d/%d/%d", &day_, &month_, &year_);
}

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
  return std::abs(day_ - other.day_) + 1;
}

std::string Date::ToString() const {
  std::string day_str = (day_ < 10 ? "0" : "") + std::to_string(day_);
  std::string month_str = (month_ < 10 ? "0" : "") + std::to_string(month_);
  std::string year_str = std::to_string(year_);
  return day_str + "/" + month_str + "/" + year_str;
}

// Implement comparison operators
bool Date::operator<(const Date& other) const { return IsBefore(other); }

bool Date::operator<=(const Date& other) const { return !(*this > other); }

bool Date::operator>(const Date& other) const { return other.IsBefore(*this); }

bool Date::operator>=(const Date& other) const { return !(*this < other); }

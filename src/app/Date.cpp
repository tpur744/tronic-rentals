#include <cstdio>
#include <string>

class Date {
 public:
  // Constructor that takes day, month, and year
  Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}

  // Constructor that parses a date string in the format "dd/mm/yyyy"
  Date(const std::string &date_str) {
    sscanf(date_str.c_str(), "%d/%d/%d", &day_, &month_, &year_);
  }

  // Method to compare if two dates are the same
  bool IsSameDate(const Date &other) const {
    return (day_ == other.day_ && month_ == other.month_ &&
            year_ == other.year_);
  }

  // Method to check if this date is before another date
  bool IsBefore(const Date &other) const {
    if (year_ != other.year_) return year_ < other.year_;
    if (month_ != other.month_) return month_ < other.month_;
    return day_ < other.day_;
  }

  // Method to check if this date is after another date
  bool IsAfter(const Date &other) const {
    return !IsBefore(other) && !IsSameDate(other);
  }

  // Convert the date back to string
  std::string ToString() const {
    char buffer[11];
    sprintf(buffer, "%02d/%02d/%04d", day_, month_, year_);
    return std::string(buffer);
  }

 private:
  int day_;
  int month_;
  int year_;
};
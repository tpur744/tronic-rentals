#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 public:
  // Constructor that takes day, month, and year
  Date(int day, int month, int year);

  // Constructor that parses a date string in the format "dd/mm/yyyy"
  Date(const std::string &date_str);

  // Method to compare if two dates are the same
  bool IsSameDate(const Date &other) const;

  // Method to check if this date is before another date
  bool IsBefore(const Date &other) const;

  // Method to check if this date is after another date
  bool IsAfter(const Date &other) const;

  // Convert the date back to string
  std::string ToString() const;

 private:
  int day_;
  int month_;
  int year_;
};

#endif  // DATE_H
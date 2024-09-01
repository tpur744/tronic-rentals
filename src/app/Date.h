// Date.h
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 public:
  // Constructors
  Date(const std::string& date_str);   // Initialize from a string
  Date(int day, int month, int year);  // Initialize with day, month, and year

  // Methods to get date components
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
  bool IsBefore(const Date& other) const;
  int DaysBetween(const Date& other) const;

 private:
  int day_;
  int month_;
  int year_;
};

#endif  // DATE_H
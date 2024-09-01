// Date.h
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 public:
  // Constructors
  Date(const std::string& date_str);  // Initialize from a string

  // Methods to get date components
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
  bool IsBefore(const Date& other) const;
  int DaysBetween(const Date& other) const;
  void ParseDate(const std::string& date_str);
  std::string ToString() const;

 private:
  int day_;
  int month_;
  int year_;
};

#endif  // DATE_H

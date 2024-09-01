#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 public:
  Date();
  Date(const std::string& date_str);

  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;

  bool IsBefore(const Date& other) const;
  int DaysBetween(const Date& other) const;
  std::string ToString() const;

  // Comparison operators
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;
  bool operator>(const Date& other) const;
  bool operator>=(const Date& other) const;

 private:
  void ParseDate(const std::string& date_str);
  int day_;
  int month_;
  int year_;
};

#endif  // DATE_H

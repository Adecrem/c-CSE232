#ifndef DATE_H
#define DATE_H

#include <string>
using std::string;

struct Date{
  int year=1970;
  int month = 1;
  int day = 1;
  Date() = default;
  Date(int y, int m, int d) : year(y), month(m), day(d) {};
  Date(string s);
  string to_string();
  void increment_day(int);
};


#endif
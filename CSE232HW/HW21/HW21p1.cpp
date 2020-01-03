#include <iostream>
#include <sstream>
#include "date.h"
using std::string;
using std::ostringstream;
using std::stoi;

string Date::to_string(){
  ostringstream oss;
  oss  << year << '-' << std::setfill('0') << std::setw(2) << month << '-' << std::setfill('0') << std::setw(2) << day;
  return oss.str();
}

Date::Date(string s){
  string year1 = s.substr(0,4);
  string month1 = s.substr(5,7);
  string day1 = s.substr(8);
  int year2 = stoi(year1);
  int month2 = stoi(month1);
  int day2 = stoi(day1);
  year = year2;
  month = month2;
  day = day2;
  
}


void Date::increment_day(int n1 = 1){
  //greg to julian
  int a1 = (14-month)/12;
  int y1 = year+4800-a1;
  int m1 = month+12 * a1-3;
  int jul = day+((153*m1+2)/5)+(365*y1)+(y1/4)-(y1/100)+(y1/400)-32045;
  jul+=n1;
  //jul to greg
  int a2 = jul + 32044;
  int b2 = (4 * a2 + 3)/146097;
  int c2 = a2 - (146097*b2)/4;
  int d2 = (4 * c2 + 3)/1461;
  int e2 = c2 - (1461 * d2)/4;
  int f1 = (5*e2 + 2)/153;
  year = 100*b2+d2-4800+(f1/10);
  month = f1+3-12*(f1/10);
  day = e2-((153*f1+2)/5)+1;
  
}

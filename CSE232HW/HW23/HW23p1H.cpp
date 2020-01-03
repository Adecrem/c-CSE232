#pragma once

#include <string>
#include <vector>
#include<iostream>

class Counter {
 private:
  int value_ = 0;
  int initial_value_ = 0;
  
 public:
  std::vector<std::string> log_;
  Counter(int v);
  Counter(const Counter&);
  ~Counter() {};
  Counter();
  int value();
  Counter& operator=(const Counter&);
  
  friend std::ostream & operator<<(std::ostream &, Counter &);
  friend Counter operator+(Counter &, Counter &);
};

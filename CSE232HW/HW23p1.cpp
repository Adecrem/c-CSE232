#include "counter.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

Counter::Counter(int v) : value_(v), initial_value_(v), log_() {
  log_.push_back("Constructor called with a " + std::to_string(value_));
}

Counter::Counter(){
  log_.push_back("Default Constructor called.");
}

int Counter::value() {
  int result = value_--;
  log_.push_back("value called. Returned a " + std::to_string(result));
  return result;
}

Counter::Counter(const Counter& c){
  value_=c.value_;
  initial_value_=c.initial_value_;
  log_=c.log_;
  log_.push_back("Copy Constructor called.");
}


Counter& Counter::operator=(const Counter&c){
  value_=c.value_;
  initial_value_=c.initial_value_;
  log_=c.log_;
  log_.push_back("= called.");
}


std::ostream & operator<<(std::ostream & o, Counter & c) {
  o << "Counter(" << c.initial_value_ << ")@" << c.value_;
  c.log_.push_back("<< called.");
  return o;
}

Counter operator+(Counter & a, Counter & b) {
  Counter c(a.initial_value_ + b.initial_value_);
  c.value_ = a.value_ + b.value_;
  c.log_.push_back("+ called.");
  return c;
}
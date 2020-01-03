#include "counter.h"
#include <string>
#include <vector>
#include <sstream>
using std::string; using std::vector;
using std::stringstream;
using std::ostringstream;
using std::ostream;
int Counter::value(){
  stringstream ss;
  int n2 = n1--;
  ss << "value called. Returned a " << n2;
  string result1 = ss.str();
  log_.push_back(result1);
  return n2;
}



ostream & operator<<(ostream & out,  Counter& ct){
  out << "Counter(" << ct.n2 <<")@"<<ct.n1;
  ct.log_.push_back("<< called.");
  return out;
  
}

Counter operator+(Counter&ct1, Counter&ct2){
  Counter final;
  final.n2 = ct1.n2 + ct2.n2;
  final.n1 = ct1.n1 + ct2.n1;
  return final;
}
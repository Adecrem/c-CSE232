#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::string; using std::vector;
using std::ostringstream;
using std::ostream;
class Counter{
  private:
    int n1 = 0;
    int n2 = n1;
  public:
    vector<string>log_;
    Counter() = default;
    string result = "Constructor called with a " + std::to_string(n1);
    Counter(int n1v) : n1(n1v) {log_.push_back(result);};
    int value();
    friend ostream &operator<<(ostream&,  Counter&);
    friend Counter operator+(Counter&, Counter&);
    
};

ostream& operator<<(ostream&,  Counter&);
Counter operator+(Counter&, Counter&);
#endif

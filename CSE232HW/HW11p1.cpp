#include <iostream>
#include <string>
#include "exciting.h"
using std::string;
string make_exciting(const string &s1, int n1=0){
  if (n1 == 0){
    n1 = 3;
  }
  string final = string(n1,'!');
  string finals = s1 + final;
  return finals;
}

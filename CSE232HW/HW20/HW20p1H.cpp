#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <string>
using std::string;
using std::vector;
struct ComplexNumber{
  int real=0;
  int imaginary=0;
  
  ComplexNumber()=default;
  ComplexNumber(int r, int i) : real(r), imaginary(i) {};
  ComplexNumber(string s);
  string to_string();
  
  ComplexNumber multiply(ComplexNumber);
};
void split(const string &, vector<string> &, char);

#endif

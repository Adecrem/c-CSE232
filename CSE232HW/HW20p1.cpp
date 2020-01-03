#include <iostream>
#include <string>
#include "ComplexNumber.h"
#include <sstream>
#include <vector>
#include <algorithm>
using std::string; using std::ostringstream;
using std::cin; using std::istringstream;
using std::vector; using std::cout;

string ComplexNumber::to_string(){
  ostringstream oss;
  oss << '('<< real << '+' << imaginary << 'i' << ')';
  return oss.str();
}

ComplexNumber::ComplexNumber(string s){
  vector<string>vec;
  s.erase(std::remove(s.begin(),s.end(),'i'), s.end());
  s.erase(std::remove(s.begin(),s.end(),')'), s.end());
  s.erase(std::remove(s.begin(),s.end(),'('), s.end());
  split(s,vec,'+');
  real = stoi(vec[0]);
  imaginary = stoi(vec[1]);
}


void split(const string& s, vector<string>& e, char sp){
  istringstream iss(s);
  string i;
  while(getline(iss, i, sp)){
    e.push_back(i);
  }
}

ComplexNumber ComplexNumber::multiply(ComplexNumber c2){
  ComplexNumber answer;
  answer.real = (real*c2.real)-(imaginary*c2.imaginary);
  answer.imaginary = (real*c2.imaginary)+(c2.real*imaginary);
  return answer;
}


#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <initializer_list>
using std::initializer_list;
using std::vector;
using std::ostream;
using std::cout;
template<typename T>
class EveryOther;

template<typename T>
ostream & operator<<(ostream & o, const EveryOther<T>& e);

template <class T>
class EveryOther{
  public:
  vector<T>vec_;
  EveryOther()=default;
  EveryOther(initializer_list<T> c): vec_(c){}; 
  void push_back(T var){
    vec_.push_back(var);
  }
  
  int size(){
    vector<T>vec1;
    for(size_t i = 0; i < vec_.size(); i+=2){
      vec1.push_back(vec_[i]);
    }
    return vec1.size();
  }
  friend ostream & operator<< <T>(ostream &, const EveryOther&);
  
};
  template<typename T>
  ostream & operator<<(ostream & o,const EveryOther<T>& e){
    o << "EveryOther(";
    for(size_t i = 0; i < e.vec_.size(); i+=2){
      o << e.vec_[i] << ", ";
    }
    o << ')';
    return o;
  }

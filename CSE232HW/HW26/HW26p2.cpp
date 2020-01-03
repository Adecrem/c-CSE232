#pragma once
#include <iostream>
#include <stack>
using std::stack;

template<typename t>
stack<t> reverse_stack(stack<t> &s){
  stack<t>s1;
  while(s.empty() != true){
    t top = s.top();
    s.pop();
    s1.push(top);
  }
  return s1;
};

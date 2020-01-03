#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include "student.h"
using std::vector; using std::string;

bool sorter(const Student& s1, const Student& s2){
  if (s1.name.last_name == s2.name.last_name){
    return s1.name.first_name < s2.name.first_name;
  }else{
    return s1.name.last_name < s2.name.last_name;
  }
  
}

void sort_by_name(vector<Student>& stud){
  std::sort(stud.begin(),stud.end(), sorter);
}

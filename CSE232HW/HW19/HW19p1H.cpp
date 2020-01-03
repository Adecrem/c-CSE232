#pragma once
#include <string>

struct Name {
  std::string first_name;
  std::string middle_initial;
  std::string last_name;
  
};

//bool sorter(const Name& s1, const Name& s2);

struct Student {
  Name name;
  double grade;
};

//void sort_by_name(vector<Student>& stud);

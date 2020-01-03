#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::string; using std::vector; using std::sort;

string upper(string s1){
  s1.erase(std::remove_if(s1.begin(),s1.end(), [] (char c){return !isupper(c);}),s1.end());
  return s1;
}

bool sorter(string s1, string s2){
  return upper(s1) < upper(s2);
}

void SortByUpper(vector<string> &vec) {
  sort(vec.begin(), vec.end(), sorter);
}

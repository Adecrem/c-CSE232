#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector; using std::cin; using std::string; using std::cout;
using std::out_of_range;
string Lookup(const vector<string> &words, const vector<int> &indices){
  string final;
  int indiceslen = indices.size();
  for (int i = 0; i < indiceslen; i++){
    final += words.at(indices.at(i)) + ' ';
  }
  
  return final;
}

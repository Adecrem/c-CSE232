#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using std::cout; using std::cin; using std::string; using std::vector;
using std::accumulate;
using std::multiplies;
using std::remove_if;
int Product(const vector<int> &n1) {
  return accumulate(n1.begin(), n1.end(), 1, multiplies<int>());
}

int isPositive(int final, int n1){
  return final + (n1 > 0 ? n1 : 0);
}

int PositiveSum(const vector<int> &n1) {
  return accumulate(n1.begin(),n1.end(), 0, isPositive);
}

bool is9000(int n1){return n1 <= 9000;};

void OnlyOver9000(vector<int> &n1){
  n1.erase(std::remove_if(n1.begin(),n1.end(),is9000), n1.end());
}

string findupper(string s1, string s2){
  string s3;
  if(std::all_of(s2.begin(), s2.end(), [] (char c){return isupper(c);} )){
    s3 += s2;
  };
  return s1+s3;
}

string ONLYUPPERCASE(const vector<string> &s1){
  return accumulate(s1.begin(),s1.end(),string(""), findupper);
}



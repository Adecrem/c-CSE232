#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
using std::string;
using std::vector;
using std::transform;
using std::minus;
using std::plus;
using std::multiplies;

vector<long> vector_ops(vector<long> v1, vector<long> v2, char op){
  vector<long>v3 = (v1 < v2)? v1 : v2;
  vector<long>v4 = (v2 > v1)? v1 : v2;
  switch(op)
  {
    case '+':
    {
      transform(v3.begin(), v3.end(), v4.begin(), v3.begin(), plus<long>());
      return v3;
    }
    case '-':
    {
      transform(v3.begin(), v3.end(), v4.begin(), v3.begin(), minus<long>());
      return v3;
    }
    case '*':
    {
      transform(v3.begin(), v3.end(), v4.begin(), v3.begin(), multiplies<long>());
      return v3;
    }
    default:
    {
      return vector<long>();
    }
  }
}

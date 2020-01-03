#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
#include <vector>
using std::string; using std::set; using std::vector;
using std::set_intersection;
set<string> pleasing_to_all(vector<string>& v1, vector<string>& v2, vector<string>& v3){
  vector<string>vec;
  set<string>setter;
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  sort(v3.begin(),v3.end());
  set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(vec,end(vec)));
  set_intersection(vec.begin(),vec.end(),v3.begin(),v3.end(),std::inserter(setter,end(setter)));
  return setter;
}

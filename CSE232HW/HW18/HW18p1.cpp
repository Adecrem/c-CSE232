#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include "rating.h"
using std::string;
using std::vector;
using std::accumulate;
using std::plus;
using std::cout;
double get_average_score(const vector<Rating>& ratings){
  double average = 0;
  //average = accumulate(ratings.begin(),ratings.end(), plus<double>());
  for (int i = 0; i < ratings.size(); i++){
    average+=ratings[i].score;
  }
  double finalaverage = average/ratings.size();
  return finalaverage;
}

#ifndef RATE_H
#define RATE_H

#include <vector>
#include <string>

using std::string; using std::vector;
struct Rating{
  string name;
  double score;
};
  double get_average_score(const vector<Rating>& ratings);
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
using std::cout; using std::string; using std::ifstream;
using std::fixed; using std::setprecision; using std::istringstream;
using std::endl; using std::vector; using std::sort;
int main(){
  string s1;
  double num, mini = 0, maxi = 0, total;
  vector<double>vec;
  int c = 0, numi = 0;
  ifstream file("input_data.txt");
  if (file.is_open()){
    while(getline(file,s1,' ')){
      istringstream iss(s1);
      while(getline(iss,s1)){
        istringstream ss(s1);
        while (ss >> num){
          if(numi == 0){
            mini = num;
            maxi = num;
          }
          cout << fixed << setprecision(2);
          mini = std::min(mini,num);
          maxi = std::max(maxi,num);
          vec.push_back(num);
          total += num;
          c++;
          numi++;
      }
      }
    }
  }
      cout << "data = ";
      for(double i = 0; i<vec.size(); i++){
        cout << vec.at(i) << ", ";
      }
      sort(vec.begin(),vec.end());
      double median1 = 0;
      for(double i = 0; i<vec.size(); i++){
        if (vec.size() % 2 == 0){
          median1 =((vec[(vec.size()/2)-1]+vec[(vec.size()/2)])/2);
        }else{
          median1 =(vec[vec.size()/2]);
        }
      }
      cout << "\n";
      cout << "min = " << mini << "\n";
      cout << "max = " << maxi << "\n";
      cout << "mean = " << total/c << ' '  << "\n";
      cout << "median = " << median1 << "\n";
  
}

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using std::string; using std::ifstream; using std::map; using std::cout;
map<string, int> get_name_to_score(map<string,string>scores){
  ifstream file("scores.csv");
  string in1;
  map<string,int>input;
  map<string,int>finalscore;
  while(getline(file,in1)){
    string pid = in1.substr(0,7);
    int score = std::stoi(in1.substr(8));
    input.insert({pid,score});
  }
  for(auto it = scores.begin(); it != scores.end(); it++){
    string name = it-> first;
    string pid = it -> second;
    
    auto it2 = input.find(pid);
    
    if(it2 != input.end()){
      finalscore[name]=it2->second;
    }else{
      finalscore[name]=-1;
    }
  }
  return finalscore;
}
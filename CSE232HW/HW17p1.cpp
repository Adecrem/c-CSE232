#include <iostream>
#include <vector>
#include <string>
#include <map>
using std::vector; using std::string;
using std::map;
double calculate_grade(map<string,vector<int>> & scores){
  vector<int> hw = scores["homeworks"];
  int hwp = 0;
  for(int elem : hw){
    hwp += elem;
  }
  
  vector<int> lab = scores["labs"];
  int lc = 0;
  for(int elem : lab){
    lc += elem;
  }
  
  vector<int> project = scores["projects"];
  int projpt = 0;
  for(int elem : project){
    projpt += elem;
  }
  vector<int> exam = scores["exams"];
  int exampt = 0;
  for(int elem : exam){
    exampt += elem;
  }
  int finalscore = projpt+exampt+hwp;
  int missedlab = 11-lc;
  finalscore -= (50*missedlab);
 
  
  //std::cout << "hw" << hwp << "\n";
  //std::cout << "labs" << lc << "\n";
  //std::cout << "exam" << exampt << "\n";
  //std::cout << "proj" << projpt << "\n";
  if (exampt<150){
    return 0.0;
  }
  else if (finalscore <=599){
    return 0.0;
  }
  else if(finalscore>= 600 && finalscore <=699){
    return 1.0;
  }
  else if(finalscore>=700 && finalscore <= 749){
    return 2.0;
  }
  else if(finalscore>=750 && finalscore <= 799){
    return 2.5;
  }
  else if(finalscore>=800 && finalscore<= 849){
    return 3.0;
  }
  else if (finalscore>=850 && finalscore<= 899){
    return 3.5;
  }
  else if(finalscore >=900){
    return 4.0;
  }
}


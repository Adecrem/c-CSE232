#include <iostream>
#include <string>
using std::cin; using std::cout; 
using std::string; using std::string;
int main(){
  string input;
  string mystr;
  string ban1 = "Wolverines";
  string ban2 = "University of Michigan";
  string ban3 = "Ann Arbor";
  string censor = "****";
  int ban1length = ban1.length();
  int ban2length = ban2.length();
  int ban3length = ban3.length();
  while(getline(cin,mystr)){
    if (mystr == "\n"){
      break;
    }
    input += " " + mystr;
  }
  
  size_t find1 = input.find(ban1);
  size_t find2 = input.find(ban2);
  size_t find3 = input.find(ban3);
  
  
  while (find1 != string::npos){
    find1 = input.find(ban1);
    input.replace(find1,ban1length,censor);
    find1 = input.find(ban1);
  }
  while (find2 != string::npos){
    find2 = input.find(ban2);
    input.replace(find2,ban2length,censor);
    find2 = input.find(ban2);
  }
  while (find3 != string::npos){
    find3 = input.find(ban3);
    input.replace(find3,ban3length,censor);
    find3 = input.find(ban3);
  }
  cout << input;
}
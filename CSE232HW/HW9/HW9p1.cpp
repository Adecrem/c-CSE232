#include <iostream>
#include <string>
using std::cout; using std::cin; 
using std::string;
int main(){
  string input;
  int n1;
  while (cin >> input >> n1){
    int stringnum = input.length();
    if (stringnum <= n1){
      cout << "true\n";
    }else{
      cout << "false\n";
  }
  }
}

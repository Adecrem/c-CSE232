#include <iostream>
#include <string>
#include <sstream>
using std::cin; using std::cout; using std::getline; using std::string;
using std::endl;
int main() {
  string input;
  string mystr;
  while (getline(cin,mystr)) {
    if (mystr.empty()) {
      input += "\n";
      input +=  "\t" + mystr;
    }else{
      input += mystr + "\n";
    }
  }
  cout << "\t" << input;
}

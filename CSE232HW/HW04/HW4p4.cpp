#include <iostream>
#include <string>
using std::cout; using std::cin;
using std::string; using std::getline;

int main() {
  int dgt = 0;
  string input;
  string mystr;
  while (getline(cin, mystr)) {
    if (mystr == "\n")
        break;
    input += " " + mystr;
}
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      dgt++;
  }
  }
  cout << dgt;
  return 0;
}

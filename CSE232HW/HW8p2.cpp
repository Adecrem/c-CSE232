#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cctype>
#include <string>
using std::string;

int main() {
  string line;
  std::getline(cin, line);
  for (int i = line.size() - 1; i >= 0; --i) {
    char c = line[i];
    cout << c;
  }
  cout << endl;
}

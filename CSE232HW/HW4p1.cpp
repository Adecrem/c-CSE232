#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
  char day;
  cout <<
  "What is the first letter of today's name (i.e. M for Monday)?"
  << endl;
  cin >> day;
  if (day == 'S' || day == 's') {
  cout << "It is the weekend!";
  }
  if (day == 'M' || day == 'T' || day == 'W' || day == 'F'
  || day == 'm' || day == 't' || day == 'w' || day == 'f') {
    cout << "It is just a weekday. :(";
  }
  return 0;
}

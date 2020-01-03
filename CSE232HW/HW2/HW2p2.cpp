#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
  int age;
  cout << "What is your age? \n";
  cin >> age;
  bool allowed = (4 <= age) && (age <= 10);
  if (allowed) {
    cout << "You are allowed to swim.";
  } else {
    cout << "You are not allowed. Go away.";
  }
  cout << endl;
  return 0;
}

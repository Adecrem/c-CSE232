#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void half_to_nothing(int x) {
  cout << "I have " << x << endl;
  if (x <= 1) {
    cout << "I'm done!" << endl;
    return;
  }
  half_to_nothing(x / 2);
}

int main() {
  int x;
  cin >> x;
  half_to_nothing(x);
}

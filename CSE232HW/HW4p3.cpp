#include <iostream>
#include <cmath>
using std::cin; using std::cout;

int main() {
  int small, big;
  cin >> small >> big;
  for (int i = small+1; i <= big-1; i++) {
    if (1162261467%i != 0) {
      cout << i << "\n";
    }
  }
  return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout; using std::cin; using std::setw;
using std::endl; using std::string;

int main() {
    int width;
    char pad;
    string words = ("center me!");
    int wordssize = words.size();
    cin >> width;
    cin >> pad;
    if (width > 10) {
      cout << string((width-wordssize)/2, pad) << words
      << string(round((width-wordssize)/2.0), pad) << endl;
    }
    if (width <= 10) {
      cout << words;
    }
    return 0;
}

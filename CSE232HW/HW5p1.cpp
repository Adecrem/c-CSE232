#include <iostream>
#include <string>
using std::cin; using std::cout; using std::string;
int main(){
    int count = 0;
    string input;
    cin >> input;
    for (int i = 0; i<input.length(); i++) {
        if (input[i] == '0') {
            count++;
        }
    }
    cout<<count;
}

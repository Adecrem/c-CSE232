#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using std::cout; using std::cin; using std::string;
using std::sort;
long loc_to_dec(string loc) {
    long sum = 0;
    for (size_t i=0; i < loc.length(); i++){
        int letter = loc[i] - 'a';
        int n1 = pow(2, letter);
        sum+=n1;
    }
    return sum;
}

string abbreviate(string loc){
    for (size_t i = 0; i < loc.length(); i++){
        while (loc[i] == loc[i+1]) {
            char new1 = static_cast<char>(loc[i]+1);
            loc.replace(i, 2, 1, new1);
            i--;
            sort(loc.begin(), loc.end());
        }
    }
    return loc;
}

string dec_to_loc(long dec){
    string s1;
    s1.assign (dec, 'a');
    s1 = abbreviate(s1);
    return s1;
}

long add_loc (string loc1, string loc2){
    string finals = loc1+loc2;
    string s1 = abbreviate(finals);
    long finall = loc_to_dec(s1);
    return finall;
}

//int main() {
//    string loc1;
//    int n1;
//    cout << "Give me a location string:\n";
//    cin >> loc1;
//    cout << "Give me an integer:\n";
//    cin >> n1;
//}
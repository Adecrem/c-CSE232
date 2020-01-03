#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    int userin;
    
    cout << fixed << setprecision(2);
    cin >> userin;
    double finalkm = ((5584493340)+((userin*86400)*14.33));
    double finalmile = ((3470040014)+((userin*86400)*8.90));
    double com = ((((5584493340)+((userin*86400)*14.33))
    /299792.458)/3600)*2;
    cout<< finalkm<< '\n';
    cout<<finalmile<<'\n';
    cout<<com<<'\n';
    return 0;
}

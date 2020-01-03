#include <iostream>
#include <iomanip>
using std::cin; using std::cout; using std::endl;
using std::fixed; using std::setprecision;
int main(){
  int n;
  double low, high, addval2;
  cin >> low >> high >> n;
  double addval = ((high-low)/n);
  double first=low;
  cout << fixed << setprecision(3);
  cout << '('<< low <<", "<<low+addval<<')'<<endl;
  while (addval2 < high){
    first = (first + addval);
    addval2 = addval + first;
    cout << '('<<first<<", "<<addval2<<")\n";
  }
}
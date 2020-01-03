#include <string>
using std::cin; using std::cout; using std::string; using std::runtime_error;

template <typename T>
T safe_add(T  x,T  y){
  T z = x+y;
  string zstr = std::to_string(z);
  string xstr = std::to_string(x);
  string ystr = std::to_string(y);
  int finderz = zstr.find('7');
  int finderx = xstr.find('7');
  int findery = ystr.find('7');
  if(finderz != string::npos || finderx != string::npos || findery != string::npos){
    throw runtime_error("can't add because 6+1 appears in it");
  }else{
    return z;
  }
  
}
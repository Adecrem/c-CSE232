#include <string>
#include <algorithm>
using std::string;
using std::transform;

int doubler(int x){return x*2;}

void double_array(int *arr, size_t size){
  transform(arr,arr+size, arr, doubler);
}

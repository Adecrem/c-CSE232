#include <string>
using std::string;
template<typename Type, size_t size>
size_t get_size(Type const (&arr)[size]){
  return size;
}

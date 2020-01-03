#include <stdexcept>
template<typename Type, size_t size>
Type& safe_at(Type (&arr)[size], size_t index){
  if(index>=size){
    throw std::out_of_range("");
  }else{
  return arr[index];
  }
  
}

#include <iostream>
#include "table.h"
#include <vector>
#include <random>
#include <stdexcept>
#include <sstream>
using std::ostream;
using std::random_device;
using std::vector;

Table::Table(long width, long height, long val){
    vector<long>row;
    for(long j = 0; j < width; j++){
        row.push_back(val);
    }
    for(long i = 0; i < height; i++){
        t_.push_back(row);
    }
    width_=width;
    height_=height;
}

void Table::fill_random(long lo, long hi, unsigned int seed){
      std::mt19937 generator(seed);
      std::uniform_int_distribution<long> distribution(lo,hi);
      for(long i = 0; i < height_; i++){
          for (long j = 0; j < width_; j++){
              set_value(i, j, distribution(generator));
          }
      }
      
    }
  
bool Table::set_value(unsigned int row_num, unsigned int col_num, long val){
    if (row_num < height_ && col_num< width_){
        t_.at(row_num).at(col_num)=val;
        return true;
    }else{
        return false;
    }
}

long Table::get_value(unsigned int row_num, unsigned int col_num)const{
    if (row_num < height_ && col_num< width_){
        return t_.at(row_num).at(col_num);
    }else{
        throw std::out_of_range("");
    }
}

ostream& operator<<(ostream& out, Table t){
      for(long i = 0; i < t.height_; i++){
          for(long j = 0; j < t.width_; j++){
            out << std::to_string(t.get_value(i, j)) << ',';
      }
      out << std::endl;
      }
      out << std::endl;
      return out;
    
    }

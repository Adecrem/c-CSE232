#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

		void shift_range(std::vector<int>&vec, int low, int high){
            
            std::sort(vec.begin(),vec.end());
            std::rotate(std::lower_bound(vec.begin(),vec.end(),low), std::upper_bound(vec.begin(),vec.end(),high),vec.end());
            //return vec;
		}
            
		

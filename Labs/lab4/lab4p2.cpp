#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

	std::vector<int> fibonacci(int n){	
		std::vector<int>v(n);
		if(n=0){
	    return v; 
		}else{
		  v[0]=1;
		}
		std::adjacent_difference(v.begin(),v.end(),v.begin()+1,std::plus<int>());

	}
	

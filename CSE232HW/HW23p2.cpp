#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::istringstream;
using std::cout;
using std::swap;
using std::string;
using std::vector;
using std::cin;

void swap(vector<int>&vec, int i, int j){
  int temp = vec[i];
  vec[i] = vec[j];
  vec[j] = temp;
}

int main(){
  vector<int>bubbler;
  vector<int>inserter;
  vector<int>selecter;
  string input;
  getline(cin,input);
  int n1;
  istringstream ss(input);
  while(ss>>n1){
    inserter.push_back(n1);
    bubbler.push_back(n1);
    selecter.push_back(n1);
  }
  //selection
  
  cout << "Selection Sort" << std::endl;
  for(size_t i = 0; i < selecter.size()-1; i++){
    int min = i;
    for(size_t j = i + 1; j < selecter.size(); j++){
      if(selecter[j] < selecter[min]){
        min = j; 
      }
    }
        swap(selecter, i, min);
    for(size_t k = 0; k < selecter.size(); k++){
      cout << selecter[k] << ' ';
    }
    cout << std::endl;
    
  }
  
  //inserter
  cout << "Insertion Sort" << std::endl;
  for(size_t insertstart = 0; insertstart < inserter.size(); insertstart++){
    cout << inserter[insertstart] << ' ';
  }
  cout << std::endl;
  for(size_t i = 1; i < inserter.size();i++){
    int x = inserter[i];
    int j = i-1;
    while(j>=0 && inserter[j] > x){
      inserter[j+1] = inserter[j];
      j = j-1;
    inserter[j+1] = x;
    for(size_t k = 0; k < inserter.size();k++){
      cout << inserter[k] << ' ';
    }
    cout << std::endl;
    }
  }
  //bubble
  cout << "Bubble Sort" << std::endl;
  for(size_t bubblestart = 0; bubblestart < bubbler.size();bubblestart++){
    cout << bubbler[bubblestart] << ' ';
  }
  cout << std::endl;
  for(int i = bubbler.size()-1; i >= 0; i--){
    for(int j = 0; j <= i - 1; j++){
      if(bubbler[j] > bubbler[j+1]){
        swap(bubbler, j, j+1);
      for(size_t k = 0; k < bubbler.size(); k++){
        cout << bubbler[k] << ' ';
    }
        cout << std::endl;
      }
    }
  }
  
}
//Sources provided cited below, 
//selection and bubble
//http://theoryapp.com/selection-insertion-and-bubble-sort/
//insertion
//https://en.wikipedia.org/wiki/Insertion_sort)
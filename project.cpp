#include <iostream>
using std::cout; using std::cin;
#include <string>
using std::string;
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
using std::cout; using std::cin; using std::string; using std::ifstream;
using std::vector; using std::istringstream; using std::set; using std::set_intersection;
using std::inserter; using std::map;

int main() {
    string password;
    string s1;
    int countindex= 0;
    int count = 0;
    string passwords;
    std::multimap<int, string>finder;
    cout << "Give me a password:" << std::endl;
    cin >> password;
    int pass1 = 0;
    int pass2 = 0;
    pass1 = password.length();
    int minelem = 999;
    cout << "You provided a password of " << password << std::endl;
    ifstream file("common_passwords.txt");
    if (file.is_open()) {
        while (getline(file, s1)) {
            istringstream iss(s1);
            while (iss >> passwords) {
                pass2 = passwords.length();
                if(pass1<=pass2){
                    count=(pass2-pass1);
                    for(int i = 0; i<pass1; i++){
                        if(password[i] != passwords[i]){
                            count++;
                        }
                    }
                }else if(pass1>pass2){
                    count=(pass1-pass2);
                    for(int i = 0; i<pass2;i++){
                        if(password[i]!=passwords[i]){
                            count++;
                        }
                    }
                }
                if (count<minelem){
                    minelem = count;
                }

                finder.insert(std::pair<int,string>(count,passwords));
                countindex++;

            }
        }
    }
        std::multimap<int,string>::iterator iter;
        int diff;
        vector<string>vec;
        cout << "The most similar passwords to " << password << " are:" << std::endl;
        for(iter=finder.begin() ;  iter!=finder.end() ; iter++){
            if((*iter).first == minelem) {
                 //cout <<(*iter).second << ", ";
                 vec.insert(vec.begin(), (*iter).second);
                diff = (*iter).first;
            }else{
                break;
            }

        }
        std::sort(vec.begin(),vec.end());
        for(std::size_t i = 0; i < vec.size();i++){
            cout << vec[i] << ", ";
        }

            cout << std::endl;
        cout << "All of which are " << diff  << " character(s) different." << std::endl;


}

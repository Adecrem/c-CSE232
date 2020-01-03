// Project1
// Andrew Decrem
// Professor Nahum

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using std::cout; using std::cin; using std::string;

int get_line_sum(string s1){
    int final = 0; //Initialize
    int length = s1.length(); //Find length
    for(int i = 0;i < length; i++){ //Iterate
        final += (s1[i] - '0'); //add digits
    }
    return  final; //return number
}
// Reads a string
// Determines length
// Iterates and gets sum of each digit
// Returns sum

char get_next_state(string nhood,  string rules){
    auto found1 = rules.find(nhood); // find string in rules
    int found2 = found1+7; // go to number associated with neighborhood
    char final =  rules[found2];
    if (found1 == string::npos) { // if not in
        return '0';
    }
    return final; //return
}
// Takes in two strings
// Nhood is the neighborhood
// Rules is a set of rules
// Finds the nhood in rules
// If nhood is in rules
// Will return the number associated with it
// If not in rules it will return 0


void update_line(string &line, string &rules){
    int n = 0;
    string tmp = "";
    int linelength = line.length();
    int linep1 = linelength+1; //After line length
    int linem1 = linelength-1; //Before line length
    while (n < linelength){
        if (n == 0){ //Move last to first concatenate
            line.insert(0,1,line[linem1]); //insert
        }
        if(n == 9){ //Move first to last concatenate
            line.insert(linep1,1,line[1]);
        }
        string string = line.substr(0+n,3);
        n++;
        char new1 = get_next_state(string,rules);
        if(new1 != '0') { //If line is in rules
            tmp+=new1;
        }else{
            tmp += '0'; // If its not
        }
    }
    line = tmp; //make lines equal
}
// Function takes in two strings
// First is a string second is a set of rules
// Finds the length of the string
// Finds whats before and after
// Iterate through line
// Makes string a circle
// Checks if its in rules with get_next_state
// Void function, no return




string run_cellular_automata(string rules, int n_line, string start_line){
    int n = 0;
    string newnew;
    while(n < n_line){ //Iterate
        int sum = get_line_sum(start_line); //Find sum
        string final = start_line + " sum = " + std::to_string(sum); //format
        newnew += final+"\n"; //create new lines
        update_line(start_line, rules); //update line
        n++; // add
    }
    return newnew;
}
// Loop amount of lines
// Get sum of digits
// format
// Add to string and create newline
// Update line and loop
// Iterate
// Return formatted line


int main(){
    string input;//initialize
    string rules;//initialize
    while (getline(cin, input)) { //get line including \n
        if (input == "\n"){
            break;
        }
        rules += "\n" + input;
    }
    int where = rules.find('.'); //Find where rules end
    string rulesfinal = rules.substr(1,where-2); //make substring of rules
    string therest = rules.substr(where+2); // find everything after substring
    int where2 = therest.find("\n",2);
    string num = therest.substr(0,where2); // Find string of just number
    int n1 = stoi(num); // Turn string to number
    string where3 = therest.substr(where2+1); // make string for original string
    cout << run_cellular_automata(rulesfinal,n1,where3); //output cell automata
}
// Reads lines
// Finds where rules ends ('.')
// Indices and finds the number of lines
// Indices and finds the starting line
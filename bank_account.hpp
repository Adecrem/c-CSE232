//Project 3
//Bank Statement project
//Made by Andrew Decrem
//CSE 232 Dr.Nahum
//Program that takes in bank statement and adjusts the balance accordingly
//shows interest and calculates efficiently
//able to take one command or many
#pragma once
#include <string>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <sstream>
using std::stoi;
using std::string;
using std::cout;
using std::ostringstream; using std::istringstream;

void deposit(double& balance, const double  amount){//deposit function
    balance+=amount;//adjust balance
}

bool withdraw(double& balance, const double amount){//withdraw function
    if(amount>balance) {//looking for overdraft
        return false;//boolean statement for overdraft
    }else{
        balance-=amount;//adjusting if withdraw is possible
        return true;
    }
}

void overdraft(double& balance, const double amount){
    balance-=(amount+35);//applying overdraft fee
}

double interest_for_month(const double balance,const double apr){//finding interest per month function
    double perc = apr/100;//turing apr into percentage
    double ann = perc/12;//putting it into per month
    double final = (ann*balance);//applying the percentage
    final = (int)(100*final)/100.0;//Truncate
    std::setprecision(2);//setpercision
    return final;//return final
}

void string_date_to_int_ptrs(const string date, int* year, int* month, int* day){//turn date to pointers
    string year1 = date.substr(0,4);//get year
    string month1 = date.substr(5,6);//get month
    string day1 = date.substr(8);//get day
    int year2 = stoi(year1);//turn to int
    int month2 = stoi(month1);//turn to int
    int day2 = stoi(day1);//turn to int
    *year = year2;//pointer
    *month = month2;//pointer
    *day = day2;//pointer
}

void string_date_to_ints(const string date, int &year, int &month, int &day){//date to int
    string year1 = date.substr(0,4);//get year
    string month1 = date.substr(5,6);//get month
    string day1 = date.substr(8);//get day
    int year2 = stoi(year1);//year to int
    int month2 = stoi(month1);//month to int
    int day2 = stoi(day1);//day to int
    year = year2;//setting year
    month = month2;//setting month
    day = day2;//setting day
}


int number_of_first_of_months(const string date_early,const string date_late){//number of first of months, used to calculate interest
    string yeare = date_early.substr(0,4);//find year 1
    string monthe = date_early.substr(5,6);//find month 1
    int yeare1 = stoi(yeare);//year 1 to int
    int monthe1 = stoi(monthe);//month 1 to int
    string yearl = date_late.substr(0,4);//find year 2
    string monthl = date_late.substr(5,6);//find month 2
    int yearl1 = stoi(yearl);//turn year 2 to int
    int monthl1 = stoi(monthl);//turn month 2 to int
    int final = (yearl1*12+monthl1)-(yeare1*12+monthe1);//final equation
    return final;//return
}

double interest_earned(double balance,const double apr,const string date_early,const string date_late){//interest earned function
    if(balance<=0) {//if balance is less than 0 theres no interest
        double final1 = 0;
        return final1;//return
    }
    int count=0;
    double final=0;
    double balance1=balance;//initialization
    double months = number_of_first_of_months(date_early, date_late);//call number of months
    while(count<months){
        final = balance*=(1+(apr/100)/12);//equation for apr
        balance = (int)(100.0*balance)/100.0;//truncate
        final = (int)(100.0*final)/100.0;//truncate
        count++;
    }
    double final1=final-balance1;//take away balance
    return final1;//return
}

string process_command(const string line, string &previous_date, double &balance,const double apr) {//processing commands
    int values1 = line.find('$');//find dollar sign
    string values2 = line.substr(values1 + 1);//make substr of amount
    double values4 = std::stod(values2);//turn amount to int
    double values3 = (int)(100.00*values4)/100.00;//truncate
    string current_date = line.substr(0, 10);//find current date
    if (previous_date == "") {//if no previous date, make it the current date
        previous_date = current_date;
    }

    string commandd = line.substr(11, 7);//if command is deposit
    string commandw = line.substr(11, 8);//if command is withdraw
    int number_of_first = number_of_first_of_months(previous_date, current_date);//call number of first
    ostringstream oss;//make ostringstream

    if (number_of_first > 0) {//if 1 month or more has passed
        if (commandd == "Deposit") {//if deposit and more than one month has passed
            double interest_bearned = interest_earned(balance, apr, previous_date, current_date);//interest earned
            deposit(balance, values3);//deposit
            double deposit_earned = balance + interest_bearned;//balance plus interest
            oss << "On " << current_date << ": Instructed to perform \"Deposit $" <<  values2 << "\"\nSince " << previous_date << ", interest has accrued " << number_of_first
                << " times.\n$" << std::fixed << std::setprecision(2) << interest_bearned << " interest has been earned.\n" << "Balance: " << std::fixed
                << std::setprecision(2) << deposit_earned << "\n";//Outputting with correct formatting
            balance = deposit_earned;//adjusting balance
            previous_date = current_date;//adjusting date
            return oss.str();//return
        }else if (commandw == "Withdraw") {//if withdraw and more than one month
                double interest_bearned = interest_earned(balance, apr, previous_date, current_date);//interest earned
            if (withdraw(balance, values3) == true) {//if withdraw and there is no overdraft
                double deposit_earned = balance + interest_bearned;//balance plus interest
                oss << "On " << current_date << ": Instructed to perform \"Withdraw $" << values2 << "\"\nSince " << previous_date << ", interest has accrued " << number_of_first
                    << " times.\n$" << std::fixed << std::setprecision(2) << interest_bearned << " interest has been earned.\n" << "Balance: " << std::fixed
                    << std::setprecision(2) << deposit_earned << "\n";//format output
                balance = deposit_earned;//adjust balance
                previous_date = current_date;//adjust date
                return oss.str();//return
            }
            if (withdraw(balance, values3) == false){//withdraw with overdraft
                overdraft(balance, values3);//apply overdraft
                double deposit_earned = balance + interest_bearned;//balance plus interest
                oss << "On " << current_date << ": Instructed to perform \"Withdraw $" <<  values2 << "\"\nSince " << previous_date << ", interest has accrued " << number_of_first
                    << " times.\n$" << std::fixed << std::setprecision(2) << interest_bearned << " interest has been earned.\n" << "Overdraft!\n" << "Balance: "
                    << std::fixed
                    << std::setprecision(2) << deposit_earned << "\n";//outputting with correct format
                balance = deposit_earned;//adjust balance
                previous_date = current_date;//adjust date
                return oss.str();//return
            }
        }
    } else if (commandd == "Deposit") {//deposit less than one month
        deposit(balance, values3);//deposit
        oss << "On " << current_date << ": Instructed to perform \"Deposit $" << values2 << "\"\nBalance: "
            << std::fixed << std::setprecision(2) << balance << "\n";//formatting output
        previous_date = current_date;//adjust date
        return oss.str();//return
    } else if (commandw == "Withdraw") {//withdraw less than a month
        if (withdraw(balance, values3) == true) {//if no overdraft
            oss << "On " << current_date << ": Instructed to perform \"Withdraw $" << values2 << "\"\nBalance: " << std::fixed << std::setprecision(2) << balance << "\n";
            previous_date = current_date;//formatting output
            return oss.str();//return
        }
        if (withdraw(balance, values3) == false) {//withdraw less than a month with overdraft
            overdraft(balance, values3);//call overdraft
            oss << "On " << current_date << ": Instructed to perform \"Withdraw $" << values2 << "\"\nOverdraft!\nBalance: " << std::fixed << std::setprecision(2) << balance << "\n";//formatting output
        }
        previous_date = current_date;//adjust date
        return oss.str();
    }
}

string process_commands(const string input,const double apr){//process command(s) as in multiple commands at once
    string previous_date = input.substr(0,10);//take previous date
    double balance=0;//set initial balance
    string final;//initialize string
    istringstream iss(input);//stringstream
    for(string line; getline(iss,line);){//take line by line
        final += process_command(line, previous_date, balance, apr);//append to final
    }
    return final;//return final
}

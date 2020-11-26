// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework2- problem #5

#include <iostream>
using namespace std; 

int main(){
    /* 
    1. declare variables
    2. ask for the time in seconds
    3. store input in the variable seconds 
    4. calculate time in hours minutes and seconds
    5. print time in hours minutes seconds
    */ 
    int seconds, hours, minutes, sec; 
    cout << "Enter a number of seconds: " << endl; 
    cin >> seconds; 

    hours = seconds/3600;//3600 s in an hour
    minutes = (seconds%3600)/60;//time leftover in sec divided by 60 to find the minutes
    sec = (seconds%3600)%60;

    cout << hours << " hour(s) " << minutes << " minute(s) " << sec 
    << " second(s) "<< endl; 
    return 0; 
}

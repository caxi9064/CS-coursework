// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework2- problem #3

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    /*
    1. initialize variables
    2. ask for temperature in Fahrenheit 
    3. store value in variable tempF
    4. calculate tempC
    5. display tempF and tempC
    */
    double tempF, tempC; 

    cout << "Enter a temperature in Fahrenheit: " << endl;
    cin >> tempF;
    tempC = 5.0/9.0 *(tempF - 32.0);

    cout << "The temperature " << tempF << " degrees Fahrenheit is "
    << fixed << setprecision(2) << tempC << " degrees Celsius. " << endl;
    return 0;
}
// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #1

#include <iostream>
using namespace std;
int main()
{
    int num; //declaring variables
    int sum = 0;  //initializing sum 
    cout << "Enter a positive number: " << endl;  
    cin >> num;
    
    //starts from zero and increments by two 
    // when the last value is reached loop terminates
    for (int i = 0; i <= num ; i= i + 2)
    {
        sum += i ;
    }
    cout << "Sum: " << sum << endl; 
}

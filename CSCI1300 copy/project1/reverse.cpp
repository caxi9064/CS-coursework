// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #1
#include<iostream>
using namespace std;   

/**
function to find the reverse of the input string
parameter: string input 
*/
void reverse(string str)
// definition of reverse function
{   //int n = str.length();
    for (int i=str.length()-1; i >=0; i--)
    {   
        cout << str[i];
    }
}
int main (void)
{
    string str1 = "Hello World";
    reverse(str1); //function call 
    cout << endl;
    string str2 = "CSCI 1300: Starting Computing";
    reverse(str2);
}
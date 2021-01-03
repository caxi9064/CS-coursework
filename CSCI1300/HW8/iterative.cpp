// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326- Sanskar Katiyar
// Homework 8 - Problem # 3

#include <vector>
#include <iostream>
#include <string>
using namespace std;
string decimalToBinaryIterative(int num);
int main()
{
    cout << decimalToBinaryIterative(5) << endl;
}

/*
function converts decimal value to binary number 
parameter: non-negative integer
return: string of binary numbers
*/
string decimalToBinaryIterative(int num)
{
    vector<int> v;
    string s= ""; 
    int binary;
    
    while(num != 0)
    {
        binary = num%2; 
        v.insert(v.begin(), binary);
        num = num/2;
    }
    binary= num%2;
    v.insert(v.begin(), binary);

    for (int i = 0; i < v.size(); i++)
    {
        s += to_string(v[i]);
    }
        
    return s;
}
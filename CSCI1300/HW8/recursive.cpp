// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326- Sanskar Katiyar
// Homework 8 - Problem # 4
#include <iostream>
#include <string>
using namespace std;
string decimalToBinaryRecursive (int num);
int main()
{
    cout << decimalToBinaryRecursive(5);
}
/*
function converts decimal value to binary number using recursion
parameter: non-negative integer
return: string of binary numbers
*/
string decimalToBinaryRecursive (int num)
{
    string binary;

    binary = to_string(num%2);
    num = num/2;

    if (num == 0) 
    {
        return binary;
    }
    else return decimalToBinaryRecursive(num) + binary; 
}
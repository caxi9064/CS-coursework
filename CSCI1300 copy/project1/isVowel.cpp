// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #2
#include<iostream>
using namespace std;   
/*
function returns true if character is a vowel 
parameter: character input
return: true or false
*/ 

bool isVowel(char ch)
//definition of vowel 
{
    if (ch == 'a' || ch == 'A' || ch =='e'|| ch == 'E'|| ch == 'i'|| ch == 'I' || ch == 'o' 
    || ch == 'O'|| ch =='u'|| ch == 'U')
    return true; //bool true is 1
    else return false; //bool false is 0

}
int main()
{
    cout << isVowel('u') << endl;//function call 
    cout << isVowel ('z') << endl;
}
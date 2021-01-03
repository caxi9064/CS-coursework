// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #3

#include<iostream>
#include <string>
using namespace std;   
/*
function returns true if character is a vowel 
parameter: character input
return: true or false
*/ 
bool isVowel(char ch)// comes before function numVowels
{
    if (ch == 'a' || ch == 'A' || ch =='e'|| ch == 'E'|| ch == 'i'|| ch == 'I' || ch == 'o' 
    || ch == 'O'|| ch =='u'|| ch == 'U')
    return true; //bool true is 1
    else return false; //bool false is 0
}
/*
function returns number of vowels in the string 
parameter: string input
return: int value 
*/
int numVowels(string str)
{
    int result=0; 
    for (int i = 0; i <= str.length(); i++)
    {
    if (isVowel(str[i]) == true)
     result ++;
    }
    return result; 
}

int main()
{
    cout <<  numVowels("aaa") << endl; //calls the function numVowels and outputs the results
    cout <<  numVowels("Do you want a muffin") << endl;
    cout <<  numVowels("I hope the boat will float") << endl;
    return 0; 
}
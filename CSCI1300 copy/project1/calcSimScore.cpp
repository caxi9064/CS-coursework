// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #4
#include<iostream>
#include <string>
using namespace std;   

/*
function to calculate similarity score of two sequences of DNA
parameters: sequence 1 , sequence 2
return: similarity score 
*/
double calcSimScore (string s1, string s2)
//if both sequences are equal in length 
//for each character in string 1 find the number of matches with string 2
//calculate the hamming distance and return similarity score 
//else return 0
{
    double hammingDistance = 0;
    double simScore;
    if (s1.length() == s2.length() && s1.length()!= 0) 
    {
        for (int i=0; i <= s1.length(); i++)
        {
            if (s1[i] != s2[i])
            hammingDistance++;
        }
        return simScore= (s1.length()-hammingDistance)/ s1.length(); 
    }
    else
    return 0;
}

int main()
{
    cout << calcSimScore ("ATGC", "ATGA") << endl;
    cout << calcSimScore ("CCDCCD", "CCDCCD") << endl;
    cout << calcSimScore ("ATG", "GAT") << endl;
    cout << calcSimScore ("ACCDT", "ACT") << endl; 
    return 0; 
}
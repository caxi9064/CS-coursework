// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Homework 7 - Extra credit problem #1
#include <iostream>
#include <string>
using namespace std;

int keywordCipher(string message, string key, bool flag);
string findNewKey(string key);
string encoded(string newKey);

int main()
{
    string s1= "BATMAN";
    string s2= "FEATHER";
    bool encrypt=true ;
    bool decrypt= false;
   
    string newKey= findNewKey(s2);
    string encodedString= encoded(newKey);
}

string findNewKey(string key)
{
    int count=0;
    string temp = "";
    for (int i = 0; i<key.length(); i++)//removing duplicate letters in key
    {
        for (int j = 0; j<i;j++)
        {
            if (key[i]!=key[j])
            {
                count++;
            }
            else//if duplicate is found
            {
                key[i]=key[count];//replace duplicate with the next character
            }
        }
    }
    return key;
}

string encoded(string newKey)
{
    int count = 0;
    string encodedString="";
    for (int i = 0; i< newKey.length();i++)//removing duplicates in remaining letters
    { 
        for (int j = 80; j>65;j--)
        { 
            if (int(newKey[i])!= j)
            {
                count ++;
            }
            else
            newKey[i]= newKey[];
        }
    
    }
    // return encodedString;
    
    return 0;
}

/*
this function return the encrypted string
parameters: a message, key, flag
return: 

int keywordCipher(string message, string key, bool flag)
{
   
    // for (int i = key.length(); i<26; i++)//appending letters of alphabet
    // {
    //     ch = char();
    //     key += ch;

    // }

    // if (flag == true)//encrypt
    // {


    // }
    // else//decrypt

}
*/
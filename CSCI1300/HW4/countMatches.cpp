// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #4

#include <iostream>
#include <string>
using namespace std;
int main()
{  
    string str1;
    string str2; 
   
    cout << "Enter the search string: " << endl;
    cin >> str1; 
    cout << "Enter the substring to be searched: " << endl; 
    cin >> str2; 

    int counter=0 ;

    //starts from zero 
    //loop terminates when last character is reached
    for (int position=0; position < str1.length(); position++)
    {
        if (str1.substr(position, str2.length()) == str2)
        {
            counter ++;//increase count by 1
        }
    }
    cout << "Number of occurrences: " << counter << endl; 
}
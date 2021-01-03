// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework5- problem #1

#include<iostream>
#include <string>
using namespace std;   
int main ()
{
    double temps[10];//array size is 10
    for (int i=0; i<10; i++)
    {
        temps[i]= -459.67;//initializing values to -459.67
        cout << temps[i] << endl; 
    }
    cout << endl;

    for (int i=0; i<5;i++)
    {
        string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
        cout << colors[i] << endl;
    }
    cout << endl; 

    int sequence[100];
    for (int i=0; i<100; i++)
    {
        sequence[i]= i+1;//initializing each element 
        cout << sequence[i]<< endl;
    }  
    cout << endl; 

    char letters[52];
    for (int i = 0; i<26; i++)
    {

        letters[i] = 65 + i; //uppercase characters
        letters[i+1] = 97 + i; //lower case characters are printed in the second column 
        cout << letters[i] << " " << letters[i+1] << endl; 
    }
}
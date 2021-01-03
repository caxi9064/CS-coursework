// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework5- problem #5

#include<iostream>
#include <string>
#include <iomanip>
using namespace std; 
int split(string input, char separator, string arr[], int size);

int main()
{
    string arr[10];
    int num = split("cow/chicken/fish/test", '/', arr , 10);
    for (int i =0; i< num; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

/*
function to find number of pieces in a string and fill array with those string pieces
parameters: string, separator, arr where string pieces are stored, size of array
return: number of pieces string is split into
*/
int split(string input, char separator, string arr[], int size)
{ 
    if (input == "")//if string is empty return 0
    {
        return 0;
    }

    int index = 0;
    int j = -1;
    int i=0;
    for (i = 0; i<input.length(); i++)
    {   
        if (input[i] == separator)
        {
            int length= i-j;
            if (index == size)
            {
                return -1;
            }
            arr[index] = input.substr(j+1,length-1);//j+1 because starts at 0
            index++;  
            j=i;//setting first position of substring to position of the last delimiter 
        }
    } 
    //there is no delimiter at the end so it has to be outside loop
    int length= i-j;//length of string - last position 
    arr[index] = input.substr(j+1,length);
    index++;//increments outside loop

    return index;//returns number of pieces in string
}

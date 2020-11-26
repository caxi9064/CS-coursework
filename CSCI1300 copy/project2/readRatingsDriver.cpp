// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Project 2 - Problem # 7
#include "user.h"
#include <iostream>
#include <string>
#include <fstream>
int split(string input, char separator, string arr[], int size);
int readRatings(string filename, User users[], int numUsersStored, int usersArraySize, int maxCol);

int main()
{   
    const int usersArraySize= 10;
    const int maxCol = 50;
    User users[usersArraySize];
    int numUsersStored = 0;
    cout << readRatings("ratings.txt", users, numUsersStored, usersArraySize, maxCol);
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
    return index;
}

/*
Function reads the txt file and prints user ratings 
Parameters: filename, array of user objects, num of users stored, capacity of users array, max columns 
Return: total number of users in the array 
*/
int readRatings(string filename, User users[], int numUsersStored, int usersArraySize, int maxCol)
{
    ifstream myFile;
    myFile.open(filename);
    string line;
    string array[51];//there are actually 51 elements because username is included
    
    if (numUsersStored >= usersArraySize)
    {
        return -2; 
    }
    if (myFile.fail())
    {
        return -1;
    }

    while (getline(myFile, line)&& numUsersStored < usersArraySize)
    {
        if (line != "")
        {
            line = line +',';
            int num = split(line, ',', array, 50);//storing the elements in each line in array 
            
            users[numUsersStored].setUsername(array[0]);//setting username of each object in array 
            // cout << users[numUsersStored].getUsername() << endl;
        
            for (int i = 0; i < num-1; i++)
            {
                int x = stoi(array[i+1]);//converting value from string to int, skips the user name
                users[i].setRatingAt(i,x);//setting rating 
            }
            numUsersStored++;
        }
    }
    return numUsersStored; 
}

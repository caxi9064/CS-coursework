// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Project 2 - Problem # 9

#include "user.h"
#include <iostream>
#include <string>
using namespace std;
int addUser(string username, User users[], int numRatings, int numUsersStored, int usersArrSize);
string getLowercase(string title);
int main()
{
    int usersArrSize = 100;
    int numRatings = 50;
    User users[usersArrSize];
    int numUsersStored = 50;
    int val = addUser("Knuth", users, numRatings, numUsersStored, usersArrSize);
    users[50].setUsername("Knuth");
    cout << users[50].getUsername();
    cout << users[50].getRatingAt(3);
}
/*
converts upper case to lower case 
parameters: title of book
return: title in all lowercase characters 
*/
string getLowercase(string title)
{
    string title1 = "";
    for (int i = 0; i<title.length(); i++)
    {
        title1 += tolower(title[i]);
    }
    return title1;
}
/*
function adds a user to the user array if the user does not exist and sets num of ratings to zero 
parameters: username, users array, number of ratings, number of users stored, capacity of users array
return: new total number of users
*/
int addUser(string username, User users[], int numRatings, int numUsersStored, int usersArrSize)
{
    //check if user already exists 
    //if user does not exist then
    //  add user to array
    //  set num ratings to zero 
    
    if (numUsersStored >= usersArrSize)
    {
        return -2;
    }
    if (username == "")
    {
        return -1;
    }
    for (int i = 0; i<numUsersStored; i++)
    {//checking if user already exists
        if(getLowercase(username) == getLowercase(users[i].getUsername()))
        {
            return -1;
        }
    }
    int newTotal= numUsersStored+1;//updating total number of users 
    int arr[50]={};//initializing array
    for (int j = 0; j<50;j++)
    {
        arr[j]=0;//setting all values in ratings array to zero
    }
    User(username, arr, numRatings); 
    users[numUsersStored].setUsername(username);//setting the username of added user 

    return newTotal; 
}
// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Project 2 - Problem # 6
#include "user.h"
#include <iostream>
#include <string>

using namespace std;

User::User() //default constructor
{
    username = ""; 
    numRatings=0;
    for (int i = 0; i<50; i++)
    {
        ratings[i]=0; //setting all values in ratings array to zero
    }

}
User::User(string s, int arr[], int num)//parameterized constructor
{
    username = s;
    for (int i = 0; i<num;i++)
    {
        ratings[i] = arr[i];//initializing array 
    }
    
    if (num < size)
    {
    numRatings= num;
    }
} 

void User::setUsername(string s)
{
    username = s; 
}    //assigns username value of input string

bool User::setRatingAt(int index, int value)
{//set rating at specified index, return bool true if successful
    if (index< 50 && index>=0 && value <=5 && value >=0)
    {
        ratings[index]= value;
        return true;
    }
    else return false;
}

void User::setNumRatings(int num)
{
    numRatings=num; //assign num ratings value of input 
}  

string User::getUsername () const
{
    return username;//returns username as string
} 

int User::getRatingAt(int index)const
{
    if (index >=50 ||index <0)
    return -1;
    else
    return ratings[index];
} //returns rating stored at index

int User::getNumRatings()const
{
    return numRatings;////returns the number of ratings 
}

int User::getSize() const
{
    return size;
}
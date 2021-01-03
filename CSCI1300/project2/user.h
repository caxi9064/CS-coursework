// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Project 2 - Problem # 6

#ifndef USER_H
#define USER_H
 
#include <string>
#include <iostream>
using namespace std;

class User 
{
    public:
    User(); //default constructor
    User(string s, int arr[], int num);//parameterized constuctor

    //setters
    void setUsername(string s);//assigns username value of input string
    bool setRatingAt(int index, int value);//set rating at specified index
    void setNumRatings(int num);//assign num ratings value of input 
   
    //getters
    string getUsername() const; //returns username as string
    int getRatingAt(int index)const; //returns rating stored at index
    int getNumRatings()const; //returns the number of ratings 
    int getSize() const; // returns size 

    private: 
    string username;
    static const int size = 50;
    int ratings[50];
    int numRatings; 

};

#endif
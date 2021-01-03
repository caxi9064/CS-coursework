// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Project 2 - Problem # 10
// partner - Jules Geneser

#include "user.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string getLowercase(string title);
int getUserStats(string username, User users[], int numUsersStored, int numBooksStored);

int main()
{
User users[3];

//Setting username and ratings for User1
users[0].setUsername("User1");
users[0].setNumRatings(3);
users[0].setRatingAt(0,1);
users[0].setRatingAt(1,4);
users[0].setRatingAt(2,2);

//Setting username and ratings for User2
users[1].setUsername("User2");

//Setting username and ratings for User3
users[2].setUsername("User3");
users[2].setNumRatings(3);
users[2].setRatingAt(0,0);
users[2].setRatingAt(1,0);
users[2].setRatingAt(2,0);

cout<<"Function's returned value: "<<getUserStats("User1", users, 3, 3)<<endl;
cout<<"Function's returned value: "<<getUserStats("User2", users, 3, 3)<<endl;
cout<<"Function's returned value: "<<getUserStats("User4", users, 3, 3)<<endl;
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
this function prints the average rating if the user is found
parameters: username, users array, number of users stored, number of books stored
return: int value
*/
int getUserStats(string username, User users[], int numUsersStored, int numBooksStored)
{
    // if user is found
    //  compute average rating
    //  if numBooksStored< numRatings
    //  pick lesser value
    //  print number of books rated for user
    //  check if user has not rated any books
    // else if user is not found
    //  print user not found
    //  return -3

    int k =-1;
    double total = 0;
    int booksRated = 0;

    for (int i = 0; i<numUsersStored; i++)
    { 
        if(getLowercase(username) == getLowercase(users[i].getUsername()))//if user is found
        {
            k=i;//setting index for user 
        }
    }
    if (k == -1)
    {
        cout << username << " does not exist. " << endl;
        return -3;
    }
    for (int j = 0; j<numBooksStored;j++)
    {
        if (users[k].getRatingAt(j) != 0)//if rating exists
        {
            booksRated++;
        }
        total += users[k].getRatingAt(j);//computing total for books rated
    }
        double averageRating = total/booksRated;//computing average rating
    
    if (booksRated==0)//if no ratings exist for user 
    {
        cout << username << " has not rated any books." << endl;
        return 0;
    }   
    else if (averageRating != 0)
    { 
        cout << username << " rated " << booksRated << " books \n" ; 
        cout << username << "'s average rating was " << fixed << setprecision(2) << averageRating << endl;
    }
    return 1; 
}

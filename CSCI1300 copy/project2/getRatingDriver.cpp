// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Project 2 - Problem # 8
// partner - Jules Geneser

#include "user.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;
string getLowercase(string title);
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks);
int main()
{
    Book books[2];

    books[0].setTitle("Three Men In A boat") ;
    books[1].setTitle("Title2") ;
    // cout << "Book titles: " << books[0].getTitle() << books[1].getTitle() << endl;

    books[0].setAuthor("author1") ;
    books[1].setAuthor("author2") ;
    // cout << "Authors: " << books[0].getAuthor() << books[1].getAuthor() << endl;
 
    User users[2];

    users[0].setUsername("bonnie") ;
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);

    users[1].setUsername("user2") ;
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);

    cout<<getRating("bOnNIe", "Three Men In a Boat", users, books, 5, 4)<<endl;//test values 
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
If both the username and book title are found then the function will find the rating value given by the user 
Parameters: username, title of book, array of user objects, array of book objects, users stored, books stored
Return: the rating value that user gave for book
*/
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks)
{   
    //for each user
    //  getLowercase 
    //  if the username is found
    //      count++
    //for each book 
    //  if book title matches   
    //  get rating at index
    int x;
    int indexUsers = -1;
    int indexBooks = -1;
    
    for (int i = 0; i<numUsers; i++)
    {
        if(getLowercase(username)== getLowercase(users[i].getUsername()))
        {
            indexUsers=i;//setting index of users array
        }
    }
    for (int j = 0; j<numBooks; j++)
    {
        if (getLowercase(title) == getLowercase(books[j].getTitle()))
        {
            indexBooks=j;//setting index book rating 
        }
    }
    if (indexUsers!=-1 && indexBooks!=-1)
    {
        x = users[indexUsers].getRatingAt(indexBooks);//getting rating at index
    }
    else
    return -3;

    return x;//return rating
}
#include "Book.h" 
#include <iostream>
#include <string>

using namespace std;

Book::Book()//default constructor- set values to empty strings
{
    title = "";
    author = "";
    genre = "";
}

Book::Book(string s1,string s2, string s3)//parameterized constructor
{ 
    title = s1;
    author = s2;
    genre = s3;
}
//setting values for the title, author, and genre to the input
void Book::setTitle(string s1)
{
    title = s1;
}
void Book::setAuthor(string s2)
{
    author = s2;
}
void Book::setGenre(string s3)
{
    genre = s3;
}

string Book::getTitle()const 
{
    return title;//returns title as a string
}
string Book::getAuthor()const
{
    return author; //returns author as a string
}
string Book::getGenre()const
{
    return genre;//returns genre 
}

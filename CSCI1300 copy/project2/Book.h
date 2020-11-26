#include <iostream>
#include <string>

#ifndef BOOK_H
#define BOOK_H

using namespace std;
class Book
{
    public:
        Book(); //default constructor
        Book(string s1, string s2, string s3);//parameterized constructors

        void setTitle(string s1); 
        void setAuthor(string s2);
        void setGenre(string s3);

        string getTitle()const;//returns title as a string
        string getAuthor()const;//returns author as a string
        string getGenre()const;//returns genre as string
        

    private:
        string title;
        string author;
        string genre;

};

#endif
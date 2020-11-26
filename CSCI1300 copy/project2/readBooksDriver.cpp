// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Homework 7 - Problem # 4

#include "Book.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
int split(string input, char separator, string arr[], int size);
int readBooks (string fileName, Book books[], int numBooksStored, int booksArrSize);
int main()
{

    Book books[10]= {};//array of objects 
    readBooks ("books.txt", books, 0 , 10);


    cout <<books[0].getAuthor() << endl;
    cout << books[1].getAuthor() << endl;

    cout << books[0].getTitle() << endl;
    cout << books[1].getTitle() << endl;

    cout << books[0].getGenre() << endl;
    cout << books[1].getGenre() << endl;
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
this function will fill an array of Book objects with title, author, and genre
parameters: name of file to be read, array of Book objects, num of books currently stored, capacity of books array
return: total number of books 
*/
int readBooks (string fileName, Book books[], int numBooksStored, int booksArrSize)
{
    ifstream myFile;
    myFile.open(fileName);

    string line;
    string arr[50];//array that stores strings from line

    if (numBooksStored >= booksArrSize) //book stored in array cannot exceed the size
    return -2;
    else if (myFile.fail())//checking if file failed to open
    return -1;

    if (myFile.is_open())//checking if file failed to open
    {
        while (getline(myFile, line) && numBooksStored < booksArrSize)//getting line from file
        {
            if (line != "")//skipping empty lines
            {
                int num = split (line, ',', arr, 50);

                Book b = Book (arr[1], arr[0], arr[2]);//declaring object of b and constructor
                books[numBooksStored]= b;
        
                numBooksStored++;
            }
        }
        return numBooksStored;
    }
   else return -1;
}
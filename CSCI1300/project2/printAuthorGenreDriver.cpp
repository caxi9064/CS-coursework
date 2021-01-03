// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Project 2 - Problem # 5

#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int readBooks (string fileName, Book books[], int numBooksStored, int booksArrSize);
int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored);

int main()
{
    Book books[50];
    int numBooksStored = 0;
    int i =readBooks ("books.txt", books, numBooksStored, 50);
    numBooksStored= i;

    cout << printAuthorGenre("science fiction", 'D', books, numBooksStored);
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
                line = line + ',';
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

/*
function prints all books of a genre if the first character of author name matches a given character
parameters: genre, character, array of book objects, number of books stored in array
return: return num of books that match criteria
*/
int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored)
{
    //for each object in the array
    // if genre matches 
    //  getAuthor()
    //  if first character of author name matches 
    //display each book 
    // else cout no titles found
    //return count 

    int count = 0;
    string array [10];
    string bookNames[50];
    string authorNames[50];
    for (int i = 0; i<numBooksStored; i++)
    {
        string bookGenre= books[i].getGenre();

        if (genre == bookGenre)
        {
            string author= books[i].getAuthor();
            if  (author[0]== authorFirstLetter)
            {
                bookNames[count]= books[i].getTitle();//storing name of book in array bookNames
                authorNames[count]= books[i].getAuthor();//storing name of author in authorNames
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No titles found for this genre-author pair." << endl;
        return 0;
    }
    else 
    {
        cout << "Here is a list of books that match this genre-author pair: " << endl;
        for (int j = 0; j < count; j++)
        {
            cout << bookNames[j] << " by " << authorNames[j] << endl;
        }
    }
    return count;
}

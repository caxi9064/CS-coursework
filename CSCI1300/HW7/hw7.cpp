// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Homework 7 - Problem # 6

#include <iostream>
#include <string>
#include <fstream>
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


Book::Book()
{
    title = "";
    author = "";
    genre = "";
}

Book::Book(string s1,string s2, string s3)
{
    title = s1;
    author = s2;
    genre = s3;
}

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
    return title;
}
string Book::getAuthor()const
{
    return author;
}
string Book::getGenre()const
{
    return genre;
}

int split(string input, char separator, string arr[], int size);
int readBooks (string fileName, Book books[], int numBooksStored, int booksArrSize);
void printAllBooks(Book arr[], int numOfBooks);

int main()
{
    Book books[50]= {};//array of objects 
    string fileName;
    int userInput;

    int numBooks = 0;//declaring variables
    int result; 

while (userInput != 3)
    {
    cout << "======Main Menu=====\n" <<"1. Read books\n" << "2. Print all books\n" << "3. Quit" << endl;
    cin >> userInput;
    
        switch (userInput)
        {   
            case 1: 
            {
                cout << "Enter a book file name: " << endl;
                cin >> fileName;
                result = readBooks(fileName, books, numBooks, 50);//stores current num of books stored in result
                //numBooks will get updated each time

                  if (result == -1)
                
                { 
                    cout << "No books saved to the database." << endl;break;
                }

                else if (result == -2)
                {//need break statement and brackets 
                    cout << "Database is already full. No books were added."  << endl;break;
                }
                else 
                {
                    if (result == 50)//hidden testcase if array is full then 
                    {
                        numBooks=result;//reassigning values to variables numBooks
                        cout << "Database is full. Some books may have not been added." << endl; break;
                    }
                    else
                    {
                        numBooks = result;
                        cout << "Total books in the database: " << numBooks << endl; break;  
                    }   
                }
            }
            case 2: 
            {
                printAllBooks(books, numBooks);break;//calling print all books function
            }
            case 3: cout << "Good bye!" << endl; break;
            default: cout << "Invalid input." << endl; break;
        }
        
    }
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

                Book b = Book (arr[1], arr[0], arr[2]);//declaring object 
                books[numBooksStored]= b;
        
                numBooksStored++;
            }
        }
        return numBooksStored;
    }
   else return -1;
}

/*
This function finds and prints the title and author of book
parameters: books array, num of books currently stored
does not return anything
*/

void printAllBooks(Book books[], int numBooksStored)
{
    if (numBooksStored <= 0)
    cout << "No books are stored" << endl;
    else 
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i< numBooksStored; i++)
            {
                cout << books[i].getTitle() << " by "; 
                cout << books[i].getAuthor() << endl;
            }
    }
}

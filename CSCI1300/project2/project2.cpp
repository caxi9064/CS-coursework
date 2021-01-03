// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 – Sanskar Katiyar
// Project 2 - Problem # 11
// partner - Jules Geneser
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
    const int size = 50;
    int ratings[50];
    int numRatings; 

};

User::User() //default constructor
{
    username = ""; 
    numRatings=0;
    for (int i = 0; i<50; i++)
    {
        ratings[i]=0; //setting all values in ratings array to zero
    }

}
User::User(string s, int arr[], int num)//parameterized constuctor
{
    username = s;
    for (int i = 0; i<num;i++)
    {
        ratings[i] = arr[i];//initializing array with input values
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

int split(string input, char separator, string arr[], int size);
string getLowercase(string title);
int readBooks (string fileName, Book books[], int numBooksStored, int booksArrSize);
void printAllBooks(Book arr[], int numOfBooks); 
int countGenre(string genre, Book books[], int numBooksStored);
int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored);
int addUser(string username, User users[], int numRatings, int numUsersStored, int usersArrSize);
int readRatings(string filename, User users[], int numUsersStored, int usersArraySize, int maxCol);
int getRating(string username, string title, User users[], Book books[], int numUsers, int numBooks);
int getUserStats(string username, User users[], int numUsersStored, int numBooksStored);

int main()
{
    static const int booksArraySize = 50; 
    static const int usersArraySize = 100;
    Book books[booksArraySize];
    User users[usersArraySize];
    //declaring variables
    string fileName, genre, username, bookTitle, firstLetter, inputString;
    int result, numBooksInGenre, numFilteredBooks, userInput;
    int numBooks = 0;
    int numRatings = 50;
    int numUsersStored = 0;
    int maxCol = 50;
   
    while (userInput != 9)
    {
        cout << "Select a numerical option:\n" << "======Main Menu=====\n" << "1. Read books from file\n" << "2. Print all books\n" << "3. Book-count by genre\n" <<
        "4. Filter books by genre, author\n" << "5. Add user\n" << "6. Read ratings\n" << "7. Get rating\n" << "8. Get user statistics\n" <<
        "9. Quit" << endl;

        getline(cin, inputString); 
        userInput= stoi(inputString); //typecasting input as integer

        switch(userInput)
        {
            case 1: //read books from file
            {
                cout << "Enter a book file name:" << endl;
                getline(cin, fileName);
                result = readBooks(fileName, books, numBooks, booksArraySize);//stores current num of books stored in result
                //numBooks will get updated each time

                if (result == -1)
                { 
                    cout << "No books saved to the database." << endl;break;
                }
                else if (result == -2)
                {
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
            case 2: //print all books in database 
            {
                printAllBooks(books, numBooks); break;
            }
            case 3: //print book count by genre
            {
                cout << "Enter the genre: \n";
                getline (cin, genre);
                numBooksInGenre = countGenre(genre, books, numBooks); 
                cout << "Total " << genre << " books in the database: " << numBooksInGenre << endl; break;
            }
            case 4://print total number of books filtered by author/genre
            {
                cout << "Enter the genre: \n";
                getline(cin, genre);
                cout << "Enter first char of author name: \n";
                getline (cin, firstLetter); 
                numFilteredBooks= printAuthorGenre(genre, firstLetter[0], books, numBooks);
                cout << "Number of titles found for this filter: " << numFilteredBooks << endl;break;
            }
            case 5://adding a user 
            {
                cout << "Enter a user name: \n";
                getline(cin, username);
                result= addUser(username, users, numRatings, numUsersStored, usersArraySize);
                if (result == -2)
                {
                    cout << "Database is already full. User cannot be added." << endl; break;
                }
                if (result == -1)
                {
                    cout << "User already exists or the username is empty." << endl; break;
                }
                else 
                {
                    numUsersStored = result;
                    cout << "Welcome, " << username << "!" << endl; break;
                }
            }
            case 6://read ratings file
            {
                cout << "Enter the ratings file name:\n";
                getline(cin, fileName);
                result= readRatings(fileName, users, numUsersStored, usersArraySize, maxCol);
                if (result == -1)
                {
                    cout << "No ratings saved to the database." << endl; break;
                }
                if (result == -2)
                {
                    cout << "Database is full. No ratings were added." << endl; break;
                }
                else 
                {
                    if (result == usersArraySize)
                    {
                        cout << "Database is full. Some ratings may have not been added." << endl; break;
                    }
                    else 
                    {
                        numUsersStored = result;
                        cout << "Total users in the database: " << numUsersStored << endl; break;
                    }
                }
            }
            case 7: //get book rating
            {
                cout << "Enter a user name: \n";
                getline(cin, username);
                cout << "Enter a book title: \n";
                getline(cin, bookTitle); 
                result = getRating(username, bookTitle, users, books, numUsersStored, numBooks);
                if (result == -3)
                {
                cout << username << " or " << bookTitle << " does not exist." << endl; break;
                }
                else 
                cout << username << " rated " << bookTitle << " with " << result << endl; break;
            }
            case 8://get user stats
            {
                cout << "Enter a user name: \n";
                getline(cin ,username);
                getUserStats(username, users, numUsersStored, numBooks);break;
            }   
            case 9: cout << "Good bye!" << endl; break;
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
/*
This function counts the books in a given genre
Parameters: genre, array of books, books currently in the array
Return: count of books matching the given genre
*/
int countGenre(string genre, Book books[], int numBooksStored)
{
    int count =0;

    for (int i = 0; i<numBooksStored; i++)
    {
        string bookGenre= books[i].getGenre(); 

        if (genre == bookGenre)
        {
            count++;
        }
    }
    return count;
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
    {
        if(getLowercase(username) == getLowercase(users[i].getUsername()))
        {

            return -1;
        }
    }
    int newTotal= numUsersStored+1;//updating total number of users 
    int arr[50]={};//initializing array
    for (int j = 0; j<50;j++)//setting all values in ratings array to zero
    {
        arr[j]=0;
    }
    User(username, arr, numRatings); 
    users[numUsersStored].setUsername(username);//setting the username of added user 

    return newTotal;
}
/*
Function reads the txt file and prints user ratings 
Parameters: filename, array of user objects, num of users stored, capacity of users array, max columns 
Return: total number of users in the array 
*/
int readRatings(string filename, User users[], int numUsersStored, int usersArraySize, int maxCol)
{
    ifstream myFile;
    myFile.open(filename);
    string line;
    string array[51];//there are actually 51 elements because username is included
    
    if (numUsersStored >= usersArraySize)
    {
        return -2; 
    }
    if (myFile.fail())
    {
        return -1;
    }

    while (getline(myFile, line)&& numUsersStored < usersArraySize)
    {
        if (line != "")
        {
            line = line +',';
            int num = split(line, ',', array, 50);//storing the elements in each line in array 
            
            users[numUsersStored].setUsername(array[0]);//setting username of each object in array 
            // cout << users[numUsersStored].getUsername() << endl;
        
            for (int i = 0; i < num-1; i++)
            {
                int x= stoi(array[i+1]);//converting value from string to int, skips the user name
                users[i].setRatingAt(i,x);
            }
        
            numUsersStored++;
        }
    }
    return numUsersStored; 
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
    int countUser = 0;
    int countBooks = 0;
    
    for (int i = 0; i<numUsers; i++)
    {
        string username1= getLowercase(users[i].getUsername());
        if(getLowercase(username)== username1)
        {
            countUser++;
        }
    }
    for (int j = 0; j<numBooks; j++)
    {
        if (getLowercase(title) == getLowercase(books[j].getTitle()))
        {
            countBooks++;
        }
    
    }
    if (countUser!=0 && countBooks!=0)
    {
        x = users[countUser].getRatingAt(countBooks);
        return x;
    }
    
    else
    return -3;
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

    int k =0;
    double total = 0;
    int booksRated = 0;
    
    for (int i = 0; i<numUsersStored; i++)
    { 
        if(getLowercase(username) == getLowercase(users[i].getUsername()))//if user is found
        {
            k++;
        }
    }
    if (k == 0)
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

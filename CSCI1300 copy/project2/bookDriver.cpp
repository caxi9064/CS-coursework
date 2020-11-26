#include "Book.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string title = "ABCD";
    string author = "efg";
    string genre = "hijk";
    Book b = Book(title, author, genre);
    cout << "Title name: " << b.getTitle() << endl;
    cout << "Author name: " << b.getAuthor() << endl;
    cout << "Genre name: " << b.getGenre() << endl; 
}
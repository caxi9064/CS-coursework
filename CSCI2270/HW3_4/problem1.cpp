#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool append(string* &str_arr, string s, int &numEntries, int &arraySize);
int main()
{
    string* str_arr;
    str_arr = new string[10];//allocating memory in heap
    string s;
    int numEntries = 0;
    int arraySize = 10;

    string word;
    ifstream testFile("ignoreWords.txt");
    while(testFile >> word)
    {
        bool array_doubled = append(str_arr, word, numEntries, arraySize);//calling append function
    }
    testFile.close();
    cout << arraySize << endl << numEntries << endl << str_arr[2];
}
/*
Function appends a string to array str_arr and doubles the array if size is exceeded
Parameters: reference to str_arr pointer, string to be inserted, reference to num entries, reference to size
Return: true if array is doubled 
*/
bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    //TODO: Complete this function
    bool doubled = false;
    if(numEntries == arraySize)
    {//array doubling
        
        arraySize = arraySize * 2;
        string* newArray;
        newArray = new string [arraySize];
        for(int i = 0; i < numEntries; i++)
        {
            newArray[i] = str_arr[i];
        }
        delete [] str_arr;
        str_arr = newArray;
        doubled = true;
    }
    str_arr[numEntries] = s;//adding string to array
    numEntries++;

    return doubled;
    
}
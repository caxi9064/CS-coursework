// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework6- problem #2

#include<iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

int split(string input, char separator, string arr[], int size);
int readSales(string fileName, string names_array[], int monthlySales[][12], int size);

int main ()
{
    string fileName = "sales.txt";
    const int size= 10;
    string names_array[size];
    int monthlySales [size][12];
    
    int val = readSales(fileName, names_array, monthlySales, size);
    cout << "return value:" << val << endl;
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
function finds and prints the name of employees and their monthly sales if the file can be opened
parameters: name of file, array of names, array of monthly sales, size of array 
return: the number of employees stored in the array 
*/

int readSales(string fileName, string names_array[], int monthlySales[][12], int size)
{
    ifstream in_file;
    in_file.open(fileName);

    string line; 
    string arr[12];//declaring array
    int count = 0;
    int k=0;
    int numOfLines =0;
    int total = 0;
    double average;
    
    if (in_file.is_open())
    {
        while (getline(in_file, line))//reading one line at a time
        {
            numOfLines++;
            if (count < size)//to check if there's segmentation error
            {
                if (numOfLines%2==1)//odd
                {
                names_array[count]= line;//array stores name of the employees
                cout << names_array[count];//printing name
                
                }
                else //even
                {   
                    line = line + ',';
                    int num = split(line, ',', arr, 12);
                    for (int j =0; j< num; j++)
                    { 
                        monthlySales[k][j] = stoi(arr[j]) ;//storing values in 2D array
                        total += monthlySales[k][j];//calculating total across each row
                    }
                        count++;//increments each time AFTER sales array is processed  
                        k++;
                        average = total/12.0;
                        cout << ": " << fixed << setprecision(1) << average << endl;
                        total =0;//setting total to zero 
                }
            }
            else break;//exits loop if number of values being passed to array exceeds size 
        }
    return count;
    }

    else 
    {
        return -1;
    }

    in_file.close();
}



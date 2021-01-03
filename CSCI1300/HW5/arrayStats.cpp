// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework5- problem #2

#include<iostream>
#include <string>
#include <iomanip>
using namespace std;   

void stats(double values[], int Size);

int main ()
{
    double arr[] = {10.4, 3.2, 1.4, 5.1, 6.7}; //declaring and initializing array  
    stats(arr, 5); //passing array into function , size of the array is 5
}

/*
function computes the average, min, and max of an array 
parameters: array, size
does not return anything 
*/
void stats(double arr[], int Size)
{  
    //declaring and initializing variables 
    double min = arr [0];
    double max = arr[0];
    double total = 0; 

    for (int i=0; i<Size ;i++)//loop through entire array
    {
        if (arr[i] < min)//finds min  
        {
            min = arr[i]; 
        }
        if (arr[i]>max)//finds max 
        {
            max = arr[i];
        }
        total += arr[i];  //adding all elements in the array  
    }
    //prints the results
    cout << "Min: " << fixed << setprecision(2) << min << endl;
    cout << "Max: " << fixed << setprecision(2) << max << endl;
    double average = total/Size; //computes average
    cout << "Avg: " << fixed << setprecision(2)<< average << endl; 
}
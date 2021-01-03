// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework5- problem #3

#include<iostream>
#include <string>
#include <iomanip>
using namespace std; 

void printArray(int arr[], int numElems);
int insert(int arr[], int numElems, int size, int newElement);

int main ()
{
int arr[10] = {5,10,15,20};
int numElems = 4;
int size = 10;
int newElement = 25;
numElems = insert(arr, numElems, size, newElement);
printArray(arr, numElems);
}

void printArray(int arr[], int numElems)
{   
    for (int i=0; i < numElems; i++)
    {
        cout << arr[i] << " ";
    }
}

/*
function adds an element to the ordered array  
parameters: array, number of elements in array, size of array, new element to be added
return: numElems after adding the element 
*/
int insert(int arr[], int numElems, int size, int newElement)
{
    int index=0;
    if (numElems<size)
    { 
        //has to be numElems-1 because index starts at 0 not 1
        for (int i = numElems-1; i>= 0 && arr[i]>newElement ; i--)  
        {
            //if conditions met then elements shift right and increment index
            arr [i+1] = arr [i];
            index++;
        }
        int length= numElems- index;//this is to find the position where newElement is stored 
        arr[length]= newElement;//where the new element will be stored

        return numElems+1;
    }
    else return numElems;   
}
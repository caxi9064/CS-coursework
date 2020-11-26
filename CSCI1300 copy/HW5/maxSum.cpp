// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework5- problem #4

#include<iostream>
#include <string>
#include <iomanip>
using namespace std; 

/*
function to find max value in each row and calculate sum of those values
parameters: array, rows in array
return:  sum of max values 
*/
const int columns = 10; 
int maxSum(int arr[][columns], int rows)
{
    int sum = 0;
    for (int i = 0; i<rows;i++ )
    {
        int max = arr[i][0];//initialize max value to the first element in each row 
        for (int j = 0; j<columns; j++)//loop to traverse through each row and find max value
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];//store greatest value in max
            } 
        }
        sum += max;//has to be outside for loop since sum is of the max values in each row
    }
return sum;
}

int main()
{
    int arr[2][10] = {
     {1, 2, 3, 4, 5, 10, 9, 8, 7, 6},
     {5, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
cout << "returned value: " <<  maxSum(arr, 2);
}



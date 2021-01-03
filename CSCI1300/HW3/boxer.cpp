// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #4

#include <iostream>
using namespace std;

int main()
{
    /* program to find whether entered weights are descending or ascending */ 
    int weight1, weight2, weight3; 
    cout << "Enter boxers' weights" << endl;
    cin >> weight1 >> weight2 >> weight3; 
// weights 1 2 and 3 cannot equal one another 
if (weight1 != weight2 && weight1 != weight3 && weight3 != weight2)
{
    //if the input is largest to smallest then prints descending order
    if (weight1 > weight2 && weight2 > weight3)
    {
        cout << "Descending order" << endl;
    }
    /*if the weights are not in descending order then test to see
    if they are in ascending order*/  
    else if (weight1 < weight2 && weight2 < weight3)
    {
    cout << "Ascending order" << endl;
    }
    //if none of the above conditions are met then print Neither
    else 
    {
        cout << "Neither" << endl;
    }
}
else //if the first condition is not met then the program prints neither
{
    cout << "Neither" << endl;
}

return 0;
}

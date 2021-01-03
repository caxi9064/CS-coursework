// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #5

#include <iostream>
using namespace std;

int main()
{   
    int input, position;
    cout << "Enter the height: " << endl;
    cin >> input;
    char ch = 'a';
    for(int height = input; height >= 1 ; height--)//repeats if height is greater than 0
    {
        for(int j = 1; j <= height; j++)//each row has same number of characters as the height 
        {
            cout << ch;
            ch++;
            if (ch > 'z')
            ch = 'a';    
        }
    }
    
        cout << endl;

    
    return 0;
}
    
    

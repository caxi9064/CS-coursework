// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #2

#include <iostream>
using namespace std;

int main()
/*ask user for input 
while num is > 1 
if num is even
    num = n/2
if num is odd
    num = 3n+1
display num
*/
{
    int num;  
    cout << "Enter a positive number: " << endl;  
    cin >> num;


    while (num > 1) //the loop terminates when value reaches 1
    {
        cout << num  << endl; 
        if (num % 2 ==0 )
        {
            num = num/2;
           
        }
        else 
        {
            num = (3*num + 1);
            
        }  
        cout << num << endl;
    }
   
    
    
        return 0;
    
    
}
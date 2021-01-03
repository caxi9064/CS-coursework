// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #6

#include <iostream>
using namespace std;

int main()

{
    int length, y, x, space = 1;
    cout<< "Enter the length: ";
    cin>>length;

    space = length - 1;
  for (y = 1; y<=length; y++) //run loop until length is reached
  {
    for (x = 1; x<= space; x++)//loop for adding spaces in each row
    
        cout<<" ";
        space--;
    for (x = 1; x <= 2*y-1; x++)// adding stars in each row until end of the row
        cout<< "*";
    
    cout<<endl;// next row
  }
 
  space = 1;
 
  for (y = 1; y<= length - 1; y++)//loop to find the lower half of diamond 
  {
    for (x = 1; x<= space; x++)
    cout<<" ";
    space++; //spaces increment by 1 after each row
 
    for (x = 1 ; x<= 2*(length-y)-1; x++)
      cout<< "*";
 
    cout<<endl;
  }
  return 0;
}
 


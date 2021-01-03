// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #3

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sushi_pieces ; //declaring variables
    double totalPrice, price ;
    cout << "Enter the number of sushi: " << endl;//prompting user 
  
    cin >> sushi_pieces ;//reading input
    price = 1.99 * sushi_pieces ;//initializing Price

    
    if (sushi_pieces <= 0) //input validation
    {
        cout << "Invalid input" << endl;
        return 1;
    }
     
    //If the input is btw 0 and 10 then there is no discount applied 
    if (sushi_pieces > 0 && sushi_pieces < 10)
    {
        totalPrice = price;
    }
    
    //If input is between or equal to 10 and 19 then discount 10% is applied
    if (sushi_pieces >= 10 && sushi_pieces <= 19)
    { 
        totalPrice = price * 0.9 ;
    }
   //if input is btw or equal to 20 and 49 then discount 15% is applied
    if (sushi_pieces >= 20 && sushi_pieces <= 49)
    {
        totalPrice = price * 0.85 ;
    }
    //if input is between or equal to 50 and 99 then discount 20% applied
    if (sushi_pieces >= 50 && sushi_pieces <= 99)
    {
        totalPrice = price * 0.8 ;
    }
    // if input is greater than or equal to 100 then discount of 25% applied
    if (sushi_pieces >= 100)
    {
        totalPrice = price * 0.75 ;
    }
    //printing value of total price 
    cout << "Total price: $" << fixed << setprecision(2) <<totalPrice << endl;
return 0;
}
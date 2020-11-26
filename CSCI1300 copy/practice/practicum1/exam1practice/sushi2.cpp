#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sushi_pieces ; //declaring variables
    double totalPrice, price ;
    cout << "Enter the number \n of sushi: " << endl;//prompting user 
  
    cin >> sushi_pieces ;//reading input
    price = 1.99 * sushi_pieces ;//initializing Price

    if (sushi_pieces > 0)
    {
        if (sushi_pieces < 10)
        {
            totalPrice= price;
        }
        if (sushi_pieces >=10 && sushi_pieces <=19)
        {
            totalPrice = price * .95;
        }
        cout << "The price is: " << totalPrice << endl;
    }

    else 
    {
    cout << "Invalid input" << endl; 
    }
    return 0;
}
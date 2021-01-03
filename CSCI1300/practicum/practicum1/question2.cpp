#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int number;
    cout << "Enter Number: " << endl;
    cin >> number ;

    switch (number)
    {
        case 0: cout << "" << endl; break;
        case 1: cout << "st" << endl; break; 
        case 2: cout << "nd" << endl; break;
        case 3: cout << "rd" << endl; break; 
        default : cout << "th" << endl; break; 
    }
    
return 0;
}
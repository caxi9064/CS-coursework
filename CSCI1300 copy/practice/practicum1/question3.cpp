#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double num1, num2, num3;
    cout << "Enter first number: " << endl;
    cin >> num1;
    cout << "Enter second number: " << endl;
    cin >> num2;
    cout << "Enter third number: " << endl; 
    cin >> num3;

    if (num1 < num3 && num1 < num2)
        cout << "The smallest number is " << num1 << endl;
    if (num2 < num3 && num2 <num1)
        cout << "The smallest number is " << num2 << endl;
    if (num3 < num1 && num3 < num2) 
        cout << "The smallest number is " << num3 << endl;

return 0;
}
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double number1, number2, answer;
    char userResponse ;
    cout << "Enter a number: " << endl
    << "Enter another number: " << endl
    << "Enter an operator: " << endl; 
    cin >> number1 >> number2 >> userResponse;

    switch (userResponse)
    {
        case '+':
        {
        answer = number1 + number2; 
       // cout << number1 << A << number2 << " = " << answer << endl; break;
        }
        case '-': 
        {
        answer= number1 - number2 ; 
        //cout << number1 << A << number2 << " = " << answer << endl; break;
        }
        case '/':  
        {
        answer= number1 / number2; 
        //cout << number1 << A << number2 << " = " << answer << endl; break;
        }
        case '*':  
        {
        answer= number1 * number2 ; 
        //cout << number1 << A << number2 << " = " << answer << endl; break;
        }
        cout << number1 << " " << userResponse << " " << number2  << " = " 
        << fixed << setprecision(2) 
        << answer << endl; break;
        default : cout << "Invalid operator" << endl; 
    }
return 0;
}
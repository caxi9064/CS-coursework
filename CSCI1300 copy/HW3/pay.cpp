// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #2

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float hoursWorked, payRate, totalPay; //declaring variables as floats
    cout << "Enter the number of hours worked " << endl;//prompting for input
    cin >> hoursWorked;//reading and storing input in'hoursWorked'
    cout<< "Enter an hourly pay rate "<< endl; //Prompting user for input 
    cin >> payRate ;//storing input in 'payRate'

    if (hoursWorked < 0 || payRate < 0) //input validation 
    {
        cout << "Invalid input" << endl; 
        return 1; //terminates program 
    }

    //if hoursWorked is less than 40 then no overtime pay is included
    if (hoursWorked <= 40)
    {
        totalPay = hoursWorked * payRate ; 
    }
    
    else
    {   //cannot use % 
        totalPay = ((hoursWorked - 40) * 1.5 * payRate) + (40.0 * payRate) ;
    }
    cout << "Paycheck: " << fixed << setprecision(2) << totalPay << endl; 
return 0;
}

/*
    if (hoursWorked > 0 && payRate > 0 )
    {   
        if (hoursWorked <= 40)
        {
            totalPay = hoursWorked * payRate;
            cout << "Paycheck: " << fixed << setprecision(2) 
            << totalPay << endl; 
        }
        else 
        {
            totalPay =((hoursWorked - 40) * 1.5 * payRate) 
            + (40.0 * payRate);
            cout << "Paycheck: " << fixed << setprecision(2) 
            << totalPay << endl;
        }
    }
    else
    {
        cout << "Invalid input" << endl;
    }
    
return 0;
}
*/ 



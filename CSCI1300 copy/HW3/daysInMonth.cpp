// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #5

#include <iostream>
using namespace std;

int main()
{
    int year, month;//declaring variables 
    cout << "Enter a year: " << endl; 
    cin >> year;
    cout << "Enter a month: " << endl;
    cin >> month; 


    switch (month)//switch statement, multiple alternatives for variable month
    // there are 31 days for the months 1,3,5,7,8,10,12 
    {   case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout << 31 << " days " << endl; break; 

    // there are 30 days in months 4, 6, 9 ,11
        case 4:
        case 6:
        case 9:
        case 11: cout << 30 << " days " << endl; break;

//month 2 has either 28 or 29 days depending on if its a leap year. 
        case 2:    
        /* 
         if the year is greater than 1572 and divisible by 100, then it must
         also be divisible by 400 to be a leap year. If it is not divisible 
         by 400 then it is not a leap year. 
        */
            if (year > 1572 && year%100==0)
        {   
            if (year%400 ==0)
            {
                cout << 29 << " days " << endl; break;
            }
            else
            {
                cout << 28 << " days " << endl; break;
            }
        }

        /* if the year is before 1572 or if the year is not divisible
        by 100, then it has to be divisible by 4 to be a leap year. 
        */
            if (year%4==0)
            {
            cout << 29 << " days " << endl; break;
            }
            else
            {
            cout << 28 << " days " << endl; break;
            }
              
        default: cout << "Invalid month" << endl; break;//if month not 1-12
    }
return 0;
}
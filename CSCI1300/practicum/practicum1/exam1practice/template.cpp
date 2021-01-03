#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{   int month, day; 
    cout << "Enter month: " << endl;
    cin >> month ;
    cout << "Enter day: " << endl; 
    cin >> day; 

    switch (month)
    {
        case 1: 
        case 2: cout << "The season is winter" << endl; break;

        case 3: 
            if (day <= 21 )
            {
                cout << "The season is winter" << endl; break;
            }
            else //if (day <= 31)
            {
            cout << "The season is spring" << endl; break;
            }

        case 4:
        case 5: cout << "The season is spring" << endl; break;

        case 6: 
            if (day > 0 && day <= 20) 
            {
                cout << "The season is spring" << endl; break;
            }
             else //if (day <= 30)
            {
            cout << "The season is summer" << endl; break;
            }

        case 7:
        case 8: cout << "The season is summer" << endl; break;

        case 9: 
        if (day <= 20)
        {
           cout << "The season is summer" << endl; break;
        }
        else //if (day <=30)
        {
            cout << "The season is fall" << endl; break;
        }

        case 10:
        case 11: cout << "The season is fall" << endl; break; 

        case 12: 
        if (day <= 20)
        {
            cout << "The season is fall" << endl; break; 
        }
        else //if (day <= 31)
        {
            cout << "The season is winter" << endl; break;
        }
    }
    

return 0;
}
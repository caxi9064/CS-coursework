#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int day;
    cout << "Enter the day: " << endl;
    cin >> day;

    switch (day)
    {
        case 1 : cout << "MONDAY" << endl; break; 
        case 2:
        case 3: 
        case 4: cout << "WORKDAY" << endl; break;
        case 5: cout << "FUNDAY" << endl; break;
        case 6:
        case 0:cout << "SLEEPDAY" << endl; break;
        default: cout << "INVALID" << endl; break;
    }
    return 0;
}
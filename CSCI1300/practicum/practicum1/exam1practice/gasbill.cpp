#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int units ;
    double totalCost;
    cout << "Enter unites used: " << endl;
    cin >> units;

    if (units > 0)
    {
        if (units <= 100)
        {
            totalCost = 1.23 * units ; 
            cout << "Total cost: " << totalCost << endl; 
        }
        else if (units > 100)
        {
            totalCost = 123 + (1.14 * (units%100)) ;
            cout << "Total cost: " << totalCost << endl; 
        }
        else if (units > 200)
        {
            totalCost = 123 + 114 + (1.08 * (units%200));
            cout << "Total cost: " << totalCost << endl; 
        }
    }
    else 
    {
        cout << "Incorrect input" << endl;
    }
return 0;
}
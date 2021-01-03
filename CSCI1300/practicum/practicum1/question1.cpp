#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double distance, averageSpeed, gasPrice, tripCost;
    cout << "Enter the distance travelled: " << endl;
    cin >> distance ;
    cout << "Enter the average speed: " << endl;
    cin >> averageSpeed;
    cout << "Enter the gas price: " << endl;
    cin >> gasPrice; 
    if (averageSpeed > 62)
    {
        tripCost = (distance/26) * gasPrice;
    }
    else 
    {
        tripCost = (distance/30) * gasPrice;
    }

    cout << "The total cost of the trip is: " << tripCost << endl;  

return 0;
}
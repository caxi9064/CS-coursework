#include <iostream>
using namespace std;

int main(){
//representing time in a digital clock
    int hour, minutes;
    cout << "Enter the time in hours and minutes: " << endl;
    cin >> hour >> minutes;

    switch (hour) 
    {
        case 1:
        case 2:
        case 3:
        case 4: 
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11: cout << hour << " : " << minutes << "AM" << endl; break;
        case 12: cout << hour << ":" << minutes << "PM" << endl; break;
        default: cout << "Wrong input!" << endl; break;
    }
    return 0;
}
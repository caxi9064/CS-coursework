#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
   int month; 
	cout << "Enter a month:" << endl; 
	cin >> month; 
    
    
	if (month == 12 || month <= 3)
    {
		cout << "It's winter" << endl;
    }
	else if(month >= 4 && month <= 5)
    {
		cout << "It's spring" << endl; 
	} 
   
    else if (month >= 6 && month <= 8)
    {
		cout << "It's summer" << endl; 
	}
    else if (month >= 9 && month <= 11)
    {
		cout << "It's autumn" << endl; 
	} 

	if (month < 1 or month > 12)
    {
		cout << "Invalid" << endl; 
	}

	return 0;
}
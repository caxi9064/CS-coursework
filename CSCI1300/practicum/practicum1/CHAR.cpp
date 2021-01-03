#include <iostream>
#include <string>
using namespace std;

int main()
{//using a string 
//does not work for switch statements
    string userResponse;
    cout << "Do you own a dog?" << endl;
    cin >> userResponse;

        if (userResponse == "Yes" || userResponse == "yes" )//string has to be in " "
        {
            cout << "Meat's the need of dogs like yours!" << endl;
        }
       
        else
        {
            cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint."
            << endl;
        }

//using a character
//can use in switch statements
    char userResponse;
    cout << "Do you own a dog?" << endl;
    cin >> userResponse; 

        if (userResponse == 'Y' || userResponse == 'y') //char has to be in ' '
         {
            cout << "Meat's the need of dogs like yours!" << endl;
        }
       
        else
        {
            cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint."
            << endl;
        }

return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int my_height;
    cout << "Enter your height: " << endl;
    cin >> my_height ;
    bool overSixFeet;

    if (my_height >= 6)
   {
    {
         overSixFeet = true;
    }
    else
    {
         overSixFeet = false ;
    }
   }  
    if (overSixFeet == true)
    {
        cout << "Over six feet" << endl;
    }
    else 
    {
        cout << "Under six feet" << endl;
    }
  
return 0;
}
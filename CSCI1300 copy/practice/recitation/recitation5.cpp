#include <iostream>
#include <string>
using namespace std;   
//int main()
/*
//for loop, while loop
    int x = 10;int sum = 0;
   
    for(int i=0; i < x; i++)
    {
    sum += x;
    }
    cout << "Sum = " << sum << endl;
    return 0;
    

    int i=10;
    while (i<x)
    {
        i++;
        sum +=x;
    }
        cout << "Sum = " << sum << endl;
    return 0;

// converting uppercase to lowercase characters
pseudocode:
initialize userString 
prompt user for input
store input in userString
initialize newString
For i=0 to the end of the string
    if userString >= 65 && userString <= 90 
        add userString[i]+65 to newString 
    else 
        add userString[i] to newString
print newString

string userString;
cout << "please enter a string: " << endl;
cin >> userString;
for (int i=0; i<=userString.length(); i++)
{
    if (userString[i] <= 90 && userString[i] >= 65)
    cout << char (userString[i]+32);
    
    else cout << char (userString[i]);
}
return 0; 
*/

// converted to a function 
/**
 * converts string to lower case 
 * @param userString 
 * @return 
 */


string getLowerCase(string userString);
int main()
{
    
    string returnValue1 = getLowerCase("Welcome to CSCI 1300!"); 
    cout <<returnValue1<< endl; 
    
    string returnValue2 = getLowerCase("Hello World!");
    cout << returnValue2<< endl;

    string returnValue3 = getLowerCase("AbcdeFGHIjklmnOPQRST");
    cout << returnValue3 << endl;
return 0; 
}

string getLowerCase(string userString)
{
  
    string returnString; 
    for (int i=0; i<=userString.length(); i++)
    {
    if (userString[i] <= 90 && userString[i] >= 65)
    returnString += userString[i] +32 ;
    
    else returnString += userString[i];
    }
return returnString;
}

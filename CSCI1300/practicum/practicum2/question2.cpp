#include<iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;
int CountMtoZ (string str);
int main()
{
    string input =  "MUENZINGER";
    cout << CountMtoZ(input);
    
}

int CountMtoZ (string str)
{
    int count = 0;
    if (str.length()==0)
    {
        return -1;
    }
    for (int i = 0; i<str.length(); i++)
    {
        if (str[i]=='M'|| str[i]=='N' ||str[i]=='O'||str[i]== 'P'|| str[i]== 'Q'|| str[i]== 'R'
        || str[i]== 'S'||str[i]== 'T' || str[i]== 'U'|| str[i]=='V'|| str[i]=='W'|| str[i]=='X'
        ||str[i]=='Y'||str[i]=='Z')
        count++;
    }
    if (count == 0)
    {
        return -2;
    }
    return count;
}

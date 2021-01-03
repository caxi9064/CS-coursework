#include<iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;

void printCountriesInRange(string names [], int medalCount[], int n);

int main()
{
    int n = 4;
    string names[4]={"USA", "Mexico", "Norway", "Canada"};
    int medalCount[4]= {14, 3, 10, 12};
    printCountriesInRange(names, medalCount, n);
    
}
void printCountriesInRange(string names[] , int medalCount[], int n)
{
    for (int i = 0; i<n; i++)
    {
        if (medalCount[i]<=15 && medalCount[i]>=10)
        cout<< names[i] << " " << medalCount[i] << endl;
    }
}
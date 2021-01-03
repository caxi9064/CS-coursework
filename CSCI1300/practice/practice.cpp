#include<iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;

void floodMap(double arr[][4], int rows, double waterLevel);

int main() 
{
    double map[4][4] = {{5.9064, 15.7541, 6.11483, 11.3928}, 
{16.8498, 5.736, 9.33342, 6.36095}, 
{3.18645, 16.935, 4.7506, 9.63635}, 
{2.22407, 0.815145, 0.298158, 13.466}};
floodMap(map, 4, 9.3);

}

const int columns = 4;
void floodMap(double arr[][columns], int rows, double waterLevel)
{
   for (int i = 0; i<rows; i++)
   {
       for (int j = 0; j<columns; j++)
       {
           if (arr[i][j]>waterLevel)
           {
               cout << "_" ;
           }
           else cout << "*" ;
       }
       cout << endl;
   }
}

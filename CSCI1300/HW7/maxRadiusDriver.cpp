// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Homework 7 - Problem # 2
#include <iostream>
#include "Planet.h"
using namespace std;

int maxRadius(Planet planets[], int size);
int main()
{
    Planet planets[3];
planets[0] = Planet("Nebraska",13.3);
planets[1] = Planet("Flarbellon-7",8.6);
planets[2] = Planet("Parblesnops",6.8);
int idx = maxRadius(planets, 3);
cout << planets[idx].getName() << endl;
cout << planets[idx].getRadius() << endl;
cout << planets[idx].getVolume() << endl;
}

/*
finds the max value in array
parameters: an array, num of elements in the array 
return: index where largest value was found
*/
int maxRadius(Planet planets[], int size)
{
    double max = planets[0].getRadius();
    int idx=0;

    if (size==0)
    return -1;

    for (int i = 0; i<size;i++)
    {
        if (planets[i].getRadius()>max)
        {
            max = planets[i].getRadius();
            idx=i; 
        }
    }
    return idx; 
}


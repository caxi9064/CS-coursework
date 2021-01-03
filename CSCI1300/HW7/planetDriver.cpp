// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Homework 7 - Problem # 1
#include <iostream>
#include "Planet.h"
using namespace std;

int main() {
    string name = "Jupiter";
    double radius = 7, newRadius = 40;
    Planet p6 = Planet(name, radius);
    cout << "Planet Name: " << p6.getName() << endl; 
    cout << "Planet Radius: " << p6.getRadius() << endl;
    cout << "Planet Volume: " << p6.getVolume() << endl;
    p6.setName("Jupiter");
    p6.setRadius(newRadius);
    cout << "Planet Name: " << p6.getName() << endl; 
    cout << "Planet Radius: " << p6.getRadius() << endl;
    cout << "Planet Volume: " << p6.getVolume() << endl;
}

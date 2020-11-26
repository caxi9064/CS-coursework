
#include <iostream>
#include <string>
#include <cmath>
#include "Planet.h"

using namespace std;

/*
sets planet name to empty and planet radius to 0.0
*/
Planet::Planet()
{
    planetName = "";
    planetRadius =0.0;
}

/*
set the name and radius 
parameters: name and radius 
*/
Planet::Planet(string s, double r)
{
    planetName = s;
    planetRadius = r;
}

/*
set the planet's name
parameter: string name
*/
void Planet::setName(string s)
{
    planetName = s;
}

/*
set the planet's radius 
parameter: radius
*/
void Planet::setRadius(double r)
{
    planetRadius = r;
}

/*
get name of planet
return: name of planet 
*/
string Planet::getName() const
{
    return planetName;
}

/*
get radius of planet
return: radius of planet
*/
double Planet::getRadius() const
{
    return planetRadius;
}

/*
calculate volume of planet 
return the volume
*/
double Planet::getVolume()const
{
    double volume = (4.0/3)*M_PI*pow(planetRadius,3);
    return volume;
}


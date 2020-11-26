//header file
#ifndef PLANET_H
#define PLANET_H 

#include <string>
#include <iostream>
using namespace std;

class Planet
{
    public: //functions here
        Planet();//default constructor
        Planet(string s, double r);//parameterized constructor
    
        //mutators, update values
        void setName(string s);
        void setRadius(double r);
        

        //accessors, return values
        string getName()const; 
        double getRadius()const;
        double getVolume()const;

        
    private: //variables here
        string planetName;
        double planetRadius;
};//semicolon denotes class

#endif
// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework2- problem #6

#include <iostream>
#include <cmath>

using namespace std; 
int main(){
    /* 
    1. declare variables 
    2. ask for the radius 
    3. store value in variable radius 
    4. calculate Volume and SurfaceArea
    5. display Volume and Surface Area
    */ 
    double radius, Volume, SurfaceArea; 
    cout << "Enter a radius: " << endl;
    cin >> radius ;
    Volume = (4 * M_PI * (pow(radius,3)/3));
    SurfaceArea = 4 * M_PI * pow(radius,2); 

    cout << "Volume: "<< Volume << endl;
    cout<< "Surface area: "<< SurfaceArea << endl;
    return 0;
}   
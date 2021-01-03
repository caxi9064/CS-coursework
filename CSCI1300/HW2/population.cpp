// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework2- problem #4

#include <iostream>
using namespace std;

int main(){
    /* 
    1. declare variables
    2. ask for the current population
    3. store value in the variable currentPopulation 
    4. calculate finalPopulation
    5. print finalPopulation
    */
    int birth, death, newImmigrant, currentPopulation, finalPopulation ;
    cout << "Enter the current population: "<< endl;
    cin >> currentPopulation ; 

    birth = 3942000; //birth = 1/8 * sec;
    death = 2628000; //death = 1/12 * sec;
    newImmigrant = 1168000; //newImmigrant = 1/27 * sec;
   
    finalPopulation = currentPopulation - death + birth + newImmigrant ; 
    
    cout << "The population in one year: " << finalPopulation << endl;
    return 0; 
}
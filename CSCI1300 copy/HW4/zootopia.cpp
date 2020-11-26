// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework4- problem #3

#include <iostream>
using namespace std;
/* 
initialize variables
prompt user to select an option from menu
Repeat for each option if user does not choose 4
if user chooses option 1 
    prompt user for agility and strength 
    display hireScore=
if user chooses 2
    promt user for agility and speed
    display hireScore=
if user chooses 3
    prompt user for strength and speed
    display hireScore 
if input is not 1-4 then 
    display "invalid input"

if user chooses 4
    "Good bye!" 
*/
int main()
{
    double hireScore, option, agility, speed, strength;
    option = 1; 
    while (option != 4) //if user does not choose 4 then repeat all of this
    {
    cout << "Select a numerical option: " << endl
    << "=== menu ===" << endl
    << "1. Fox " << endl
    << "2. Bunny " << endl
    << "3. Sloth " << endl
    << "4. Quit " << endl; 
    cin >> option ;

        if (option == 1)
        {
            cout << "Enter agility: " << endl;
            cin >> agility ;
            cout << "Enter strength: " << endl;
            cin >> strength;
            hireScore = 1.8 * agility + 2.16 * strength ;
            cout << "Hire Score: " << hireScore << endl;
    
        }
        if (option == 2)
        {
            cout << "Enter agility: " << endl;
            cin >> agility ;
            cout << "Enter speed: " << endl;
            cin >> speed;
            hireScore = 1.8 * agility + 3.24 * speed;
            cout << "Hire Score: " << hireScore << endl;
        }
        if (option ==3)
        {
            cout << "Enter strength: " << endl;
            cin >> strength ;
            cout << "Enter speed: " << endl;
            cin >> speed;
            hireScore = 2.16 * strength + 3.24 * speed;
            cout << "Hire Score: " << hireScore << endl;
        }
        if (option > 4 || option < 1)
        {
            cout << "Invalid option" << endl;
        }
    }
    
        //exits while loop  
        cout << "Good bye!" << endl; 
        return 0;
}
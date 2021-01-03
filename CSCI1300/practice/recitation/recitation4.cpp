#include <iostream>
using namespace std;
int main()
{
/*
pseudocode:
declare variable option 
prompt user for input: option
read input option 
if menu option is 1
    then display ...
else if menu option is 
    then display ...
else if menu option is 3
    then display ...
else if menu option is 4 
    then display ... 
*/
//While and switch statements 
    int option = 0; // declaring option 

    while (option !=4) //loop executes as long as the option is never equal to 4
    {
        cout << "The options are: " << endl
        << "\t1. Load data" << endl
        << "\t2. Run data" << endl
        << "\t3. Save data" << endl
        << "\t4. Quit data" << endl
        << "Please choose one program option: " << endl;
    }
    cin >> option ;
    switch (option)
    {
        case 1: cout << "Loading data..." << endl; break;
        case 2: cout << "Processing data..." << endl; break;
        case 3: cout << "Saving data..." << endl; break;
        case 4: cout << "Bye" << endl; break;
        default: cout << "Invalid input" << endl; break;
    }

return 0;
/*
// Do While loop 
    do 
    {
        cout << "The options are: " << endl
        <<  "1. Load data" << endl
        <<  "2. Run data" << endl 
        <<  "3. Save data" << endl
        <<  "4. Quit data" << endl
        << "Please choose one program option: " << endl;
    cin >> option ;
    }
*/
}
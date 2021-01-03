// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int score1, score2, score3; //declaring variables 
    cout << "Enter practicum 1 score : " << endl; //prompting user for input
    cin >> score1; //Read input and store in 'score1'
    cout << "Enter practicum 2 score : " << endl;//prompting user for input
    cin >> score2;  //Read input, store in 'score2' 
    cout << "Enter practicum 3 score : " << endl;//prompting user for input
    cin >> score3; //Read input, store in 'score3'
    
    //calculating the average score and typecasting 
    double practicumAverage = (double)(score1+score2+score3)/3;
    
    //printing the practicum average score
    cout << "Practicum average: " << fixed << setprecision(2)
    << practicumAverage << endl;

    if (practicumAverage >= 67 )
    {cout << "You have a passing practicum average." << endl; 
    }
    else cout << "You can retake practicums during the final." << endl; 

return 0 ;
}
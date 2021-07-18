#include<iostream>
#include<cmath>
#include<iomanip>
#include "StackCalculator.hpp"

using namespace std;

int main()
{
  // stack to hold the operands
  StackCalculator stack;

  int numElement = 0;
  string* inparr = new string[50];

  // enter a number
  string number;
  cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, number);
    
   if (number == "=")break;
   else
   {
     inparr[numElement] = number;
     numElement++;
   }
  }

 if (numElement == 0)
 {
   cout << "No operands: Nothing to evaluate " << endl;
 }
 else
 {
   bool res = stack.evaluate(inparr, numElement);
   if (res == true)
    {
      cout << "Result= " << stack.getStackHead()->number << endl;
    }
 }   
  return 0;
}

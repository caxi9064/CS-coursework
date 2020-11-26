#include <iostream>
#include <string>
using namespace std;   
//q2 pseudocode
//deposit (balance, amount)
//  return balance and amount 
//withdraw (balance, amount)
//  if balance is greater than amount
//      print "amount too large"
//  else 
//      return balance-amount 

double withdraw(double balance,double amount);
double deposit(double balance,double amount);
void menu();//displays menu everytime

int main ()
{
    double balance = 0; 
    double amount = 0;
    int option = 0;
    while (option != 4)
    {
        menu (); //display menu
        cin >> option; //get input

        switch (option)
        { 
            case 1: 
            cout << "How much money" << endl;
            cin >> amount;
            balance =withdraw(balance,amount); 
            cout << balance << endl; break;

            case 2:
            cout << "How much money" << endl;
            cin >> amount;
            balance = deposit (balance,amount);
            cout << balance << endl; break;
        
            case 3:
            cout << "How much money" << endl;
            cin >> amount; break;
            
            case 4: cout << "Exiting program" << endl;break;
            default: cout << "invalid input" << endl; break;
        }
    }
}
double withdraw(double balance,double amount)
{
    if (balance < amount)
    {
        cout << "Error: amount too large"<< endl;
    }
    else 
    {
        balance -= amount;
    } 
    return balance;
}

double deposit(double balance,double amount)
{
    return balance += amount ;
}

void menu ()
{
    cout << "\tMenu\n" << "\t1) withdraw\n" << "\t2) deposit\n" << "\t3) check balance\n" << 
    "\t4) exit" << endl;
}
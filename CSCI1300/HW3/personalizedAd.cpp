// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework3- problem #6

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int adScore, facebookFriends, zipCode, age;
    //string userResponse;
    string userResponse;
    
    cout << "How personalized should the ad be? (1-3)" << endl;
    cin >> adScore ;

    switch(adScore) //multiple alternatives for adScore tested (1-3)
    {
        case 1:  //1 is the user input
        cout << "Do you own a dog?" << endl;
        cin >> userResponse;
        /* If the user says yes or Yes to having a dog*/
        if (userResponse == "Yes" || userResponse == "yes" )
        {
            cout << "Meat's the need of dogs like yours!" << endl; break;
        }
        /*If user does not say yes or Yes*/
        else
        {
            cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint."
            << endl; break;
        }
        

        case 2: //2 is the user input
        cout << "How many Facebook friends do you have?" << endl; 
        cin >> facebookFriends;

        //if input is greater than or equal to 500 
        if (facebookFriends >= 500)
        {
            cout << "Don't like cleaning up after your dog?"
            " Call Doody Free to sign up for backyard cleanup"
            " or dog walking service." << endl; break;
        }
        
        else//if (facebookFriends < 500)
        {
            cout << "Who doesn't need another cat?"
            " Adopt a shelter pet right meow." << endl; break;
        }

        case 3: //3 is the user input
        cout << "What is your zip code?" << endl;
        cin >> zipCode;
        cout << "What is your age?" << endl;
        cin >> age ;

        /*if the zipcode is in boulder then the program will then 
        test other conditions*/
        if (zipCode >= 80301 && zipCode <= 80310)
        {
            //test the condition if the age is greater than 25 or not.
            if (age>=25)
            {
                cout << "You are surrounded by professional athletes."
                " Up your exercise game in the privacy of"
                " your home with a Peloton bike." << endl; break;
            }
            else //if (age<25)
            {
                cout << "Looking for dinner that won’t break the bank? Tacos."
                " Come grab a $3 at Centro Latin Kitchen." << endl; break;
            }
        }
        else //the first condition is false 
        {
            cout << "Feeling Uninspired? The Boulder Flatirons are calling."
            " Come hike to inspiring views, delicious food, and enjoy"
            " the hospitality of Boulder, CO." << endl; break;
        }
        default: cout << "Invalid option." << endl; break;
        //if the user inputs something other than 1-3 when prompted
    }
return 0;
}
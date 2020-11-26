// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 123 – Sanskar Katiyar
// Project 2 - Problem # 6

#include "user.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{

User A;

int numCheck = 8;
int indexes[] = {-10, -1, -12, 0, 5, 8, 7,6};
int ratings[] = {1, 2, 3, 4, 5, 6, 7, 8,};

cout << "checking setRatingAt "<< endl;
for(int i = 0; i < numCheck; i++){
     int index = indexes[i];
     int rating = ratings[i];
     cout << A.setRatingAt(index, rating) << endl;
}

cout << endl << "checking getRatingAt"<< endl;
for(int i = 0; i < numCheck; i++){
    int index = indexes[i];
    cout << A.getRatingAt(index) << endl;
}

// int array[50, 60, 70, 80, 90];
// User B("hello", array, 5);
// for (int i = 0; i<5; i++)
// {
//     int index= i;
//     int value= array[i];
//     cout << B.setRatingAt(index,value) << B.getRatingAt(index) << endl;
// }


}
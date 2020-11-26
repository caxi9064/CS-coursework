// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326- Sanskar Katiyar
// Homework 8 - Problem # 2
#include <iostream>
#include <vector>
using namespace std;

vector<int>shuffle(vector<int> v1 , vector<int> v2); 
int main() 
{
    vector<int> v1 = {1, 2,3,4,5};
    vector<int> v2 = {1,100, 2, 5000};
    vector<int> v3= shuffle(v1,v2); 
    for (int i = 0; i<v3.size();i++)
    {
        cout << v3[i];
    }
}
/*
Function combines the input of two vectors and creates another vector
parameters: vector 1 and vector 2
return: vector of combined input values
*/
vector<int>shuffle(vector<int> v1, vector<int> v2)
{
    vector<int> shuffled; //declaring empty vector

    if (v1.size() != v2.size())
    {
        if (v1.size()>v2.size())
        {
            for (int i = 0; i< v1.size(); i++)
            {
                if (i < v2.size())
                {
                    //alternating digits
                    shuffled.push_back(v1[i]);
                    shuffled.push_back(v2[i]);
                }
                else shuffled.push_back(v1[i]);//appending the remaining digits of v1
            }
        }
        else 
        {
            for (int i = 0; i< v2.size(); i++)
            {
                if (i < v1.size())
                {
                    //alternating digits
                    shuffled.push_back(v2[i]);
                    shuffled.push_back(v1[i]);
                }
                else shuffled.push_back(v2[i]);
            }
            
        }
    }
    else if (v1.size() ==0 && v2.size()==0)
    {
        shuffled = v1;
        return shuffled; //returns an empty string
    }

    else if (v1.size() == v2.size())
    {
        for (int i = 0; i< v1.size(); i++)
        {
            shuffled.push_back(v1[i]);
            shuffled.push_back(v2[i]);
        }
    }
    return shuffled; 
}
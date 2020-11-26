// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326- Sanskar Katiyar
// Homework 8 - Problem # 1 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // Implementation here
    int input;
    vector<int> v;

    cout << "Please enter a number:" << endl;
    cin >> input;
    if (input == -1)
    {
        cout << "The vector is empty." << endl; 
        return -1;
    }
    while (input != -1)
    {
        if (input <= 0)
        {
            cout << "The number should be a positive integer or -1.\n";
        }
        else if (input > 0)
        {
            if (v.size() == 0)
            {
                v.push_back(input); 
            }
            else if (v.size() == 0 && input%3 != 0 && input%5 != 0)
            {
                
                v.push_back(input);
                
            }
            else if (v.size()> 0)
            {
                if (input%5==0)
                {
                    v.erase(v.begin());
                }
                else if (input%3==0)
                {
                    v.pop_back();
                }
            }
        }
        for (unsigned int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " "; 
    }
    cout << endl;
        cout << "Please enter a number:" << endl;
        cin >> input;
    }

    if (v.size() != 0){
        cout << "The elements in the vector are: ";
    for (unsigned int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " "; 
    }
    cout << endl;
    
    int min = v[0];
    int max = v[0];
    for (unsigned int j = 0; j<v.size();j++)
    {
        if (v[j] <= min)
        {
            min = v[j];
        }
    }
    for (unsigned int k = 0; k<v.size();k++)
    {
        if (v[k] >= max)
        {
            max = v[k];
        }
    }
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl; 
    return 0;
    }
    else cout << "The vector is empty." << endl; 
}

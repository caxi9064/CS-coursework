#pragma once
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
class Probability
{
    private: 
    float prob_values [50];
    string event[50];
    
    public:
    Probability();
    void ReadFile(string fileName);
    string getMostLikelyEvent(float threshold);
    int split(string input, char separator, string arr[], int size);
    
};
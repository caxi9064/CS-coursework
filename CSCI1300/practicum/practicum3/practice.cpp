#include "practice.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
Probability::Probability()
{
    for(int i = 0; i<50; i++)
    {
        prob_values[i]=0;
        event[i] = "";
    }
}
void Probability::ReadFile(string fileName)
{
    string words[2];
    ifstream file;
    file.open(fileName);
    string line;
    int i = 0;
    while (getline(file, line, ','))
    {
        //cout << line;
        event[i]= line;
        getline(file, line);
        //cout << line;
        prob_values[i] = stof(line);
        i++;
    }
}
string Probability::getMostLikelyEvent(float threshold)
{
    string s;
    float max = threshold;
    int j = -1;
    for (int i = 0; i < 50; i++)
    {
        if (prob_values[i] > max)
        {
            max = prob_values[i];
            s = event[i];
            j++;
        }
    }
    if (j==-1)
    {
        return "";
    }  
    else return s;
}
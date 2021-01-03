#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "practice.h"
#include <cstdlib>
using namespace std;
int main()
{
    Probability user;
    user.ReadFile("practiceFile.txt");
    //cout << user.split(line, ',', words, 2);
    cout << user.getMostLikelyEvent(9.0);
    
}

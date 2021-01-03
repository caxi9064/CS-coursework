#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //writing to file
    fstream results;
    results.open("practiceFile.txt", ios::app); 
    results << "writing this to file." << endl;
    results << "1234" << endl;
    results.close();

    //reading a file
    string line;
    results.open("practiceFile.txt");
    while(results >> line)//reading word by word
    {
        cout << line << endl;
    }
    

    return 0;
}
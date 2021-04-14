#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int addToArrayAsc(float sortedArray[100], int numElements, float newValue);

int main(int argc, char *argv[])
{
    float arr[100];
    int numElements = 0;
    float newValue = 0;

    //reading file numbers.txt using command line
    string filename = argv[1];
    ifstream numbersFile;
    numbersFile.open(filename);
    if (numbersFile.fail())
    {
        cout << "Failed to open the file." << endl;
    }

    string line;
    while(getline(numbersFile, line)) //reading file and storing each line in variable
    {
        newValue = stof(line);
        numElements++; //each time element is going to be added increment by 1
        addToArrayAsc(arr, numElements, newValue);
    }
    numbersFile.close();
}
//function returns a count of elements
int addToArrayAsc(float sortedArray[100], int numElements, float newValue)
{
    sortedArray[numElements-1] = newValue;
    for (int i = 0; i < numElements-1; i++) // bubble sort
    {
        for (int j = 0; j < numElements-1; j++)
        {
            if (sortedArray[j] > sortedArray[j+1])
            {
                swap(sortedArray[j], sortedArray[j+1]);
            }
        }
    }
    for (int i = 0; i<numElements; i++)
    {
        if (i == numElements - 1)
        {
            cout << sortedArray[i];
        } 
        else cout << sortedArray[i] << ",";
    }
    cout << endl;
    return numElements;
}

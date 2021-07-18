#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
struct wordRecord
{
    string word;
    int count;
};
void getIgnoreWords(const char* ignoreWordFileName, string ignoreWords[]);
bool isIgnoreWord(string word, string ignoreWords[]);
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);
void sortArray(wordRecord distinctWords[], int length);
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);
int isDistinct(string word, int currentSize, wordRecord distinctWords[]);
void sortAlphabetically(wordRecord distinctWords[], int length);
int main(int argc, char* argv[])
{
    int N = stoi(argv[1]);//index
    string fileName = argv[2];//mobydick file
    string fileName2 = argv[3];//ignoreWords file
    const char *ignoreWordFileName = fileName2.c_str();

    if (argc != 4)
    {
        cout << "Usage: Assignment2Solution 3 mobydick.txt ignoreWords.txt " << endl;
    }
    string ignoreWords[50];//array stores most common words
    getIgnoreWords(ignoreWordFileName, ignoreWords);

    //creating array of structs
    int length = 100;
    wordRecord* distinctWords;
    distinctWords = new wordRecord[length];

    wordRecord record; //creating struct object

    ifstream myFile(fileName);
    string word;
    int index = 0;
    int totalNumWords = 0;
    int timesDoubled = 0;
    int valuesStored = 0;

    while(myFile >> word)
    { 
        bool result = isIgnoreWord(word, ignoreWords); 
        if (result == false)//check if unique word
        {
            totalNumWords++;
            if (totalNumWords == 1) //adding first word to array
            {
                record.word = word;
                record.count = 1;
                distinctWords[0] = record;
                valuesStored++;
            }
            else 
            {
                index = isDistinct(word, valuesStored, distinctWords);//function will return the index of the word if found
                if (index == -1)//it is a distinct word
                {
                    if (valuesStored == length)
                    {
                        timesDoubled++;
                        length = length * 2;//doubling the size
                        wordRecord * newArr = new wordRecord[length];
                        // write a simple for loop to copy stuff from distinctWords to newArr
                        for (int i = 0; i < length/2; i++)
                        {
                            newArr[i] = distinctWords[i];
                        }
                        delete[] distinctWords;
                        distinctWords = newArr;
                    }
                    record.word = word;
                    record.count = 1; 
                    distinctWords[valuesStored-1] = record;//adding to array     
                    valuesStored++;           
                }
                else //not a distinct word
                {
                    distinctWords[result].count += 1; //updating the count 
                }
            }
        }
    }
    int total = getTotalNumberNonIgnoreWords(distinctWords, length);
    cout << "Array doubled: " << timesDoubled << endl
    << "Distinct non-common words: " << valuesStored << endl
    << "Total non-common words: " << total << endl
    << "Probability of next 10 words from rank 25 " << endl
    << "---------------------------------------" << endl;
    sortArray(distinctWords, valuesStored);
    sortAlphabetically(distinctWords, valuesStored);
    printTenFromN(distinctWords, N, totalNumWords);
}
/*
function returns True if word is not distinct
*/ 
int isDistinct(string word, int valuesStored, wordRecord distinctWords[]) 
{
    int index = -1;
    for (int i = 0; i < valuesStored; i++)
    {
        if (distinctWords[i].word == word)//not distinct
        {
            return index;
        }
    }
    return index;

}
/*
Function reads the words from ignoreWords.txt and stores them in an array called ignoreWords
Does not return anything
*/
void getIgnoreWords(const char* ignoreWordFileName, string ignoreWords[]) 
{
    ifstream inFile(ignoreWordFileName);
    if (inFile.fail())
    {
        cout << "Failed to open " << ignoreWordFileName << endl; 
    }
    string word;
    int index = 0;
    while(inFile >> word)//reading each word in the file
    {
        ignoreWords[index] = word;//adding word to array
        index++;
    }
    inFile.close();
}
/*
Function returns whether word is found in the ignoreWords array
*/
bool isIgnoreWord(string word, string ignoreWords[])
{
    for (int i = 0; i < 50; i++)
    {
        if (ignoreWords[i] == word)
        {
            return true;
        }
    }
    return false;
}
/*
Function will sum the individual counts for each unique word and return the total number of distinct words
*/
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    int sum = 0;
    for (int i = 0; i< length; i++)
    {
        sum += distinctWords[i].count;
        length = length*2;
    }
    return sum;
}
/*
sort distinctWords array with most frequent words at the beginning
*/
void sortArray(wordRecord distinctWords[], int length)
{
    for (int i = 0; i< length-1; i++)
    {
        for (int j = i+1; j<length;j++)
        {
            if (distinctWords[i].count <  distinctWords[j].count)
            {
                swap(distinctWords[i], distinctWords[j]); 
                //swap(distinctWords[i].word, distinctWords[j].word);
            }
        }
    }
}
/*
sorts distinctWords alphabetically
*/
void sortAlphabetically(wordRecord distinctWords[], int length)
{
    for (int i = 0; i<length-1; i++)
    {
        for (int j = i+1; j<length;j++)
        {
            if (distinctWords[i].count == distinctWords[j].count)
            {
                string word1 = distinctWords[i].word;
                string word2 = distinctWords[j].word;
                if(word1 < word2)
                {
                    swap(word1, word2);
                    swap(distinctWords[i].count, distinctWords[j].count);
                }
            }
            
        }
    }
}
/*
prints ten words from index N and the probability of occurence
*/
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    for (int i = N; i < N+10; i++)
    {
        float probability = (float)distinctWords[i].count/totalNumWords;
        cout << fixed << setprecision(5) << probability << " - " << distinctWords[i].word << endl;
    }
}
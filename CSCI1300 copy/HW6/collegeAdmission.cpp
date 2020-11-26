// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework6- problem #3

#include<iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int split(string input, char separator, string arr[], int size); 

int main()
{
    // string fileName;
    // cout << "Enter the file name: "<< endl;
    // getline (cin, fileName);
    string line;

    ifstream in_file;
    in_file.open("superheroes_mini.txt");//open file
    
    //declaring variables
    string name;
    double GPA;
    int SAT, interest, quality, sem1, sem2, sem3, sem4;
    double overallScore;

    int numOfLines = 0;

    string arr[9];//declaring array used to store values  

    const int size= 6;//number of rows in array
    string array2d[size][9];
    int k =0;//to keep track of the number of rows

    if (in_file.is_open())
    {
        cout << " " << endl;
        cout << "Results: " << endl;
       while(getline(in_file, line))
        {
            numOfLines++;
            if (numOfLines != 1)//skip the first line
            {
                line = line + ',';
                int num = split(line, ',', arr, 9);//creating array to store string 

                    for (int j =0; j<num; j++)
                    {
                        array2d[k][j] = arr[j];//storing values in 2D array
                    }
                
                    //assigning values stored in array to the correct
                    name = array2d[k][0]; 
                    SAT = stoi(array2d[k][1]); //converting string to int
                    GPA = stod(array2d[k][2]); //converting string to double
                    interest = stoi(array2d[k][3]); 
                    quality = stoi(array2d[k][4]); 
                    sem1 = stoi(array2d[k][5]); 
                    sem2 = stoi(array2d[k][6]); 
                    sem3 = stoi(array2d[k][7]); 
                    sem4 = stoi(array2d[k][8]); 
                    
                    //normalizing GPA and SAT 
                    double GPA1=GPA*2.0;
                    double SAT1= SAT/160.0;
                    //calculating overall score
                    double overallScore= (0.4*GPA1) + (0.3*SAT1) + (0.2*quality) + (0.1* interest);
                    
                    if (overallScore >= 6)//Score criteria
                    {
                        cout << name << "," << overallScore << "," << "score" << endl; 
                    }

                    else if (overallScore >= 5)
                    {
                        if (interest == 0 || GPA1>SAT1+2)//Outlier criteria
                        cout << name << "," << overallScore << "," << "outlier" << endl;

                        else if (sem1< sem2 && sem2 < sem3 && sem3 < sem4)//Grade improvement criteria
                        cout << name << "," << overallScore << "," << "grade improvement" << endl;

                        else//not chosen, only prints name and score
                        cout << name << "," << overallScore << endl;
    
                    }
                    else cout << name << "," << overallScore << endl;//not chosen, score < 5

                    k++;//increment after setting the values to the variables
            }  
        }
    }

    else 
    {
        cout << "Could not open file." << endl;
    }
    
}

/*
function to find number of pieces in a string and fill array with those string pieces
parameters: string, separator, arr where string pieces are stored, size of array
return: number of pieces string is split into
*/
int split(string input, char separator, string arr[], int size)
{ 
    if (input == "")//if string is empty return 0
    {
        return 0;
    }
    int index = 0;
    int j = -1;
    int i=0;
    for (i = 0; i<input.length(); i++)
    {   
        if (input[i] == separator)
        {
            int length= i-j;
            if (index == size)
            {
                return -1;
            }
            arr[index] = input.substr(j+1,length-1);//j+1 because starts at 0
            index++;  
            j=i;//setting first position of substring to position of the last delimiter 
        }
    } 
    return index;
}
    

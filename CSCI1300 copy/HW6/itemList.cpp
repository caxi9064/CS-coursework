// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Homework6- problem #1

#include<iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    string fileName;
    cout << "Enter the file name: "<< endl;
    getline (cin, fileName);
    string line;

    ifstream in_file;//ifstream for input 
    in_file.open(fileName);//open file

    int numOfLines=0;

    int size = 10;
    string product_name[size];
    double price[size];
    int index1= 0;
    int index2= 0;

    if (!in_file.fail())//check to see if file opened
    {
       while (getline(in_file, line))
        {
            if (line != "")
            {   
                numOfLines++;
                for (int i = 0; i<line.length(); i++)//go through the entire line
                {
                    if (line[i] == ',')
                    {   //left side is numbers, start at 0
                        //right side is character values, start at i+1
                    
                        product_name[index2] = line.substr(0, i);//stores substring in array
                        index2++;//incrementing array size   
                        
                        price [index1] = stod (line.substr(i+1, line.length()-i));//converts string to double
                        //store values in array
                        index1++;   
                    }
                }
            }
        }
        cout << "The number of lines: " << numOfLines << endl;  

        double max = price [0];//declaring largest value in array
        string Max = product_name [0];
        double min = price [0];//declaring smallest value 
        string Min = product_name [0]; 
    
        for (int i = 0; i< index1; i++)//loop to go through the array
        {
            if (price[i]> max)//finding largest value
            {
                max = price [i];//setting max to largest value found
                Max= product_name [i];//both arrays have basically the same size
            }
        }
        for (int i = 0; i <index1; i++)
        {
            if (price[i]<min)//finding smallest value
            {
                min = price [i];
                // cout << min << endl;
                Min = product_name [i];
            }
        }
        cout << "The most expensive product: " << Max << endl;
        cout << "The least expensive product: " << Min << endl;
    }

    else
    {
        cout << "Could not open file" << endl; 
    }

    in_file.close();//close file
    
}

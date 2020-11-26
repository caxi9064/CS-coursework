// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #5
#include<iostream>
#include <string>
using namespace std;  
/*
function tests all 3 character sequences in the genome to find the highest similarity score
parameters:genome and sequence
return: highest sim score
*/
double findBestSimScore(string genome, string sequence)
{
    if (sequence.length() > genome.length())
    return 0;
    else 
    {
        double simScore;
        double highestSimScore =0;
        int hammingDistance=0;
        for (int i =0; i<= (genome.length()-sequence.length()); i++)
        //traversing length of the genome  
        {
            for (int j=0; j < sequence.length(); j++) 
            //traversing sequence 
            {
                if (sequence[j]!= genome[i+j])//i+j because comparing next character in each string
                hammingDistance++; 
            }
             simScore = ((sequence.length()-double (hammingDistance))/sequence.length());
             //hammingDistance is typecast as double because sequence length is integer

             hammingDistance =0; //resetting hammingDistance each time 
             if (simScore > highestSimScore)
             highestSimScore= simScore; //comparing sim score to previous highest score 
        }
        return highestSimScore; 
    }
}

int main()
{
    cout << findBestSimScore("ATACGC", "ACT") << endl; 
}
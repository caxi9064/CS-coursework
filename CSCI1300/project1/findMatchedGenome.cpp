// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #6
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
/*
this function does not print anything, it finds the highest sim score of each genome 
parameters: genome 1,2,3 and sequence   
prints the genome with the best match  
*/
void findMatchedGenome(string g1, string g2, string g3, string sequence2)
{
    if (g1 == "" || g2 == ""|| g3 == "" || sequence == "")
    {
        cout << "Genomes or sequence is empty." << endl; 
    }
    else if (g1.length() != g2.length() || g1.length() != g3.length())
    {
        cout << "Lengths of genomes are different." << endl; 
    }
    else //finds the highest score of each genome 
    //calls the function findbestsimscore to 
    {   double s1 = findBestSimScore(g1, sequence);
        double s2 = findBestSimScore(g2,sequence);
        double s3 = findBestSimScore(g3, sequence);
    //comparing the highest scores and printing the highest one 
        if (s1 >= s2 && s1 >= s3)
                cout << "Genome 1 is the best match." << endl;
            
        if (s2 >= s3 && s2 >= s1)
                cout << "Genome 2 is the best match." << endl;
            
        if (s3 >= s1 && s3 >= s2)
                 cout << "Genome 3 is the best match." << endl;
    }
}
int main()
{
    findMatchedGenome("AAA", "AAB", "AAC", "AB");//test case 1
    findMatchedGenome("AGCTAC", "AACCTT", "TTCAGT", "AGC");//test case 2
}
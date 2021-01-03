// CS1300 Fall 2020
// Author: Catherine Xiao
// Recitation: 326 - Sanskar Katiyar 
// Project1- problem #7
#include <iostream>
#include <string>
using namespace std;   

double calcSimScore (string s1, string s2);
double findBestSimScore(string genome, string sequence);
void findMatchedGenome(string g1, string g2, string g3, string sequence2);
//while user does not choose option 4, print menu and options 
//  if user chooses option 1, prompt user to input 2 string sequences 
//      display similarity score 
//  if user chooses option 2, prompt user for genome and sequence input
//      display best similarity score 
//  if user choose option, prompt user to input genome 1-3 and sequence
//      display the best match 
int main()
{   string s1,s2, genome, sequence, g1,g2,g3, sequence2; 
    int option = 0; 
    while (option != 4)
    {
    cout << "Select a numerical option: \n"
    << "=== menu ===\n" << "1. Find similarity score\n" << "2. Find the best similarity score\n"
    << "3. Analyze the genome sequences\n"<< "4. Quit" << endl; 
    cin >> option;

        if (option == 1)
        { 
            cout << "Enter sequence 1: \n";
            cin >> s1; 
            cout << "Enter sequence 2: \n";
            cin >> s2;
            cout << "Similarity score: " << calcSimScore(s1, s2) << endl;
        }

        if (option == 2)
        {
            cout << "Enter genome: \n";
            cin >> genome;
            cout << "Enter sequence: \n";
            cin >> sequence; 
            cout << "Best similarity score: " << findBestSimScore(genome, sequence) << endl;
        }
        if (option == 3)
        {
            cout << "Enter genome 1: \n";
            cin >> g1; 
            cout << "Enter genome 2: \n";
            cin >> g2;
            cout << "Enter genome 3: \n";
            cin >> g3;
            cout << "Enter sequence: \n";
            cin >> sequence2; 
            findMatchedGenome(g1, g2, g3, sequence2);
        }
        if (option > 4 || option < 1)
            cout << "Invalid option." << endl;
    }
    cout << "Good bye!" << endl;
    
}
double calcSimScore (string s1, string s2)
//if both sequences are equal in length 
//for each character in string 1 find the number of matches with string 2
//calculate the hamming distance and return similarity score 
//else return 0
{
    double hammingDistance = 0;
    double simScore;
    if (s1.length() == s2.length() && s1.length()!= 0) 
    {
        for (int i=0; i <= s1.length(); i++)
        {
            if (s1[i] != s2[i])
            hammingDistance++;
        }
        return simScore= (s1.length()-hammingDistance)/ s1.length(); 
    }
    else
    return 0;
}

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
void findMatchedGenome(string g1, string g2, string g3, string sequence2)
{
    if (g1 == "" || g2 == ""|| g3 == "" || sequence2 == "")
    {
        cout << "Genomes or sequence is empty." << endl; 
    }
    else if (g1.length() != g2.length() || g1.length() != g3.length())
    {
        cout << "Lengths of genomes are different." << endl; 
    }
    else //finds the highest score of each genome 
    //calls the function findbestsimscore to 
    {   double s1 = findBestSimScore(g1, sequence2);
        double s2 = findBestSimScore(g2,sequence2);
        double s3 = findBestSimScore(g3, sequence2);
    //comparing the highest scores and printing the highest one 
        if (s1 >= s2 && s1 >= s3)
                cout << "Genome 1 is the best match." << endl;
            
        if (s2 >= s3 && s2 >= s1)
                cout << "Genome 2 is the best match." << endl;
            
        if (s3 >= s1 && s3 >= s2)
                 cout << "Genome 3 is the best match." << endl;
    }
}
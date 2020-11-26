#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cctype>
using namespace std;   
//pseudocode:
//declare variables
//promt user for input and output file names
//open input files
//if files open
//  contacenate file content
//  write to output file 
//else print "failed"
//close file 

int main()
{
    //declare variables
    string fileName1;
    string fileName2;
    string outfileName; 

    ifstream file1; 
    ifstream file2;
    ofstream outfile; 

    //prompt user for file names
    cout << "Enter files to contacenate: " << endl;
    cin >> fileName1 >> fileName2; 

    cout << "Enter output file name : " << endl; 
    cin >> outfileName;

    //open files
    file1.open(fileName1); //ifstream fp1(filename1);
    file2.open(fileName2);
    outfile.open(outfileName); //ofsttream op(outfileName)

    if (file1.is_open()&&file2.is_open()&& outfile.is_open())//check to see if files opened successfully
    {
        //while(get(ch))
        //
        //  {
        //    outfile << ch;
        //  }
        //outfile << endl; 
        //read character by character 
        string line = "";
        while (getline(file1, line))
        {
            outfile << line << endl; 
        }
        line = "";
        while (getline(file2, line))
        {
            outfile << line << endl;
        }
        outfile.close();

    }
    else cout << "could not open files" << endl;
}

//pseudocode:
//prompt user for file names
//if file opens successfully 
//declare variables:  mostpopularperson= "", numberoffriends= 0; 
//  read each line input
//  for each line 
//      set persons name = substring to white space 
//
int main()
{
    string fileName;
    cout << "Enter file name: " << endl;
    cin >> fileName; 

    ifstream file;
    file.open(fileName);

    //declaring variables for storing data
    string line, mostpopularperson, currentperson;
    int mostpopularcount=0;
    int currentfriendcount=0; 
    if (!file.is_open())
    {
        cout << "File failed to open" << endl;
        return 0;
    }

    while (getline(file, currentperson, ' '))//read until space is encountered
    {
        getline (file, line)//read line by line
        int comma_count = 0;

        for (int i =0; i <line.length(); i++)
        {
            if (line[i]==',')
            comma_count ++;
            currentfriendcount= comma_count +1;
        }
        if (currentfriendcount > mostpopularcount)
        {
            mostpopularcount = currentfriendcount;
            mostpopularperson = currentperson; 
        }
    }

}

int main()//min and max values using limits
{
    int min_int = numeric_limits<int>::min;
    int max_int = numeric_limits<int>::max;

    double min_int = numeric_limits<double>::min;
    double max_int = numerics_limits<double>::max;

    return 0;
}

int main()
{
    
int main()
{
   char ch;
   int n;
   ifstream in_file;
   in_file.open("products.txt");
   while (in_file.get(ch))
   {
      if (isdigit(ch))
      {
         in_file.unget();//unget character 
         in_file >> n;
         cout << n;
      }
   }
   return 0;
}

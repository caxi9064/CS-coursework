#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct studentData
{
    string studentName;
    int homework;
    int recitation; 
    int quiz;
    int exam; 
    double average;
};
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);
char calcLetter(double avg);
void printList(const studentData students[], int length);
int main(int argc, char* argv[])
{
    studentData students[50]; //declaring students array
    string inputFile = argv[1];
    string outputFile = argv[2];
    string lower_bound = argv[3];
    string upper_bound = argv[4];

    string line;
    ifstream myFile(inputFile);
    string studentName, homework, recitation, quiz, exam;
    int length = 0;

    while(getline(myFile, line))//reading each line of csv file
    {
        stringstream ss(line); //creating string object to get student info
        getline(ss, studentName, ',');
        getline(ss, homework, ',');
        getline(ss, recitation, ',');
        getline(ss, quiz, ',');
        getline(ss, exam, ',');
        
        addStudentData(students, studentName, stoi(homework), stoi(recitation), stoi(quiz), stoi(exam), length++); //updates student info
    }
    myFile.close();

    printList(students, length);//calling printList function

    ofstream outFile(outputFile);//writing to output file
    for (int i = 0; i<length; i++)
    {
        char letterGrade = calcLetter(students[i].average);
        int num = letterGrade;
        int lower = lower_bound[0]; 
        int upper = upper_bound[0];
        if (num <= lower && num >= upper) 
        {
            outFile << students[i].studentName << "," << students[i].average << "," << letterGrade << endl;
        }
    }
    outFile.close();
}
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length)
{
    studentData p1; //declaring a structure variable 
    p1.studentName = studentName;
    p1.homework = homework;
    p1.recitation = recitation; 
    p1.quiz = quiz;
    p1.exam = exam; 
    p1.average = (homework+recitation+quiz+exam)/4.0;
    students[length] = p1; //adding structure to students array
}
//function returns letter grade based on average score 
char calcLetter(double avg) 
{
    if (avg >= 90)
    {
        return 'A';
    }
    else if (avg >= 80 && avg <= 89.9)
    {
        return 'B';
    }
    else if (avg >= 70 && avg <= 79.9)
    {
        return 'C';
    }
    else if (avg >= 60 && avg <= 69.9)
    {
        return 'D';
    }
    return 'F';
}
//function prints the name and average grade of each students in the students array
void printList(const studentData students[], int length) 
{
    for(int i = 0; i < length; i++)
    {
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;
    }
}
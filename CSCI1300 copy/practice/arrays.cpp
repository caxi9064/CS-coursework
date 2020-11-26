#include<iostream>
#include <iostream>
using namespace std;   
int main()
{
    //filling array with zeroes 
    double values[10];
    for (int i=0; i <10; i++)
    {
         values[i]=0;
    }
    //copying arrays 
    int luckyNumbers[5];
    int squares[]={3,4,5,6,7};
    for (int i=0;i<5;i++)
    {
        luckyNumbers[i] = squares[i]; 
    }
    //sum and average 
    double values[5]={1,2,3,4,5};
    double total=0;
    const double size=4;
    for (int i=0;i<size;i++)
    {
        total = total + values [i]
    }
    double average = total/size;

    //maximum/minimum
    double largest = values[0];
    for (int i =1; i < size of values; i++)
    {
        if (values[i]>largest)
        {
            largest = values[i];
        }
    }

}

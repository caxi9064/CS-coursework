#include<iostream>
using namespace std;   
int main()

//example of a function 

double cube_volume(double side_length)
//definition of cube volume 
    {
        if (side_length < 0) {return 0;}
        double volume = side_length * side_length * side_length;
        return volume;
    }
int main()
{
    double result1 = cube_volume (2);
    double result2 = cube_volume (10) ;
    cout << "A cube with side length 2 has volume "  << result1 << endl;
    cout << "A cube with side length 10 has volume " << result2 << endl;
 
    return 0;
}


//functions WITHOUT return values
//prints string in a box
//param str the string to print 

void box_string(string str)
{
    int n = str.length();
    for (int i = 0; i < n + 2; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "!" << str << "!" << endl;
    for (int i =0; i <n+2;i++)
    {
        cout << "-" ;
    }
    cout << endl;
}//does not computer any value , no need for return statement 

#include<iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
using namespace std;

void dotsAndDashes(int n);
int main()
{
    int n = 6;
    dotsAndDashes(6);

}
void dotsAndDashes(int n)
{
  for (int i =1 ; i <n; i++)
  {
    for(int j=0; j<i; j++)
    {
      if(i%2==0)
      {
        cout<<"-";
      }
      else
      {
        cout<<".";
      }
    }
    cout << endl;
  }
}
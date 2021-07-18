/*
CSCI 2270 - Spring 2021
Midterm 1
Question 1 starter code.

*/


#include <iostream>

using namespace std;

/*
    * TODO your function header goes here
*/
void trim (int * &a0, int &length, int value);

void testPrint(int *p0, int length);

int main(){
   
    int a_test[] = {3, 2, 5 ,1, 0, 8, 4};
    int test_length = 7;
   
   
    /*
    Test 1
    */
    cout << "\n---------------------\n";
    
    int * a0 = new int[test_length];
    for(int i = 0; i<test_length; i++){
        a0[i] = a_test[i];
    }

    int target = 0; 
    
    /*
        * TODO your function call goes here. It should look like:
    */ 
   
    trim(a0, test_length, target);

    cout << "Test 1: \n"  << "expected >> 3 2 5 1 " << endl;
    testPrint(a0, test_length);
    delete [] a0;

    return 0;
}
/*
    * TODO your function definition goes here
*/
//takes array, length, and a target value
//reference to pointer: pointer itself is changed
void trim (int * &a0, int &length, int value)
{
    if (length != 0)//if array not empty
    {
        for (int i = 0; i < length; i++) //traverse array
        {
            if (a0[i] == value)//if value is found
            {
                length = i;
            }
            //no changes to array if target value not found
        }
    }
    //create new array and copy over values from the old array
    int *tempArr = new int[length];
    for (int i = 0; i < length; i++)
    {
        tempArr[i] = a0[i];
    }
    delete [] a0;//deallocate old array
    a0 = tempArr;
}
void testPrint(int *p0, int length){
    
    cout << "result   >> ";

    for(int i = 0; i<length; i++){
        cout << p0[i] << " ";
    }
    cout << "\n---------------------\n\n" << endl;
}
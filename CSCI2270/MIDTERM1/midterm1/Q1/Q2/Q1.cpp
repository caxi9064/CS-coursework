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
void trim (int *array, int length, int value);

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
void trim (int *array, int length, int value)
{
    //if array not empty
    if (length != 0)
    {
        //traverse array
        for (int i = 0; i < length; i++)
        {
            if (array[i] == value)//if value is found
            {
                //removing all elements from first occurence of target and rest of array
                for (int j = i; j<length;j++)
                {
                    array[j] = NULL;//deallocate memory elements 
                }
            }
            //no changes to array if target value not found
        }
    }
}
void testPrint(int *p0, int length){
    
    cout << "result   >> ";

    for(int i = 0; i<length; i++){
        cout << p0[i] << " ";
    }
    cout << "\n---------------------\n\n" << endl;
}
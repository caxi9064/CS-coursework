#include <iostream>
#include "StackCalculator.hpp"
#include <string>

using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  //TODO:
  stackHead = NULL;
}

StackCalculator::~StackCalculator()
{
  //TODO:
  Operand* current = stackHead;
  Operand* prev = NULL;
  while(current != NULL)//traverse list and delete everything 
  {
    prev = current;
    current = current->next;
    delete prev;
  }
}

bool StackCalculator::isEmpty()
{
	//TODO:
  return (stackHead == NULL);
}

void StackCalculator::push(float number)
{
  //TODO:
  if (isEmpty())
  {
    Operand* firstNode = new Operand;//allocate new node
    firstNode -> number = number; //setting value 
    firstNode -> next = NULL;
    stackHead = firstNode; //setting head node

  }
  else
  {
    Operand* prevNode = stackHead;
    Operand* newNode = new Operand;//allocate new node
    newNode -> number = number;
    newNode -> next = prevNode;//adding element to beginning of list
    stackHead = newNode; //setting head to new node
  }
}

void StackCalculator::pop()
{
	//TODO:
  if(isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else
  {
    //create pointer to store location of top of the list
    Operand* temp = stackHead;
    //set head to the next element in stack
    stackHead = stackHead->next;
    //remove element from top
    delete temp;
  }
}

Operand* StackCalculator::peek()
{
	//TODO:
  if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
  }
  else
  {
    return stackHead;
  }
  return nullptr;// remove this line if you want
}


bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
    float result = 0;
    for (int i = size-1; i >= 0; i--)
    {
      if (isNumber(*(s+i)) == true)//is number, dereferencing to get value in array
      {
        float n = stof(*(s+i));
        push(n);//pushing number to stack
      }
      else //not a number
      {
        if (s[i] == "*" || s[i] == "+")
        {
          if (isEmpty() || stackHead->next == NULL)//if there aren't enough operands
          {
            cout << "err: not enough operands" << endl;
            return false;
          }
          //do operation and return result
          float num1 = stackHead->number;
          float num2 = stackHead->next->number;
          if (s[i] == "*")
          {
              result = num1 * num2;
          }
          else if (s[i] == "+")
          {
            result = num1 + num2;
          }
          pop();
          pop();
          push(result);
        }
        else // operator not valid
        {
          cout << "err: invalid operation" << endl;
          return false;
        }
      }
    }
    if(stackHead->next != NULL)//there are leftover operands
    {
      cout << "err: Invalid expression " << endl;
      return false;
    }
	return true;
}
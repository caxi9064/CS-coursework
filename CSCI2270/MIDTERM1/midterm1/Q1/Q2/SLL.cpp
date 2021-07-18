#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
	Node* crawler;

	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}


void SLL::displayList(){
	Node* crawler = head;
	while( crawler != nullptr ){
		cout << crawler->key << "->";
		crawler = crawler->next;
	}

	cout << "END" << endl;
}


void SLL::insert(Node* afterMe, char newValue){

	if(head == nullptr){
		// first case: empty list
		// add new node and make head point to it
		head = new Node;
		head->key = newValue;
		head->next = nullptr; // what if we forget this line?
	}
	else if(afterMe == nullptr){
		// This condition implies that the list is not empty, but
		// the caller wants to add node before the head node
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = head;
		head = newNode;
		// at this point, we can test our code for this use case

	}
	else{
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = afterMe->next;
		afterMe->next = newNode;
	}


}
//returns true if sequence of char is a palindrome
bool SLL::palindrome(){
/*
    * TODO your function definition goes here
*/
	Node* temp = head;
	//if list is empty or only has one node then it is a palindrome
	if (temp == NULL || temp -> next == NULL)
	{
		return true;
	}
	else
	{
		int totalNodes= 1;
		Node* temp1 = head;
		while(temp1->next != NULL)// traverse list and store it in another linked list
		{
			temp1 = temp1->next;
			totalNodes++;
		}
		int lastIndex = totalNodes-1;
		if (totalNodes%2 == 0)//even list
		{
			for (int i = 0; i < totalNodes/2 ;i++)
			{
				if (atIndex(i) != atIndex(lastIndex-i))
				{
					return false;
				}
			}
		}
		else//odd list
		{
			int midIndex = (totalNodes-1)/2;
			for (int i = 0; i < midIndex; i++)
			{
				if (atIndex(i) != atIndex(lastIndex-i))//not a palindrome
				{
					return false;
				}
			}
		}
	}
	return true;
}
//function returns char at index i of list
char SLL::atIndex(int i){
	int maxindex = 0;
	Node* currentNode = head;
	while(currentNode-> next != NULL)
	{
		currentNode = currentNode->next; //traversing the list
		maxindex++;//getting the max index
	}
	if (i > maxindex || i < 0)//if not a valid index, return null char
	{
		cerr << "invalid index" << endl;
		return '\0';
	}
	else//index is valid
	{
		int currentIndex = 0; 
		Node* current = head;
		while(currentIndex != i)
		{
			current = current->next;
			currentIndex++;
		}
		return current->key;//return char found at correct index
	}
}




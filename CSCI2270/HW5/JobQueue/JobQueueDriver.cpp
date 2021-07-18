/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include "JobQueue.hpp"
#include <iostream>
// you may include more libraries as needed
using namespace std;

JobQueue::JobQueue()//constructor
{
	int queueFront = 0;
	int queueEnd = 0;
	int counter = 0;
}
bool JobQueue::isEmpty()
{
	return(counter == 0);
}
bool JobQueue::isFull()
{
	return(counter == SIZE);
}
void JobQueue::enqueue(string job)
{
	if (!isFull())
	{
		queue[queueEnd] = job;//adding to queue
		counter++;
		//edge case for circular array: array not full, but tail is at the end
		if (queueEnd == SIZE-1)//wrapping around to the front
		{	
			queueEnd = 0;
		}	
		else queueEnd++;
	}
	else
	{
		cout << "Queue full, cannot add new job " << endl;
	}
}
void JobQueue::dequeue()
{
	if (!isEmpty())
	{
		queue[queueFront] = "";
		counter--;
		if (queueFront == SIZE-1)
		{
			queueFront = 0;
		}
		else queueFront++;
	}
	else
	{
		cout << "Queue empty, cannot dequeue a job " << endl;
	}
}
int JobQueue::queueSize()
{
	return counter;
}
string JobQueue::peek()
{
	if (isEmpty())
	{
		cout << "Queue empty, cannot peek " << endl;
		return "";
	}
	else
	{
		return queue[queueFront];
	}
}
/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
int main(int argc, char const *argv[])
{
	menu();
	string input;
	getline(cin, input); //get user input
	int option = stoi(input);
	JobQueue q;
	while(option != 3)
	{
		switch(option)
		{
			case 1: //enqueue
			{
				cout << "Enter the number of jobs to be created: " << endl;
				getline(cin, input);//getting num of jobs to be created from user 
				int temp = 0;
				int numJobs = stoi(input);
				while(temp < numJobs)
				{
					cout << "job" << temp+1 << ":" << endl; 
					getline(cin, input);//getting job to be created
					q.enqueue(input); //enqueuing job
					temp++;
				}
			}break;
			case 2: //dequeue
			{
				cout << "Enter the number of jobs to be dispatched: " << endl;
				getline(cin, input);
				int temp = 0;
				int numJobs = stoi(input);
				while(temp < numJobs)
				{
					if(!(q.isEmpty()))
					{
						cout << "Dispatched: " << *(q.getQueue() + q.getQueueFront()) << endl;
						q.dequeue();
					}
					else
					{
						cout << "No more jobs to be dispatched from queue " << endl;
						break;
					}
					temp++;
				}
			}break;
			case 3: break;//return queue size and exit
			default: break;
		}
        menu();
     	getline(cin, input);
     	option = stoi(input);
	}
	cout << "Number of jobs in the queue:" << q.queueSize() << endl;

}
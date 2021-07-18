/*******************************************************************/
/*                CUBuildingNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*       This class uses a linked-list of CUBuilding nodes to      */
/*       represent communication paths between buildings           */
/*******************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the CUBuilding *previous and the CUBuilding that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    if (previous == NULL)
    {
        cout << "adding: " << buildingName << " (HEAD) " << endl;
        CUBuilding *newNode = new CUBuilding; //creating a new node
        newNode-> name = buildingName; //setting name of new node
        newNode-> totalRoom = numOfroom;
        newNode-> next = head; 
        head = newNode; //make head the newNode
    }
    else
    {
        cout << "adding: " << buildingName << " (prev: " << previous -> name << ")" << endl;
        CUBuilding *x = new CUBuilding; //creating new node dynamically
        x-> name = buildingName; //setting name of building
        x-> totalRoom = numOfroom;
        x-> next = previous-> next; //x will point to node that the previous pointer was pointing to
        previous-> next = x;//previous node will point to x
    }
}
/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    string buildingInfo[6] = {"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT"};
    int roomInfo[6] = {2,10, 6, 5, 4, 9};
    
    CUBuilding *previous = NULL;
    addBuildingInfo(previous, buildingInfo[0], roomInfo[0]);
    previous = head;
    for (int i = 1; i < 6; i++)
    {
        addBuildingInfo(previous, buildingInfo[i], roomInfo[i]);
        previous = previous-> next;
    }
}
/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    // Complete the function
    CUBuilding* currentNode = head;
    while(currentNode != NULL && currentNode->name != buildingName)
    {
        currentNode = currentNode->next;
    }
    if (currentNode == NULL)
    {
        return NULL;
    }
    else if (currentNode-> name == buildingName)
    {
        return currentNode;
    }
}
/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    CUBuilding* currentNode = head;
    if (isEmpty() == true)
    {
        cout << "Empty list" << endl;
        return;
    }
    CUBuilding* node = searchForBuilding(receiver);//return pointer to node if receiver is found
    if (node == NULL)//receiver node is not found
    {
        cout << "Building not found" << endl;
        return;
    }
    while(currentNode->name != receiver)
    {
        currentNode->message = "available room at " + currentNode->name + " is " + to_string(currentNode->totalRoom);
        currentNode->numberMessages += 1;
    
        cout << currentNode->name << " [# messages received: " << currentNode->numberMessages <<
        "] received: " << currentNode->message << endl;
        
        currentNode = currentNode->next;
    }
    if (currentNode->name == receiver)
    {
        currentNode->message = "available room at " + currentNode->name + " is " + to_string(currentNode->totalRoom);
        currentNode->numberMessages += 1;
    
        cout << currentNode->name << " [# messages received: " << currentNode->numberMessages <<
        "] received: " << currentNode->message << endl;
        currentNode = currentNode->next;
        
    }
}
/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    CUBuilding* currentNode = head;
    cout << "== CURRENT PATH ==" << endl;
    if (isEmpty() == true)
    {
        cout << "nothing in path" << endl << "===" << endl; 
    }
    else
    {
        while(currentNode != NULL)
        {
            cout << currentNode->name << "(" << currentNode->totalRoom << ")" << " -> ";
            currentNode = currentNode->next;
        }
        cout << "NULL" << endl << "===" << endl;
    }
}


/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the CUBuilding in the network with the specified name.
 * @param buildingName name of the CUBuilding to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName) 
{
    // TODO: Complete this function
    CUBuilding* currentNode = head;
    CUBuilding* previous = NULL;
    if (head->name == buildingName)
    {
        head = head->next;
        delete currentNode;//deleting head node
    }
    else
    {
        while(currentNode != NULL && currentNode->name != buildingName)
        {
            previous = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == NULL){
            cout << "Building does not exist." << endl;
        }
        else if (currentNode->name == buildingName)
        {
            previous->next = currentNode->next; //previous is now pointing to the node after the one to be deleted
            delete currentNode; //deleting node
        }
    }

}

/*
 * Purpose: deletes all CUBuildings in the network starting at the head CUBuilding.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    if (isEmpty()){
        return;
    }
    else{ // delete entire list
        CUBuilding* currentNode = head->next;
        CUBuilding* previous = head;
        while(currentNode != NULL)
        {
            cout << "deleting: " << previous->name << endl;
            delete previous;
            previous = currentNode;
            currentNode = currentNode->next;
            if (currentNode == NULL)
            {
                cout << "deleting: " << previous->name << endl; //deleting last node
                delete previous;
                cout << "Deleted network" << endl;
                head = NULL;
            }
        }
    }
}

/*
* Purpose: Creates a loop from last node to the CUBuilding specified.
* @param buildingName name of the CUBuilding to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding* CUBuildingNetwork::createLoop(string buildingName) 
{
    // TODO: Complete this function
    CUBuilding* node = head;
    CUBuilding* prev = NULL;
    CUBuilding* temp = NULL;

    while(node->next != NULL)
    {
        prev = node;
        node = node->next;
        if (node->name == buildingName)
        {
            temp = node;
        }
    }
    if(node == NULL)
    {
        //building name not found
        return node; 
    }
    else 
    {
        node->next = temp;
    }
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUBuildingNetwork::detectLoop() 
{
    CUBuilding* s = head;
    CUBuilding* f = head;
    while(f->next->next != NULL)
    {   
        s = s->next;
        f = f->next->next;
        if (s == f)
        {
            return true;
        }
    }
    return false;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk to the end of the List
 * @param: start_index, end_index
 * @return: none
 */
void CUBuildingNetwork::readjustNetwork(int start_index, int end_index)
{
    // TODO: Complete this function
    if (isEmpty())
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    else 
    {
        int index = 0;
        CUBuilding* temp = head;
        while (temp->next != NULL)
        {
            index++;
            temp = temp->next;
        }
        if (end_index >= index || end_index < 0)
        {
            cout << "Invalid end index" << endl;
            return;
        }
        else if (start_index >= index || start_index < 0)
        {
            cout << "Invalid start index" << endl;
            return;
        }
        else if(start_index > end_index)
        {
            cout << "Invalid indices" << endl;
            return;
        }
    } 
    //traverse the linked list
    //find node at start_index and end_index
    //store previous node before start_index and node at the end before NULL
    CUBuilding* prev = NULL;
    CUBuilding* start = NULL;
    CUBuilding* end = NULL;
    CUBuilding* nodeAfterEnd = NULL;
    CUBuilding* temp1 = head;
    CUBuilding* temp2 = head;
    CUBuilding* lastNode = head;
    if (start_index == 0)
    {
        start = head;
    }
    else
    { 
        for (int i = 0; i < start_index; i++)
        {
            prev = temp1;
            temp1 = temp1->next;
        }
        start = temp1;
    }
    for (int i = 0; i < end_index; i++)
    {
        temp2 = temp2->next;
    }
    end = temp2;
    nodeAfterEnd = temp2->next;

    while(lastNode->next != NULL)//getting last node of linked list
    {
        lastNode = lastNode->next;
    }
    lastNode->next = start;//last node will point to the node at start_index
    end->next = NULL;//end node points to null
    if (start_index == 0) 
    {
        head = nodeAfterEnd;
    }
    else
    {
        prev->next = nodeAfterEnd;//setting node at beginning of list to last node in list
    }
}

/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUBuildingNetwork::~CUBuildingNetwork()
{
    // TODO: Complete this function

}

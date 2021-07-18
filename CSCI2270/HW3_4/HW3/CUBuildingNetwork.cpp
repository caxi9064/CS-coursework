/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
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
 *   between the building *previous and the Building that follows it in the network.
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

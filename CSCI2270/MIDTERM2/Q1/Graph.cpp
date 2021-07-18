#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 * adds a vertex to the graph
 */
void Graph::addVertex(int n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->key == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->key = n;
        vertices.push_back(v);
    }
}

/*
 * adds an edge between two vertices (directed graph)
 */
void Graph::addEdge(int src, int dest){
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->key == src) {
            for(int j = 0; j < vertices.size(); j++) {
                if(vertices[j]->key == dest && i != j) {
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

/*
 * Complete the following function which checks if vert is a boss vertex
 */
bool Graph::isVertexABoss(vertex *vert) {
    //breadth first traversal to see if all values can be reached
    // for (int i = 0; i < vertices.size();i++)//find index in vertices of vert
    // {
    //     if(vertices[i]->key == vert->key)
    //     {
    //         idx = i;
    //     }
    // }
    
    vertex* temp = NULL;
    queue<vertex*>q;//queue holds visited nodes index in vertices vector
    vert->visited = true;
    q.push(vert);
    int count = 0;//keep track of all visited nodes
    count++;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int j = 0; j < temp->adj.size();j++)
        {   
            if (temp->adj[j].v->visited != true)//not visited so add to queue
            {
                temp->adj[j].v->visited = true;
                q.push(temp->adj[j].v);
                count++;
            }
        }
    }
    // cout << count << endl;
    // cout << vertices.size() << endl;
    if (vertices.size()==count)
    return true;
    else return false;
}

/*
 * Complete the following function which checks if the graph is a Boss
 */
bool Graph::isGraphABoss() {
    //for each vertex if isVertex is true
    for (int i = 0; i < vertices.size();i++)
    {
        if (isVertexABoss(vertices[i]) == true)//if just one vertex can reach all the other then return true
        {
            return true;
        }
    }
    return false;
}

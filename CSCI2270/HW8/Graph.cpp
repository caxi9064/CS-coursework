#include <Graph.hpp>
#include <string>
#include <queue>
using namespace std;

void Graph::addVertex(string n)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == n)
        {
            found = true;
        }
    }
    if (found == true)
    {
        vertex *v = new vertex;//creating new vertex
        v->name = n;
        vertices.push_back(v);
    }
}
void Graph::addEdge(string s1, string s2)
{
    //find v1 and v2
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == s1)
        {
            for (int j = 0; j < vertices.size(); j++)
            {
                if (vertices[j]->name == s2)//if exist then add edge
                {
                    adjVertex adjV1; //creating adj vertex for both nodes
                    adjVertex adjV2;
                    adjV1.v = vertices[j]; 
                    adjV2.v = vertices[i];
                    vertices[i]->adj.push_back(adjV1);//adding adj vertex          
                    vertices[j]->adj.push_back(adjV2);//adding adj vertex          
                }
            }
        } 
    }
}
void Graph::displayEdges()
{
    for (int i = 0; i < vertices.size(); i++)
    {   
        cout << vertices[i]->name << " --> ";
        for (auto j = vertices[i]->adj.begin(); j < vertices[i]->adj.end(); j++)
        {
            cout << j->v->name << " "; // j is pointer to adj vertex, v is pointer to vertex
        }
        cout << endl;
    }
}
void Graph::breadthFirstTraverse(string sourceVertex)
{
    queue<vertex*> q;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == sourceVertex)
        {
            cout << "Starting vertex (root): " << vertices[i]->name << "-> ";
            vertices[i]->visited = true;
            q.push(vertices[i]);
        }
    }
    vertex* temp;   
    while(!q.empty())
    {
        temp = q.front();
        q.pop();//already visited
        for(auto adjN = temp->adj.begin(); adjN < temp->adj.end();adjN ++)//push adjacent nodes
        {
            if (adjN->v->visited != true)
            {
                adjN->v->visited = true;
                adjN->v->distance = temp->distance + 1;
                q.push(adjN->v);
                cout << adjN->v->name << "(" << adjN->v->distance << ")" << " ";
            } 
        }
    }
}
void dfs(vertex* temp)
{
    temp->visited = true;
    for(int i = 0; i < temp->adj.size();i++)
    {
        if (temp->adj[i].v->visited == false)//visit all adj nodes depth first
        {
            dfs(temp->adj[i].v);
        }
    }
    
}
int Graph::getConnectedBuildings()
{
    int connected =0;
    for (int i = 0; i < vertices.size();i++)
    {
       if((vertices[i])->visited == false)//if true then that means vertice[i] is part of already connected component and not a separate component
       {
           dfs(vertices[i]);//depth first traversal
            connected++;
       }
    }
    return connected;
}
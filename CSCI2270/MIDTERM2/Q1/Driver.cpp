#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;

int main()
{
    /* Not a Boss graph: graph with no boss vertices    
     * (Example A. in write-up)
     */
    Graph g1;
    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addVertex(4);
    g1.addVertex(5);
    g1.addVertex(6);
    g1.addEdge(1, 2);
    g1.addEdge(2, 5);
    g1.addEdge(3, 1);
    g1.addEdge(4, 3);
    g1.addEdge(4, 5);
    g1.addEdge(6, 5);

    if(g1.isGraphABoss() == false)
        cout << "Test1: passed" << endl;
    else
        cout << "Test1: failed" << endl;

    /* Boss graph: graph with atleast one boss vertex
     * (Example B. in write-up)
     */
    Graph g2;
    g2.addVertex(1);
    g2.addVertex(2);
    g2.addVertex(3);
    g2.addVertex(4);
    g2.addVertex(5);
    g2.addVertex(6);
    g2.addEdge(1, 2);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    g2.addEdge(4, 5);
    g2.addEdge(5, 2);
    g2.addEdge(5, 6);
    
    if(g2.isGraphABoss() == true)
        cout << "Test2: passed" << endl;
    else
        cout << "Test2: failed" << endl;

    //my own test cases
    Graph g3;
    g3.addVertex(55);//only one vertex

    if(g3.isGraphABoss() == true)
        cout << "Test3: passed" << endl;
    else
        cout << "Test3: failed" << endl;

    Graph g4;
    g4.addVertex(1);//neither 1 or 2 will reach 3
    g4.addVertex(2);
    g4.addVertex(3);
    g4.addEdge(1, 2);
    g4.addEdge(2, 1);
  
    if(g4.isGraphABoss() == false)
        cout << "Test4: passed" << endl;
    else
        cout << "Test4: failed" << endl;
        
    return 0;
}

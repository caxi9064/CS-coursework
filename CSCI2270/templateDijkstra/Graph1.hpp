#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct Vertex {  // Node 
  string name; /* name of the vertex */
  vector<int> edges; /* edge list as a vector of ids of vertices */
  vector<int> weights; // weights of the edges
  bool visited;  /* useful to label visited vertices */ 
  int distance; /* useful to compute distance from a certain vertex */
};

class Graph {
private:
  vector<Vertex *> vertices; /* set of vertices/node  */ 
  
public:
  void add_vertex(string u);
  void add_edge(string u, string v);
  void add_edge(string u, string v, int w);

  void pretty_print();
  void dfs(string u); /* depth first traversal */

  void bfs(string u); /* breadth-first traversal */
  void bfs(string src, string tar); /* bfs */
  void dijkstra(string src) ; // Dijkstra's shortest path algorithm
  
private:
  int str2idx(string u); /* returns id of a vertex given name, -1 if absent */
  string idx2str(int id); /* returns name of a vertex given index, " " if absent */
  void dfs_helper(int u);

};


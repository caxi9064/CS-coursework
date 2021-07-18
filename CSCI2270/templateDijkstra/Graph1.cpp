#include<iostream> 
#include "Graph1.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <algorithm> // Talk about it..
#include<climits>

using namespace std;

int Graph::str2idx(string u) {
  for (int i = 0; i < vertices.size(); ++i) {
    if (vertices[i]->name == u) return i; //returns index of vertex in vector of vertices if found 
  }

  return -1;
}

string Graph::idx2str(int u_id) {
  if (u_id < vertices.size() && u_id >= 0) 
    return vertices[u_id]->name; //return name of vertex given index in vector
  else {
    cerr << "index out of range" << endl;
    return "";
  }
}

void Graph::add_vertex(string u) {
    if (str2idx(u) == -1) {
      Vertex* tmp = new Vertex; //creating new vertex 
      tmp->name = u;
      tmp->distance = -1;
      tmp->visited = false;
      vertices.push_back(tmp); //add to vector
    }
    else 
      cerr << "Vertex already present!" << endl;
}

void Graph::add_edge(string u, string v) {
  //Assume undirected graph 
  //u->v then v->u
  int u_id = str2idx(u);
  int v_id = str2idx(v);

  //test if vertex u and v are present 
  if (u_id == -1 || v_id == -1) {
    cerr << "One of the vertex does not exist" << endl;
    return;
  }
  else {

    // add the vertex v_id to the adjacency list vertices[u_id]->edges
  // go to index corresponding to node u and add an edge to node v ..
  auto it = find(vertices[u_id]->edges.begin(), vertices[u_id]->edges.end(), v_id);

  if (it == vertices[u_id]->edges.end()) {//if pointer is pointing to next to last element in vector of edges
    vertices[u_id]->edges.push_back(v_id);
    vertices[u_id]->weights.push_back(1);
  }
  else {
    cerr << "Edge already exists" << endl;
  }

  // go to index corresponding to node u and add an edge to node v ..
  it = find(vertices[v_id]->edges.begin(), vertices[v_id]->edges.end(), u_id);

  if (it == vertices[v_id]->edges.end()) {
    vertices[v_id]->edges.push_back(u_id);
    vertices[v_id]->weights.push_back(1);
  }
  else {
    cerr << "Edge already exists" << endl;
  }

  return;
  }
}

void Graph::add_edge(string u, string v, int w) {
  //Assume undirected graph 
  //u->v then v->u
  int u_id = str2idx(u);
  int v_id = str2idx(v);

  //test if vertex u and v are present 
  if (u_id == -1 || v_id == -1) {
    cerr << "One of the vertex does not exist" << endl;
    return;
  }
  else {

    // add the vertex v_id to the adjacency list vertices[u_id]->edges
  // go to index corresponding to node u and add an edge to node v ..
  auto it = find(vertices[u_id]->edges.begin(), vertices[u_id]->edges.end(), v_id);

  if (it == vertices[u_id]->edges.end()) {
    vertices[u_id]->edges.push_back(v_id);
    vertices[u_id]->weights.push_back(w);
  }
  else {
    cerr << "Edge already exists" << endl;
  }

  // go to index corresponding to node u and add an edge to node v ..
  it = find(vertices[v_id]->edges.begin(), vertices[v_id]->edges.end(), u_id);

  if (it == vertices[v_id]->edges.end()) {
    vertices[v_id]->edges.push_back(u_id);
    vertices[v_id]->weights.push_back(w);
  }
  else {
    cerr << "Edge already exists" << endl;
  }

  return;
  }
}

void Graph::pretty_print() {
  for (int i = 0; i < vertices.size(); i++) {
    cout << vertices[i]->name << " --> ";
    for (int j = 0; j < vertices[i]->edges.size(); j++) {
      cout << idx2str(vertices[i]->edges[j]) << ", "; 
    }
    cout << endl;
  }
}


void Graph::dfs_helper(int u_id) {
  vertices[u_id]->visited = true;
  cout << vertices[u_id]->name << " ";  

  for (int i = 0; i < vertices[u_id]->edges.size(); i++) { // for all edges for a vertex
    int succ = vertices[u_id]->edges[i]; //edges contains id of vertices connected to node
    if (!vertices[succ]->visited) //if not visited then recursively search 
      dfs_helper(succ);
  }
}

void Graph::dfs(string u) {
  for (int i = 0; i < vertices.size(); i++) 
    vertices[i]->visited = false; 

  cout << " DFS search"<<endl; 
  dfs_helper(str2idx(u));  
  cout << endl;
}

void Graph::bfs(string src) {
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i]->visited = false;
    vertices[i]->distance = -1;
  }

  queue<int> waiting;
  int s = str2idx(src); 

  vertices[s]->visited = true;
  vertices[s]->distance = 0;

  waiting.push(s);


  while (!waiting.empty()) { //while queue not empty 
    int u = waiting.front();
    waiting.pop();//pop visited nodes

    cout << vertices[u]->name << "[" << vertices[u]->distance << "] ";

    for (auto it = vertices[u]->edges.begin(); it != vertices[u]->edges.end(); it++) { //for the adjacent vertices, add to queue if unvisited
      int v = *it; //the index that iterator is pointing to
      if (!vertices[v]->visited) {
        vertices[v]->visited = true;
        vertices[v]->distance = vertices[u]->distance + 1;

        waiting.push(v); 
      }
    }
  }
}

void Graph::bfs(string src, string tar) {
  int* path = new int[vertices.size()];

  for (int i = 0; i < vertices.size(); i++) {
    vertices[i]->visited = false;
    vertices[i]->distance = -1;
    path[i] = -1;
  }

  queue<int> waiting;
  int s = str2idx(src); 
  int t = str2idx(tar); 

  vertices[s]->visited = true;
  vertices[s]->distance = 0;
  path[s] = -1;

  if (s == t) {
    cout << " target van be reached" << endl;
    return;
  }

  waiting.push(s);


  while (!waiting.empty()) {
    int u = waiting.front();  
    waiting.pop();

    // cout << vertices[u]->name << "[" << vertices[u]->distance << "] ";

    for (auto it = vertices[u]->edges.begin(); it != vertices[u]->edges.end(); it++) {
      int v = *it; 
      if (!vertices[v]->visited) {
        path[v] = u;
        vertices[v]->visited = true;
        vertices[v]->distance = vertices[u]->distance + 1;

        waiting.push(v);
        if (v == t) {
              // print optimal path form node s to node t..
              cout << " target can be reached at distance: " << vertices[v]->distance << endl;
              return;
        }
      }
    }
  }
      cout << " target can't be reached" << endl;
}


void Graph::dijkstra(string src) {
  int s = str2idx(src); 
  if (s == -1) return;

  for (int i = 0; i < vertices.size(); i++) {
    vertices[i]->distance = INT_MAX;
    vertices[i]->visited = false;  
  }

  vertices[s]->distance = 0;

  bool done = false;

  while (! done) { // number of vertice (m)
    done = true;
    // find an un-visited node with the minimum distance.
    int min = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < vertices.size(); i++) { // number of vertices i.e. m
      if (!vertices[i]->visited) {
        if (vertices[i]->distance < minDist) {//if distance of vertice is smaller than minDist then set min to i
          min = i;
          minDist = vertices[i]->distance;
        }
      }
    }
    // then visit it.
    if ((min != -1) && (minDist != INT_MAX)){
      done = false;
      vertices[min]->visited = true;
      cout << vertices[min]->name << "(" << vertices[min]->distance << ") ";

      for (int i = 0; i < vertices[min]->edges.size(); i++) {
        int v = vertices[min]->edges[i];
        int w = vertices[min]->weights[i];

        if (!vertices[v]->visited) {//if adjacent vertice is not visited, if dist is greater then set the distance for that vertice
           if (vertices[v]->distance >  vertices[min]->distance + w) {
             vertices[v]->distance = vertices[min]->distance + w;
           }
        }
      }
    }
  }
}
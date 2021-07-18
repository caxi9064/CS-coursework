#include<iostream>
#include "Graph1.hpp"
#include<vector>

int main() {
  Graph G;
  G.add_vertex("1");
  G.add_vertex("2");
  G.add_vertex("3");
  G.add_vertex("4");
  G.add_vertex("5");
  G.add_vertex("6");
 

  G.add_edge("1","6", 14);
  G.add_edge("1","3", 9);
  G.add_edge("1","2", 7);

  G.add_edge("2","3", 10);
  G.add_edge("2","4", 15);
  G.add_edge("3","4", 11);
  G.add_edge("3","6", 2);
  
  G.add_edge("4","5", 6);
  G.add_edge("5","6", 9);


  G.pretty_print();

  // G.bfs("A");

//  G.bfs("A","G");

  G.dijkstra("1");
  
  return 0;
}

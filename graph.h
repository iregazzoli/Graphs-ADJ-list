#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"

typedef char Data;

const int MAX_VERTICES = 10;
// const int MAX_EDGES_PER_VERTEX = 90; //n*(n-1)

class Graph{
private:
  int amount_of_vertices = 0;
  Vertex** vertices;

  // Pile stacku;
  // void depht_search(int i);
  int check_vertex_index(Data vertex_to_check);
  // void reset_visited_vertex();
  // int get_adjacent_unvisited_vertex(int row_num);
public:
  Graph();
  ~Graph();
  void add_vertex(Data value);
  void add_edge(Data start_vertex, Data end_vertex);
  void add_edge(Data start_vertex, Data end_vertex, int weight);
  void print_adj_list();
  void print_vertices();
  // void depht_search();
};

#endif

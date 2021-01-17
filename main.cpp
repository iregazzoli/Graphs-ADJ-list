#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;


int main(){
	Graph graph;
	// graph.print_adj_matrix();
	graph.add_vertex('a');
	graph.add_vertex('b');
	graph.add_vertex('c');
	graph.add_vertex('d');
	graph.add_vertex('e');
	graph.add_vertex('f');
	graph.print_vertices();
	graph.add_edge('a', 'b', 100);
	graph.add_edge('a', 'c', 50);
	graph.add_edge('b', 'a', 70);
	graph.add_edge('c', 'd', 1000);
	graph.add_edge('e', 'b');
	graph.add_edge('d', 'b');
	graph.add_edge('d', 'b');
	graph.add_edge('f', 'c');
	graph.add_edge('h', 'g');
	std::cout << "------------------------" << '\n';
	graph.print_adj_list();
	// graph.depht_search();
	return 0;
}

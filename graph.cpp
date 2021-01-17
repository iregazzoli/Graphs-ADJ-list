#include <iostream>
#include <fstream>
#include <stack>
#include "graph.h"
using namespace std;

Graph::Graph(){
  vertices = new Vertex* [MAX_VERTICES];
}


void Graph::add_vertex(Data value){
  if(amount_of_vertices < MAX_VERTICES){
    vertices[amount_of_vertices] = new Vertex(value);
    amount_of_vertices++;
  }
  else
    std::cout << "The Graph is full, can't add more vertices" << '\n';
}

void Graph::add_edge(Data start_vertex, Data end_vertex){
  //until line 28 is just a check for valid input.
  int start_vertex_index = check_vertex_index(start_vertex);
  int end_vertex_index = check_vertex_index(end_vertex);
  if(start_vertex_index == -1 || end_vertex_index == -1){
    std::cout << "Error: inserted value doesn't belong to the graph." << '\n';
    return;
  }
  Vertex* adjacent_vertex = new Vertex(end_vertex);
  if(vertices[start_vertex_index]->get_adjacent() == 0)
    vertices[start_vertex_index]->set_adjacent(adjacent_vertex);
  else{
      adjacent_vertex->set_adjacent(vertices[start_vertex_index]->get_adjacent());
      vertices[start_vertex_index]->set_adjacent(adjacent_vertex);
    }
  }

void Graph::add_edge(Data start_vertex, Data end_vertex, int weight){
  int start_vertex_index = check_vertex_index(start_vertex);
  int end_vertex_index = check_vertex_index(end_vertex);
  if(start_vertex_index == -1 || end_vertex_index == -1){
    std::cout << "Error: inserted value doesn't belong to the graph." << '\n';
    return;
  }
  Vertex* adjacent_vertex = new Vertex(end_vertex);
  adjacent_vertex->set_weight(weight);
  if(vertices[start_vertex_index]->get_adjacent() == 0)
    vertices[start_vertex_index]->set_adjacent(adjacent_vertex);
  else{
      adjacent_vertex->set_adjacent(vertices[start_vertex_index]->get_adjacent());
      vertices[start_vertex_index]->set_adjacent(adjacent_vertex);
    }
  }

int Graph::check_vertex_index(Data vertex_to_check){
  for(int i = 0; i < MAX_VERTICES; i++){
    //to prevent the program to access the value of an empty pointer.
    if(vertices[i] != 0){
      if((this->vertices[i])->get_value() == vertex_to_check)
        return i;
    }
  }
  std::cout << "Vertex '" << vertex_to_check << "' not found" << '\n';
  return -1;
}

void Graph::print_vertices(){
  std::cout << "Vertices are:" << '\n';
  for(int i = 0; i < MAX_VERTICES; i++){
    if(vertices[i] != 0)
      std::cout << "[" << (this->vertices[i])->get_value() << "]";
    else
      std::cout << "[/]";
  }
  std::cout << '\n';
  std::cout << '\n';
}

//agregar para que checke el weight de cada vertice y printee -weight->, el primer nodos no debe tener weight ya que solo los vertices pertenecientes al adj list son los que tienen weight, ojo con el caso del while en su primera iteracion, maybe algo como si wight != 0 imprimilo si no no.
void Graph::print_adj_list(){
  std::cout << '\n';
  std::cout << "Adjacency List:" << '\n';
  for(int i = 0; i < MAX_VERTICES; i++){

    if(vertices[i] != 0){ //prevents "Segmentation fault (core dumped)"
      Vertex* current_vertex = this->vertices[i];
      while(current_vertex != 0){ //i continue to replace "current_vertex" in each iteration. (maybe make it a private method "travel through all edges" (rep line 113))
        if(current_vertex->get_adjacent() != 0)
          std::cout << "[" << current_vertex->get_value() << "]-" << (current_vertex->get_adjacent())->get_weight() << "->";
        else
          std::cout << "[" << current_vertex->get_value() << "]";
        current_vertex = current_vertex->get_adjacent();
      }
      std::cout << '\n';
    }
  }
}

//
void Graph::depht_search(){
  std::cout << "Visited vertices:" << '\n';
  for(int i = 0; i < amount_of_vertices; i++){
    if(vertices[i]->get_visited() == false)
      depht_search(i);
  }
  reset_visited_vertex();
  std::cout << '\n';
}

void Graph::depht_search(Vertex* current_vertex){

  //need to change boolean on the vertex array "vertices".
  current_vertex->was_visited();

  std::cout << "'" << current_vertex->get_value() << "'";

  Vertex* next_vertex = current_vertex->get_adjacent();

  while(next_vertex != 0){
    //call the function again
    depht_search(next_vertex); //PROBLEM THE VERTEX YOU ARE ACCESSING IS NOT THE REAL VERTEX
    //replaces current_vertex with the next vertex.
    next_vertex = next_vertex->get_adjacent();
  }
}

void Graph::depht_search(Vertex* current_vertex){

  //need to change boolean on the vertex array "vertices".
  current_vertex->was_visited();

  std::cout << "'" << current_vertex->get_value() << "'";

  Vertex* next_vertex = current_vertex->get_adjacent();

  while(next_vertex != 0){
    //call the function again
    depht_search(next_vertex); //PROBLEM THE VERTEX YOU ARE ACCESSING IS NOT THE REAL VERTEX
    //replaces current_vertex with the next vertex.
    next_vertex = next_vertex->get_adjacent();
  }
}

// // void Graph::wide_search(){
// //   std::cout << "Visited vertices:" << '\n';
// //   for(int i = 0; i < amount_of_vertices; i++){
// //     if(vertices[i]->get_visited() == false)
// //       wide_search(i);
// //   }
// //   reset_visited_vertex();
// //   std::cout << '\n';
// // }
// //
// // void Graph::wide_search(int current_vertex){
// //   vertices[current_vertex]->was_visited();
// //   std::cout << "'" << vertices[current_vertex]->get_value() << "'";
// //   stacku.push(current_vertex);
// //     while(! stacku.empty()){
// //       stacku.pop();
// //       //necesito que la funcion devuelva TODOS los vecinos directos no uno -> que tal si le paso la refencia del stack, recorre la matriz y agrega los vecinos directamente en el stack
// //       //y procede remueve EL PRIMER ELEMENTO del stack, alternativamente podria meter un for en donde si el vertice ya fue visitado lo ignore (ojo linea 122 en ese caso), *yo del futuro: pero esto va medio en contra de la filosofia de stack....
// //     }
// // }
//
// int Graph::get_adjacent_unvisited_vertex(int row_num){
//   for(int i = 0; i < amount_of_vertices; i++){
//     if(adjacency_matrix[row_num][i] == 1 && vertices[i]->get_visited() == false)
//       return i;
//   }
//   return -1;
// }
//
void Graph::reset_visited_vertex(){
  for(int i = 0; i < amount_of_vertices; i++){
    vertices[i]->was_not_visited();
  }
}

Graph::~Graph(){
  for(int i = 0; i < MAX_VERTICES; i++){
    //erase the adjacency_list on every vertex.
    if(vertices[i] != 0){ //prevents "Segmentation fault (core dumped)"
      while(vertices[i]->get_adjacent() != 0){
        Vertex* vertex_to_delete = vertices[i]->get_adjacent();
        vertices[i]->set_adjacent(vertex_to_delete->get_adjacent());
        delete vertex_to_delete;
      }
    }
    delete vertices[i];
  }
  delete [] vertices;
}

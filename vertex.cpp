#include "vertex.h"

Vertex::Vertex(Data value){
  this->value = value;
  this->visited = false;
  this->weight = 0;
  this->adjacent_vertex = 0;
}

Vertex::Vertex(Data value, int weight){
  this->value = value;
  this->visited = false;
  this->weight = weight;
  this->adjacent_vertex = 0;
}

bool Vertex::get_visited(){
  return this->visited;
}

void Vertex::was_visited(){
  this->visited = true;
}

void Vertex::was_not_visited(){
  this->visited = false;
}

Data Vertex::get_value(){
  return value;
}
void Vertex::set_adjacent(Vertex* ady){
  this->adjacent_vertex = ady;
}

Vertex* Vertex::get_adjacent(){
  return this->adjacent_vertex;
}

void Vertex::set_weight(int weight){
  this->weight = weight;
}

int Vertex::get_weight(){
  return this->weight;
}

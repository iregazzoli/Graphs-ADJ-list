#ifndef VERTEX_H
#define VERTEX_H
typedef char Data;

class Vertex{
private:
  Data value;
  bool visited;
  Vertex* adjacent_vertex;
  int weight;

public:
  Vertex(Data value);
  Vertex(Data value, int weight);
  bool get_visited();
  void was_visited();
  void was_not_visited();
  Data get_value();
  void set_adjacent(Vertex* ady);
  Vertex* get_adjacent();
  void set_weight(int weight);
  int get_weight();
};

#endif

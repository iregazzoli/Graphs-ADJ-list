main: main.o graph.o vertex.o 
		g++ main.o graph.o vertex.o -o main

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp
	g++ -c graph.cpp

vertex.o: vertex.cpp
	g++ -c vertex.cpp

# pile.o: pile.cpp
# 	g++ -c pile.cpp

clean:
	rm *.o main

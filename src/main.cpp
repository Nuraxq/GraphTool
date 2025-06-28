#include <iostream>
#include "IGraph.h"
#include "Graph_IO.h"

// TODO:
// EINLESE UND AUSGABE OPERATOR SPEICHERN DASS GRAPH OBJEKTE AUS DATEIEN EINGELSEN WERDEN KÖNNEN
using namespace std;
int main()
{
    IGraph Graph(false);
    Graph.create_vertex(1);
    Graph.create_vertex(2);
    Graph.create_edge(1,2,10);
    Graph.create_vertex(3);
    Graph.create_edge(1,3,5);
    std::cout << Graph.find_vertex(1);
    Graph.print();
    Graph.remove_vertex(1);
    return 0;
}
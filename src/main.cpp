#include <iostream>
#include "IGraph.h"
using namespace std;
int main()
{
    IGraph Graph(false);
    Graph.create_vertex(1);
    Graph.create_vertex(2);
    Graph.create_edge(1,2,10);
    Graph.create_vertex(3);
    Graph.create_edge(1,3,5);
    Graph.print();
    Graph.remove_vertex(1);
    return 0;
}
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include "IGraph.h"
using namespace std;
int main()
{
    IGraph Graph;
    Graph.create_vertex(1);
    Graph.create_vertex(2);
    Graph.create_edge(1,2);
    Graph.remove_edge(1,2);
    return 0;
}
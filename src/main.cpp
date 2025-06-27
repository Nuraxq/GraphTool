#include <iostream>
#include "IGraph.h"
using namespace std;
int main()
{
    IGraph Graph;
    Graph.create_vertex(1);
    Graph.create_vertex(2);
    Graph.create_edge(1,2);
    Graph.print();
    Graph.remove_vertex(1);
    return 0;
}
#include <iostream>
#include <fstream>
#include "IGraph.h"
#include "Graph_IO.h"

// TODO:
// EINLESE UND AUSGABE OPERATOR SPEICHERN DASS GRAPH OBJEKTE AUS DATEIEN EINGELSEN WERDEN KÖNNEN
using namespace std;
int main()
{
    ifstream is("GraphFile");

    IGraph Graph;
    try
    {
        is >> Graph;
    }
    catch (read_error&e)
    {
        std::cout << e.what() << endl;
    }

    Graph.print();
    ofstream os("GraphFile", ios_base::trunc);
    os << Graph;
    return 0;
}

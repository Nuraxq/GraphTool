#include "IGraph.h"

Vertex* IGraph::find_vertex(int id) const
{
    for (const std::unique_ptr<Vertex>&v : vertices_)
    {
        if (v->id() == id){ return v.get();}
    }
    return nullptr;
}

void IGraph::create_vertex(int id)
{
    vertices_.push_back(std::make_unique<Vertex>(id));
}

void IGraph::create_edge(int id1, int id2)
{
    auto v1 = find_vertex(id1);
    auto v2 = find_vertex(id2);
    if (v1 && v2)
    {
        auto edge = std::make_unique<Edge>(v1,v2);
    }
}
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
      edges_.push_back(std::make_unique<Edge>(v1,v2));
        v1->add_isSourceV(edges_[edges_.size()-1].get());
        v2->add_isTargetV(edges_[edges_.size()-1].get());
    }
}

void IGraph::remove_edge(int id1, int id2)
{
    for (auto it = edges_.begin(); it != edges_.end(); it++)
    {
        if ((*it)->from()->id() == id1 && (*it)->to()->id() == id2)
        {
            auto v1 = (*it)->from();
            auto v2 = (*it)->to();
            v1->delete_isSourceV((*it).get());
            v2->delete_isTargetV((*it).get());
            edges_.erase(it);
            return;
        }
    }
    std::cout << "Kante nicht gefunden\n";
}
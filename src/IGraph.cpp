#include "IGraph.h"
// Definitionen der Funktion von der Graph Klasse

Vertex* IGraph::find_vertex(const int id) const
{
    for (const std::unique_ptr<Vertex>&v : vertices_)
    {
        if (v->id() == id){ return v.get();}
    }
    std::cout << "Knoten nicht vorhanden\n";
    return nullptr;
}

void IGraph::remove_edge(const Edge* e)
{
    const auto v1 = e->from();
    const auto v2 = e->to();
    v1->delete_isSourceV(e);
    v2->delete_isTargetV(e);

    for (auto it = edges_.begin(); it != edges_.end(); ++it )
    {
        if (it->get()  == e)
        {
            edges_.erase(it);
            return;
        }
    }

}

// Löscht Knoten und alle Inzidenten Kanten
void IGraph::remove_vertex(const int id)
{
    const Vertex*  v = find_vertex(id);
    if (!v)
    {
        std::cout << "Vertex doesnt exist\n";
        return;
    }
    for (const Edge* e : v->isSourceV())
    {
        remove_edge(e);
    }
    for (const Edge* e : v->isTargetV())
    {
        remove_edge(e);
    }
    for (auto it = vertices_.begin(); it != vertices_.end(); ++it)
    {
        if ((*it)->id() == id)
        {
            vertices_.erase(it);
        }
    }
}

void IGraph::create_vertex(int id)
{
    vertices_.push_back(std::make_unique<Vertex>(id));
}

// Sucht von alleine die kleinstmoegliche ID >= 0
void IGraph::create_vertex()
{
    for (int i = 0; i < vertices_.size(); i ++)
    {
        bool isUsed = false;
        for (const std::unique_ptr<Vertex>& v : vertices_)
        {
            if (v->id() == i){ isUsed = true; }
        }
        if (!isUsed) {create_vertex(i);}
    }
}

// erstellt Kante mithilfe von Knoten Ids
void IGraph::create_edge(const int id1,const int id2)
{
    const auto v1 = find_vertex(id1);
    const auto v2 = find_vertex(id2);
    if (!v1){std::cout << "Vertex with ID "  << id1 << " doesnt exist\n";}
    if (v1 && v2)
    {
      edges_.push_back(std::make_unique<Edge>(v1,v2));
        v1->add_isSourceV(edges_[edges_.size()-1].get());
        v2->add_isTargetV(edges_[edges_.size()-1].get());
    }
}
// Löscht kante anhand von Id's der Inzidenten Knoten
void IGraph::remove_edge(const int id1,const int id2)
{
    for (auto it = edges_.begin(); it != edges_.end(); ++it)
    {    // 1. Deref für pointer objekt, zweite für Vertex zeiger und dritte für ID von Vertex
        // Guckt ob die Kante die gesuchte ist
        if ((*it)->from()->id() == id1 && (*it)->to()->id() == id2)
        {
            const auto v1 = (*it)->from();
            const auto v2 = (*it)->to();
            v1->delete_isSourceV(it->get());
            v2->delete_isTargetV(it->get());
            edges_.erase(it);
            return;
        }
    }
    std::cout << "Edge doesnt not exit\n";
}
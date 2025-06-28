#include "IGraph.h"
// Definitionen der Funktion von der Graph Klasse


// Gibt Vertex* anhand Id zurück, sonst log fehlermeldung
Vertex* IGraph::find_vertex(const int id) const
{
    for (const std::unique_ptr<Vertex>&v : vertices_)
    {
        if (v->id() == id){ return v.get();}
    }
    std::cout << "Knoten nicht vorhanden\n";
    return nullptr;
}
// Löscht Kante, sowie den Kanteneintrag in Inzidenten Knoten
void IGraph::remove_edge(const Edge* e)
{
    const auto v1 = e->from();
    const auto v2 = e->to();
    if (v1 && v2)
    {
        v1->delete_isSourceV(e);
        v2->delete_isTargetV(e);
    }
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
// Gibt true falls vertex exisitert
bool IGraph::has_vertex(const int id) const
{
    for (auto& v : vertices_)
    {
        if (v->id() == id)
        {
            return true;
        }
    }
    return false;
}
// Gibt true falls Kante exisitert
bool IGraph::has_edge(const int from,const int to) const
{
    for (auto& e : edges_)
    {
        if ( e->from()->id() == from && e->to()->id() == to)
        {
            return true;
        }
    }
    return false;
}


// Gibt einmal den Graph und alle Kanten aus
void IGraph::print() const
{
    std::cout << "is Weighted : " << isWeighted << "\n";
    std::cout << "is Directed : " << isDirected << "\n";
    std::cout << "Vertices: \n";
    for (const auto& v : vertices_)
    {
        std::cout << "ID : " << v->id() << "\n";
    }
    std::cout << "Edges: \n";
    for (const auto& e : edges_)
    {
        std::cout << e->from()->id() << " -> " << e->to()->id();
        if (isWeighted)
        {
            std::cout << " | Weight: " << e->weight();
        }
        std::cout <<"\n";
    }
}
// Erstellt Knoten
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
void IGraph::create_edge(const int from,const int to, const int weight)
{
    {
        const auto v1 = find_vertex(from);
        const auto v2 = find_vertex(to);
        if (!v1){std::cout << "Vertex with ID "  << from << " doesnt exist\n";}
        if (!v2){std::cout << "Vertex with ID " << to << " doesnt exist\n";}
        if (v1 && v2 && !has_edge(from,to))
        {
            edges_.push_back(std::make_unique<Edge>(v1,v2,weight));
            v1->add_isSourceV(edges_[edges_.size()-1].get());
            v2->add_isTargetV(edges_[edges_.size()-1].get());
        }
        if (!isDirected && v1 && v2 && !has_edge(to,from))
        {
            edges_.push_back(std::make_unique<Edge>(v2,v1,weight));
            v1->add_isTargetV(edges_[edges_.size()-1].get());
            v2->add_isSourceV(edges_[edges_.size()-1].get());
        }
    }
}
// Löscht kante anhand von Id's der Inzidenten Knoten
void IGraph::remove_edge(const int from,const int to)
{
    for (auto it = edges_.begin(); it != edges_.end(); ++it)
    {    // 1. Deref für pointer objekt, zweite für Vertex zeiger und dritte für ID von Vertex
        // Guckt ob die Kante die gesuchte ist
        if ((*it)->from()->id() == from && (*it)->to()->id() == to)
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
// Gibt alle Nachbarn vom Knoten mit id zurück
std::vector<Vertex*> IGraph::get_neighbors(const int id) const
{
    const auto v = find_vertex(id);
    std::vector<Vertex*> vec;
    if (!v){return vec;}

    vec = v->get_neighbors();
    return vec;
}
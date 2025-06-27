#include "Vertex.h"

Vertex::~Vertex()
{
    std::cout << "Vertex number " << id() <<  " has been deleted\n";
}


//Gibt alle Nachbarn eines Knoten zurück (bei Gerichtet nur die Auf die er zeigt)
std::vector<Vertex*> Vertex::get_neighbors()const
{
    std::vector<Vertex*> v;
    for (auto& e : isSourceV_)
    {
        v.push_back(e->to());
    }
    return v;
}

void Vertex::delete_isSourceV(const Edge* e)
{
    for (auto it = isSourceV_.begin(); it != isSourceV_.end(); ++it )
    {
        if ((*it) == e)
        {
            isSourceV_.erase(it);
            return;
        }
    }
}

void Vertex::delete_isTargetV(const Edge* e)
{
    for (auto it = isTargetV_.begin(); it != isTargetV_.end(); ++it )
    {
        if ((*it) == e)
        {
            isTargetV_.erase(it);
            return;
        }
    }
}
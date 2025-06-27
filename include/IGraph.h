#pragma once
#ifndef IGRAPH_H
#define IGRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include <memory>
#include <vector>

class IGraph
{
    std::vector<std::unique_ptr<Vertex>> vertices_;
    std::vector<std::unique_ptr<Edge>> edges_;
public:
    IGraph() = default;
    void create_vertex(int id);
    void create_vertex();
    void create_edge(int id1, int id2);
    Vertex* find_vertex(int id) const;
    void remove_edge(int id1, int id2);
    void remove_edge(const Edge* e);
    void remove_vertex(int id);
};

#endif //IGRAPH_H

#pragma once
#ifndef IGRAPH_H
#define IGRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include <memory>

class IGraph
{
    std::vector<std::shared_ptr<Vertex>> vertices_;
    std::vector<std::weak_ptr<Edge>> edges_;


public:
    IGraph() = default;

    void create_vertex(int id, int weight);
    void create_vertex(int id);
    void create_edge(int id1, int id2);
    void create_edge(int id1, int id2, int weight);
    void create_edge_dir(int id1, int id2);
    void create_edge_dir(int id1, int id2, int weight);
    void print_vertices() const;
    void print_edges() const;
    std::shared_ptr<Vertex> find_vertex(int id);
    std::weak_ptr<Edge> find_edge(int id1, int id2);
    std::vector<std::shared_ptr<Vertex>>& vertices();
    std::vector<std::weak_ptr<Edge>>& edges();
};

#endif //IGRAPH_H

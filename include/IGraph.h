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
    bool isWeighted = false;
    bool isDirected = true;
public:
    std::vector<Vertex*> get_neighbors( int id) const;
    bool has_vertex(int id) const;
    bool has_edge(int from,int to) const;
    IGraph() = default;
    explicit IGraph(const bool isDir) : isDirected(isDir){}
    IGraph(const bool isWeigh, const bool isDir) : isWeighted(isWeigh),isDirected(isDir){}
    void create_vertex(int id);
    void create_vertex();
    void create_edge(int from, int to, int weight = 1);
    Vertex* find_vertex(int id) const;
    void remove_edge(int from, int to);
    void remove_edge(const Edge* e);
    void remove_vertex(int id);
    void print() const;
};

#endif //IGRAPH_H

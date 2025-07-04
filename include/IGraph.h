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
    bool is_Directed() const {return isDirected;}
    bool is_Weighted() const {return isWeighted;}
    std::vector<Vertex*> vertices() const;
    std::vector<Edge*> edges() const;
    void set_Directed(bool d){isDirected = d;}
    void set_Weighted(bool w){isWeighted = w;}
};

#endif //IGRAPH_H

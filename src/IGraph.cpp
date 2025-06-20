#pragma once
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "IGraph.h"
#include <iostream>
std::shared_ptr<Vertex> IGraph::find_vertex(int id)
{
    for (auto v : vertices_)
    {
        if (v->id() == id) {return v;}
    }
    std::cout << "Vertex not found\n";
    return nullptr;
}

std::vector<std::shared_ptr<Vertex>>& IGraph::vertices()
{
    return vertices_;
}

std::vector<std::weak_ptr<Edge>>& IGraph::edges()
{
    return edges_;
}


void IGraph::create_vertex(int id, int weight)
{
    vertices_.push_back(std::make_shared<Vertex>(id,weight));
}

void IGraph::create_vertex(int id)
{
    vertices_.push_back(std::make_shared<Vertex>(id));
}

void IGraph::create_edge(int id1,int id2)
{
   auto v1 = find_vertex(id1);
    auto v2 = find_vertex(id2);
    if(v1 && v2)
    {
        auto direction1 = std::make_shared<Edge>(v1,v2);
        auto direction2 = std::make_shared<Edge>(v2,v1);
        v1->add_edge_undir(direction1,direction2);
        v2->add_edge_undir(direction1,direction2);
        edges_.push_back(direction1);
        edges_.push_back(direction2);
    }
    else
    {
        std::cout << "One of the Vertices doesnt exist!\n";
    }
}
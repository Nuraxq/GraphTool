#pragma once
#include "Vertex.h"
#include <iostream>
int Vertex::id() const
{
    return id_;
}

int Vertex::weight() const
{
    return weight_;
}

void Vertex::add_edge_to(std::shared_ptr<Edge>& edge)
{
    to_.push_back(edge);
}

void Vertex::add_edge_from(std::shared_ptr<Edge>& from)
{
    from_.push_back(from);
}

void Vertex::add_edge_undir(std::shared_ptr<Edge>&from , std::shared_ptr<Edge>&to)
{
    from_.push_back(from);
    to_.push_back(to);
}

Vertex::~Vertex()
{
    std::cout << "Vertex with ID: " << id_ << " has been deleted!\n";
}

int Vertex::in_degree() const
{
    return from_.size();
}

int Vertex::out_degree() const
{
    return to_.size();
}
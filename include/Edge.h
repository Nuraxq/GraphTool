#pragma once
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
#include <memory>

class Edge
{
    std::weak_ptr<Vertex> to_;
    std::weak_ptr<Vertex> from_;
    int weight_ = 0;

public:
    Edge(const std::shared_ptr<Vertex>& v1,const std::shared_ptr<Vertex>& v2)
        : from_(v1), to_(v2){}
    Edge(const std::shared_ptr<Vertex>& v1,const std::shared_ptr<Vertex>& v2,int weight)
        : from_(v1), to_(v2), weight_(weight){}
    ~Edge();
    void print_info() const;
    std::shared_ptr<Vertex> from() const;
    std::shared_ptr<Vertex> to() const;
};





#endif //EDGE_H

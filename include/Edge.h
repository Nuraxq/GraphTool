#pragma once
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
#include <memory>
#include <iostream>
class Vertex;

class Edge
{
    Vertex* from_;
    Vertex* to_;
    int weight_;
public:
    ~Edge();
    Edge() = default;
    Edge(Vertex* v1, Vertex* v2) : from_(v1), to_(v2){}
    Edge(Vertex* v1, Vertex* v2,int weight) : from_(v1), to_(v2), weight_(weight){}
    int weight() const {return weight_;}
    Vertex* from() const {return from_;}
    Vertex* to() const {return to_;}
};





#endif //EDGE_H

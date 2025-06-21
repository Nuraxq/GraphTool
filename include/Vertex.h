#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include <memory>
#include <vector>
#include "Edge.h"
class Edge;

class Vertex
{
    int id_ = 0;
    std::vector<Edge*> from_;
    std::vector<Edge*> to_;

public:
    Vertex(int id)
        : id_(id){}
    std::vector<Edge*> from() const {return from_;}
    std::vector<Edge*> to() const {return to_;}
    int id() const {return id_;}
};




#endif //VERTEX_H

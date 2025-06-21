#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include <memory>
#include <vector>
#include "Edge.h"
#include <iostream>
class Edge;

class Vertex
{
    int id_ = 0;
    std::vector<Edge*> isSourceV_;
    std::vector<Edge*> isTargetV_;

public:
    ~Vertex();
    Vertex(int id)
        : id_(id){}
    std::vector<Edge*> isSourceV() const {return isSourceV_;}
    std::vector<Edge*> to() const {return isTargetV_;}
    int id() const {return id_;}
    void delete_isTargetV(Edge* e);
    void delete_isSourceV(Edge* e);
    void add_isTargetV(Edge* e){ isTargetV_.push_back(e);}
    void add_isSourceV(Edge* e){ isSourceV_.push_back(e);}
};




#endif //VERTEX_H

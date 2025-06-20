#pragma once
#ifndef VERTEX_H
#define VERTEX_H
#include <memory>
#include <vector>

class Edge;

class Vertex
{
    int id_ = 0;
    std::vector<std::shared_ptr<Edge>> from_;
    std::vector<std::shared_ptr<Edge>> to_;
    int weight_ = 0;
public:
    int in_degree() const;
    int out_degree() const;
    ~Vertex();
    Vertex(int id)
        :  id_(id){}
    Vertex(int id, int weight)
        : id_(id), weight_(weight){}
    int id () const;
    int weight() const;
    void add_edge_to(std::shared_ptr<Edge>&);
    void add_edge_from(std::shared_ptr<Edge>&);
    void add_edge_undir(std::shared_ptr<Edge>& e, std::shared_ptr<Edge>& e2);


};




#endif //VERTEX_H

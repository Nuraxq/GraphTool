#pragma once
#include <iostream>
#include "Edge.h"

void Edge::print_info() const
{
    auto v1 = from_.lock();
    auto v2 = to_.lock();
    if(v1 && v2)
    {
        std::cout << "Edge goes from: " << v1->id() << " to: " << v2->id() << "\n";
    }
}

Edge::~Edge()
{
    auto v1 = from_.lock();
    auto v2 = to_.lock();
    if(v1 && v2)
    {
        std::cout <<  "Edge from: " << v1->id() << " to: " << v2->id() << " has been deleted\n";
    }
}

std::shared_ptr<Vertex> Edge::from() const
{
    return from_.lock();
}

std::shared_ptr<Vertex> Edge::to() const
{
    return to_.lock();
}
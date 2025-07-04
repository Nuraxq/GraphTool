#pragma once
#ifndef GRAPH_IO_H
#define GRAPH_IO_H
#include "IGraph.h"
#include <iostream>
#include <fstream>

class read_error : public std::runtime_error {
public:
    read_error(std::string nachricht)
        : runtime_error(nachricht) {}
};

std::ofstream& operator<<(std::ofstream& os ,const IGraph& Graph);
std::ifstream& operator>>(std::ifstream& is, IGraph& Graph);

#endif //GRAPH_IO_H

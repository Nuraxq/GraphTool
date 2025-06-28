#pragma once
#ifndef GRAPH_IO_H
#define GRAPH_IO_H
#include "IGraph.h"
#include <iostream>

std::ofstream& operator<<(std::ofstream& os ,const IGraph& Graph);
std::ifstream& operator>>(std::ifstream& is, IGraph& Graph);

#endif //GRAPH_IO_H

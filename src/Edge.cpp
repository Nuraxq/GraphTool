#include "Edge.h"

Edge::~Edge()
{
    std::cout << "Edge from " << from_->id() <<  " to " << to_->id() << " has been deleted\n";
}
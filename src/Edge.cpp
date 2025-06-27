#include "Edge.h"
// Nachricht zur Ausgabe (Nur für Kontrolle am Anfang da)
Edge::~Edge()
{
    std::cout << "Edge from " << from_->id() <<  " to " << to_->id() << " has been deleted\n";
}
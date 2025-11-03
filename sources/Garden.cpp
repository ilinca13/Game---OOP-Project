//
// Created by horeanga on 02/11/2025.

#include "Garden.h"

void Garden::addContainer(Container& c) {
    containers.push_back(&c);  // stocăm adresa
}

void Garden::simulateGrowth() {
    for (auto* c : containers) {
        if (c->hasPlantInContainer()) {
            c->getPlant().grow();
        }
    }
}
std::ostream& operator<<(std::ostream& os, const Garden& g) {
    os << "Garden:\n";
    for (auto* c : g.containers) {
        os << " " << *c << "\n"; // dereferințiere pointer
    }
    return os;
}


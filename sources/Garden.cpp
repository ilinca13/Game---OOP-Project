//
// Created by horeanga on 02/11/2025.


#include "Garden.h"

#include <iostream>

void Garden::addContainer(std::shared_ptr<Container> c) {
    containers.push_back(std::move(c));
}

void Garden::simulateGrowth() const {
    for (const auto& c : containers) c->simulatePlantGrowth();
}

std::ostream& operator<<(std::ostream& os, const Garden& g) {
    os << "Garden:\n";
    int idx = 1;
    for (const auto& c : g.containers) {
        os << " Container " << idx++ << " -> " << *c << "\n";
    }
    return os;
}


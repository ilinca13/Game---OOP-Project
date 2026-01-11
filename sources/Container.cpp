//
// Created by horeanga on 02/11/2025.



#include "Container.h"
#include <iostream>
#include <utility>

int Container::totalContainers = 0;

Container::Container() : clean(false), plant(nullptr) { ++totalContainers; }

Container::Container(const Container& other) : clean(other.clean) {
    if (other.plant) plant = other.plant->clone();
    ++totalContainers;
}

Container& Container::operator=(Container other) {
    // copy-and-swap
    std::swap(clean, other.clean);
    std::swap(plant, other.plant);
    return *this;
}

void Container::disinfect() {
    if (!clean) {
        clean = true;
        std::cout << "Container disinfected with success.\n";
    } else {
        std::cout << "Container already clean.\n";
    }
}

bool Container::plantSeed(std::shared_ptr<PlantBase> p) {
    if (!clean) throw ContainerException("Cannot plant: container is dirty");
    if (plant) throw ContainerException("Cannot plant: container already has a plant");
    if (!p) throw ContainerException("Cannot plant: null pointer");
    plant = std::move(p);
    std::cout << "Planted successfully: " << *plant << "\n";
    return true;
}

void Container::simulatePlantGrowth() const
{
    if (plant) plant->grow();
}

void Container::setPlant(std::shared_ptr<PlantBase> newPlant)
{
    if (!newPlant) throw ContainerException("Cannot plant: null pointer");
    plant = std::move(newPlant);
}


std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << "Container [" << (c.clean ? "clean" : "dirty") << "]";
    if (c.plant) os << " contains " << *c.plant;
    else os << " empty";
    return os;
}



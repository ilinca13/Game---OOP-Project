//
// Created by horeanga on 02/11/2025.

/*#include "Container.h"

Container::Container() : clean(false), hasPlant(false) {}
void Container::disinfect(const Potion& p) {
    if (!clean) {
        std::cout << "Container disinfected with potion " << p.getName() << "\n";
        clean = true;
    } else {
        std::cout << "Containerul este deja curat.\n";
    }
}
bool Container::plantSeed(const Plant& p) {
    if (!clean) {
        std::cout << "The container isn't clean. We can't plant something inside.\n";
        return false;
    }
    if (hasPlant) {
        std::cout << "A plant was already placed inside of the container.\n";
        return false;
    }
    plant = p;
    hasPlant = true;
    std::cout << "Plant " << plant << " successfully added to container.\n";
    return true;
}
bool Container::hasPlantInContainer() const {
    return hasPlant;
}
Plant& Container::getPlant() {
    return plant;
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << "Container [" << (c.clean ? "clean" : "infected") << "]";
    if (!c.clean && c.hasPlant) {
        os << " LOGIC ERROR: infected container contains a plant!";
        return os;
    }
    if (c.hasPlant) {
        os << " with plant: " << c.plant;
    } else {
        os << " without plant";
    }
    return os;
}*/

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

void Container::simulatePlantGrowth() {
    if (plant) plant->grow();
}



std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << "Container [" << (c.clean ? "clean" : "dirty") << "]";
    if (c.plant) os << " contains " << *c.plant;
    else os << " empty";
    return os;
}



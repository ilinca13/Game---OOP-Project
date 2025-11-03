//
// Created by horeanga on 02/11/2025.

#include "Container.h"

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
}



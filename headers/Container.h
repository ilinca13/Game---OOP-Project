//
// Created by horeanga on 02/11/2025.
//

#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H

#include <iostream>

#include "Plant.h"
#include "Potion.h"

class Container {
private:
    bool clean;     // dacă containerul e curat
    Plant plant;    // planta din container
    bool hasPlant;  // există plantă?
public:
    Container();
    void disinfect(const Potion& p);     // curăță containerul
    bool plantSeed(const Plant& p);      // plantează sămânță dacă este curat
    bool hasPlantInContainer() const;    // verifică dacă există plantă
    Plant& getPlant();                   // acces la plantă
    friend std::ostream& operator<<(std::ostream& os, const Container& c);
};

#endif //OOP_CONTAINER_H
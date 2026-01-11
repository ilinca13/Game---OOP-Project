//
// Created by horeanga on 02/11/2025.
//



#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H



#include <memory>
#include <iostream>
#include "PlantBase.h"
#include "Exceptions.h"

class Container {
private:
    bool clean;
    std::shared_ptr<PlantBase> plant;
    static int totalContainers;

public:
    Container();
    Container(const Container& other);
    Container& operator=(Container other);
    void disinfect();
    bool plantSeed(std::shared_ptr<PlantBase> p);
    void simulatePlantGrowth() const;
    std::shared_ptr<PlantBase> getPlant() const { return plant; }
    void setPlant(std::shared_ptr<PlantBase> newPlant);
    bool hasPlant() const { return plant != nullptr; }

    friend std::ostream& operator<<(std::ostream& os, const Container& c);

    static int getTotalContainers() { return totalContainers; }
};

#endif
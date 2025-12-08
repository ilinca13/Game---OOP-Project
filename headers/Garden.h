//
// Created by horeanga on 02/11/2025.
//



#ifndef OOP_GARDEN_H
#define OOP_GARDEN_H

#include <vector>
#include <memory>
#include "Container.h"

class Garden {
private:
    std::vector<std::shared_ptr<Container>> containers;
public:
    void addContainer(std::shared_ptr<Container> c);
    void simulateGrowth();
    const std::vector<std::shared_ptr<Container>>& getContainers() const { return containers; }
    friend std::ostream& operator<<(std::ostream& os, const Garden& g);
};

#endif


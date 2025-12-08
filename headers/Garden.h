//
// Created by horeanga on 02/11/2025.
//

/*#ifndef OOP_GARDEN_H
#define OOP_GARDEN_H

#include <vector>
#include "Container.h"

class Garden {
private:
    std::vector<Container*> containers;  // stocăm pointeri, nu copii
public:
    void addContainer(Container& c);     // referință, nu const!
    void simulateGrowth();

    friend std::ostream& operator<<(std::ostream& os, const Garden& g);
};

#endif //OOP_GARDEN_H*/

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


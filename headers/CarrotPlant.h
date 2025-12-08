//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_CARROTPLANT_H
#define GAME_OOP_PROJECT_CARROTPLANT_H

#endif //GAME_OOP_PROJECT_CARROTPLANT_H*/

#ifndef OOP_CARROTPLANT_H
#define OOP_CARROTPLANT_H

#include "PlantBase.h"

class CarrotPlant : public PlantBase {
private:
    int size; // specific attribute
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    CarrotPlant();
    CarrotPlant(const CarrotPlant& other) = default;
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};

#endif
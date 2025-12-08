//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_PEPPERPLANT_H
#define GAME_OOP_PROJECT_PEPPERPLANT_H

#endif //GAME_OOP_PROJECT_PEPPERPLANT_H*/

#ifndef OOP_PEPPERPLANT_H
#define OOP_PEPPERPLANT_H


#include "PlantBase.h"

class PepperPlant : public PlantBase {
private:
    int spiciness;
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    PepperPlant();
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};

#endif
//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_CORNPLANT_H
#define GAME_OOP_PROJECT_CORNPLANT_H

#endif //GAME_OOP_PROJECT_CORNPLANT_H*/

#ifndef OOP_CORNPLANT_H
#define OOP_CORNPLANT_H

#include "PlantBase.h"

class CornPlant : public PlantBase {
private:
    int height;
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    CornPlant();
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};
#endif
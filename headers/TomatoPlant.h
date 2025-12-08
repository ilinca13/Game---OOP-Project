//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_TOMATOPLANT_H
#define GAME_OOP_PROJECT_TOMATOPLANT_H

#endif //GAME_OOP_PROJECT_TOMATOPLANT_H*/

#ifndef OOP_TOMATOPLANT_H
#define OOP_TOMATOPLANT_H

#include "PlantBase.h"

class TomatoPlant : public PlantBase {
private:
    int ripeness;
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    TomatoPlant();
    explicit TomatoPlant(bool startSick);
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};
#endif
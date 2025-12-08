//
// Created by horeanga on 08/12/2025.
//

/*#ifndef GAME_OOP_PROJECT_TOXICBLOOM_H
#define GAME_OOP_PROJECT_TOXICBLOOM_H

#endif //GAME_OOP_PROJECT_TOXICBLOOM_H*/

#ifndef OOP_TOXICBLOOM_H
#define OOP_TOXICBLOOM_H

#include "PlantBase.h"

class ToxicBloom : public PlantBase {
private:
    int toxicity;
protected:
    void growImpl() override;
    void printImpl(std::ostream& os) const override;
public:
    ToxicBloom();
    explicit ToxicBloom(bool startSick);
    Item harvest() override;
    std::shared_ptr<PlantBase> clone() const override;
};

#endif
//
// Created by horeanga on 02/11/2025.
//

#ifndef OOP_POTION_H
#define OOP_POTION_H

#include <string>
#include <iostream>

//Clasa Potion reprezinta potiunile pentru dezinfectat containere reciclate sau pentru vindecat plante
class Potion
{
private:
    std::string name;
    int potency; //cat de eficienta este -> pentru tema 2 pot extinde cu potiuni cu efecte diferite si puteri anume
public:
    explicit Potion(const std::string& name = "Basic Potion", int potency = 1);
    [[nodiscard]] int getPotency()  const;
   [[nodiscard]] const std::string& getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Potion& p);
};
#endif //OOP_POTION_H
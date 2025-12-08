//
// Created by horeanga on 02/11/2025.
//

/*#ifndef OOP_POTION_H
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
#endif //OOP_POTION_H*/

#ifndef OOP_POTION_H
#define OOP_POTION_H

#include <string>
#include <iostream>
#include <vector>

class Potion {
private:
    std::string name;
    int potency; // how strong
    static int totalPotionsLoaded;

public:
    explicit Potion(const std::string& name = "Basic", int potency = 1);
    Potion(const Potion& other);
    Potion& operator=(Potion other);
    const std::string& getName() const { return name; }
    int getPotency() const { return potency; }
    friend std::ostream& operator<<(std::ostream& os, const Potion& p);
    static std::vector<Potion> loadFromFile(const std::string& filename); // may throw FileReadException/DataFormatException
    static int getTotalPotionsLoaded() { return totalPotionsLoaded; }
};

#endif // OOP_POTION_H
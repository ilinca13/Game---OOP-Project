//
// Created by horeanga on 02/11/2025.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>
#include <iostream>

//Enum pentru nivelul de raritate al clasei
enum class RarityLevel
{
    Common = 1,
    Uncommon = 2,
    Rare = 3,
    Epic = 4,
    Legendary = 5
};

std::string raritytoString(RarityLevel r);
//Clasa Item reprezinta obiectele pe care jucatorul le poate obtine dupa ce o planta ajunge la maturitate
class Item
{
private:
    std::string name; //numele obiectului
    RarityLevel rarity; //raritatea
public:
    //Constructor cu parametrii default
    explicit Item(const std::string& name = "Unknown", RarityLevel rarity = RarityLevel::Common);
    //Operator de afisare pentru test
    friend std::ostream& operator<<(std::ostream& os, const Item& it);
};
#endif //OOP_ITEM_H
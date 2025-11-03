//
// Created by horeanga on 02/11/2025.
#include "Item.h"
//convertim RarityLevel in string pentru afisare
std::string raritytoString(RarityLevel r)
{
    switch (r)
    {
    case RarityLevel::Common: return "Common";
    case RarityLevel::Uncommon: return "Uncommon";
    case RarityLevel::Rare: return "Rare";
    case RarityLevel::Epic: return "Epic";
    case RarityLevel::Legendary: return "Legendary";
    }
    return "Unknown";
}
//Constructor
Item::Item(const std::string& name, RarityLevel rarity) : name{name}, rarity{rarity} {}
//Operator<< afiseaza itemul cu raritate ca text
std::ostream& operator<<(std::ostream& os, const Item& it)
{
    os << it.name << " (rarity: " << raritytoString(it.rarity)<< ")";
    return os;
}

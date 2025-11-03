//
// Created by horeanga on 02/11/2025.
#include "Potion.h"

Potion::Potion(const std::string& name, int potency) : name{name}, potency{potency} {}
int Potion::getPotency() const { return potency; }
const std::string& Potion::getName() const { return name; }
std::ostream& operator<<(std::ostream& os, const Potion& p)
{
    os << " Potion("<< p.getName()  << " potency = " << p.getPotency() << ")";
    return os;
}
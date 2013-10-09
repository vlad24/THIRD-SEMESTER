#include "Computer.h"

Computer::Computer(OperatingSystem* system)
{
    OS = system;
    isInfected = false;
}

bool Computer::hasWeaknessesNow(Randomiser* randomiser) const
{
    double attackStrength = randomiser->pseudoRandomDouble(1);
    return (attackStrength > OS->defendFromVirusProbability);
}

OperatingSystem *Computer::getOS() const
{
    return OS;
}

Computer::~Computer()
{
    delete OS;
}

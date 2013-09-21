#include "Computer.h"

Computer::Computer(OperatingSystem* system)
{
    OS = system;
    isInfected = false;
}

bool Computer::tryToInfect()
{
    double attackStrength = randomiser.pseudoRandomDouble(1);
    return (attackStrength > this->OS->defendFromVirusProbability);
}

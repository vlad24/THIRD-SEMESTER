#pragma once
#include "Computer.h"

Computer::Computer(OperatingSystem* system)
{
    OS = system;
}

bool Computer::tryToInfect()
{
    attackStrength = randomiser.pseudoRandomDouble(1);
    return (atackStrength > OS.defendFromVirusProbability);
}

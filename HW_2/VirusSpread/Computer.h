#pragma once
#include "OperatingSystem.h"
#include "Randomiser.h"

class Computer
{
public:
    Computer(OperatingSystem* system);
    bool tryToInfect();
    bool isInfected;
private:
    OperatingSystem* OS;
    Randomiser randomiser;
};

#pragma once
#include "OperatingSystem.h"
#include "Randomiser.h"

class Computer
{
public:
    Computer(OperatingSystem* system);
    bool tryToInfect();
private:
    OperatingSystem OS;
    Randomiser randomiser;
};

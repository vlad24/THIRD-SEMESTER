#pragma once
#include "OperatingSystem.h"
#include "Randomiser.h"

//! A class that represents a computer that has an OS and can strugle with virus attacks

class Computer
{
public:
    Computer(OperatingSystem* system);
    bool hasWeaknessesNow(Randomiser* randomiser) const;
    OperatingSystem* getOS() const;
    bool isInfected;
    ~Computer();
private:
    OperatingSystem* OS;
};

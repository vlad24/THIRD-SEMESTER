#pragma once
#include "Randomiser.h"

//! A class which always returns zero as a random number. It is used for tests.

class ZeroRandomiser : public Randomiser
{
public:
    ZeroRandomiser();
    int pseudoRandomInt(int maximum) const;
    double pseudoRandomDouble(double maximum) const;
};

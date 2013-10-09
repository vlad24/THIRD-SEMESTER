#pragma once
#include "Randomiser.h"

//! A class which  returns one as a random number . It is used for tests.

class OneRandomiser : public Randomiser
{
public:
    OneRandomiser();
    int pseudoRandomInt(int maximum) const;
    double pseudoRandomDouble(double maximum) const;
};

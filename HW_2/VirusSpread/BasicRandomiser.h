#pragma once
#include "Randomiser.h"

//! An class which can generate int or float pseudo random numbers basing on the current time

class BasicRandomiser : public Randomiser
{
public:
    BasicRandomiser();
    int pseudoRandomInt(int maximum) const;
    double pseudoRandomDouble(double maximum) const;
private:
};

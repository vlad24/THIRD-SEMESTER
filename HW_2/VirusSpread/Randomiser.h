#pragma once

//! An interface class which can generate int or float pseudo random numbers basing on the current time

class Randomiser
{
public:
    virtual int pseudoRandomInt(int maximum) const = 0;
    virtual double pseudoRandomDouble(double maximum) const = 0;
};

#pragma once

//! A class which can generate int or float pseudo random numbers basing on the current time

class Randomiser
{
public:
    Randomiser();
    int pseudoRandomInt(int maximum) const;
    double pseudoRandomDouble(double maximum) const;
};

#include "Randomiser.h"
#include "QTime"
#include <cstdlib>

Randomiser::Randomiser()
{
}

int Randomiser::pseudoRandomInt(int maximum) const
{
    QTime timer = timer.currentTime();
    int randomNumber = timer.msec() + rand();
    return randomNumber % maximum;
}

double Randomiser::pseudoRandomDouble(double maximum) const
{
    QTime timer = timer.currentTime();
    int numerator = pseudoRandomInt(10);
    int denominator = pseudoRandomInt(10);
    denominator = denominator * denominator + 1;
    double randomNumber = double(numerator) / double(denominator);
    while (randomNumber > maximum)
    {
        randomNumber -= maximum;
    }
    return randomNumber;
}

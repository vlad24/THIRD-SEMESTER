#include "BasicRandomiser.h"
#include "QTime"
#include <cstdlib>

BasicRandomiser::BasicRandomiser()
{
}

int BasicRandomiser::pseudoRandomInt(int maximum) const
{
    QTime timer = timer.currentTime();
    int randomNumber = timer.msec() + rand();
    return randomNumber % maximum;
}

double BasicRandomiser::pseudoRandomDouble(double maximum) const
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

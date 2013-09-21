#include "Randomiser.h"
#include "QTime"

Randomiser::Randomiser()
{
}

int Randomiser::pseudoRandomInt(int maximum)
{
    QTime timer = timer.currentTime();
    int randomNumber = timer.msec();
    return randomNumber % maximum;
}

double Randomiser::pseudoRandomDouble(double maximum)
{
    QTime timer = timer.currentTime();
    int numerator = timer.second();
    int denominator = timer.minute();
    denominator = denominator * denominator + 1;
    double randomNumber = numerator / denominator;
    while (randomNumber > maximum)
    {
        randomNumber -= maximum;
    }
    return randomNumber;
}

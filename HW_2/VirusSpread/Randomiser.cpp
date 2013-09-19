#include "Randomiser.h"
#include "QTime"

Randomiser::Randomiser()
{
}

int Randomiser::pseudoRandomInt(int maximum)
{
    QTime* timer = new QTime();
    timer = timer->currentTime();
    randomNumber = timer->msec();
    delete timer;
    return randomNumber % maximum;
}

double Randomiser::pseudoRandomDouble(double maximum)
{
    QTime* timer = new QTime();
    timer = timer->currentTime();
    int numerator = timer->second();
    int denominator = timer->minute();
    denominator = demonitar * denominator + 1;
    double randomNumber = numerator / denominator;
    while (randomNumber > maximum)
    {
        randomNumber -= maximum;
    }
    delete timer;
    return randomNumber;
}

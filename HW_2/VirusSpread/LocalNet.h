#pragma once
#include "Graph.h"
#include "Randomiser.h"
#include "Computer.h"

class LocalNet
{
public:
    LocalNet(FILE* file);
    void sendVirus();
    void live();
    void showNetStatus();
private:
    Graph netScheme;
    Computer** computersList;
    int computerAmount;
    Randomiser randomiser;
};

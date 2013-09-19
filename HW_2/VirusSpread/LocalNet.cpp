#include "LocalNet.h"

LocalNet::LocalNet(FILE *file)
{
    netScheme = Graph(file);
    computerAmount = netScheme.getVertexAmount();
    computersList = new Computer[computerAmount];
    OperatingSystem* windows = new
    for (int i = 0; i < computerAmount; i++)
    {
        OSindex = randomiser.pseudoRandomInt(4);
        computersList[i] = Computer(OSTypes[OSindex]);
    }
}

void LocalNet::sendVirus()
{
    int firstVictimNumber = randomiser.pseudoRandomInt(computerAmount);
    computersInfectionStatus[firstVictimNumber] = true;
}

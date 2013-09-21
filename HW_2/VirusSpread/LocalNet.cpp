#include "LocalNet.h"
#include "MacOS.h"
#include "WindowsOS.h"
#include "LinuxOS.h"

LocalNet::LocalNet(FILE* file)
{
    netScheme = Graph();
    netScheme.createFromFile(file);
    computerAmount = netScheme.getVertexAmount();
    computersList = new Computer*[computerAmount];
    OperatingSystem* macOS = new MacOS();
    OperatingSystem* linuxOS = new LinuxOS();
    OperatingSystem* windowsOS = new WindowsOS();
    OperatingSystem* systemList[3] = {macOS, linuxOS, windowsOS};
    for (int i = 0; i < computerAmount; i++)
    {
        int OSindex = randomiser.pseudoRandomInt(4);
        computersList[i] = new Computer(systemList[OSindex]);
    }
}

void LocalNet::sendVirus()
{
    int firstVictimNumber = randomiser.pseudoRandomInt(computerAmount);
    computersList[firstVictimNumber]->isInfected = true;
}

void LocalNet::live()
{
    for (int i = 0; i < computerAmount; i++)
    {
        if (computersList[i]->isInfected)
        {
            int* neighbours = netScheme.getNeighbourNumbers(i);
            for (int j = 0; j < computerAmount; j++)
            {
                if (computersList[neighbours[j]]->tryToInfect())
                  computersList[neighbours[j]]->isInfected = true;
            }
        }
    }
}

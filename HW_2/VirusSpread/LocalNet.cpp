#include "LocalNet.h"
#include "MacOS.h"
#include "WindowsOS.h"
#include "LinuxOS.h"
#include "QTime"

LocalNet::LocalNet(FILE* file)
{
    netScheme.fillFromFile(file);
    computerAmount = netScheme.getVertexAmount();
    computersList = new Computer*[computerAmount];
    toBeIgnoredAtThisStep = new bool[computerAmount];
    for (int i = 0; i < computerAmount; i++)
    {
        int OSindex = randomiser.pseudoRandomInt(3);
        switch(OSindex)
        {
        case(0):
        {
            OperatingSystem* macOS = new MacOS();
            computersList[i] = new Computer(macOS);
            break;
        }
        case(1):
        {
            OperatingSystem* linuxOS = new LinuxOS();
            computersList[i] = new Computer(linuxOS);
            break;
        }
        case(2):
        {
            OperatingSystem* windowsOS = new WindowsOS();
            computersList[i] = new Computer(windowsOS);
            break;
        }
        }
    }
}

void LocalNet::sendVirus()
{
    int firstVictimNumber = randomiser.pseudoRandomInt(computerAmount);
    computersList[firstVictimNumber]->isInfected = true;
}

void LocalNet::work()
{
    for (int i = 0; i < computerAmount; i++)
    {
        toBeIgnoredAtThisStep[i] = false;
    }
    for (int i = 0; i < computerAmount; i++)
    {
        if (computersList[i]->isInfected)
        {
            int* neighbours = netScheme.getNeighbourNumbers(i);
            for (int j = 0; j < computerAmount; j++)
            {
                int connectedComputer = neighbours[j];
                if (connectedComputer > 0)
                {
                    if (computersList[connectedComputer]->hasWeaknessesNow())
                    {
                        computersList[connectedComputer]->isInfected = true;
                        toBeIgnoredAtThisStep[connectedComputer] = true;
                    }
                }
            }
        }
    }
}

void LocalNet::showNetStatus() const
{
    printf("\n Infected computers : ");
    for (int i = 0 ; i < computerAmount; i++)
    {
        if (computersList[i]->isInfected)
            printf("%d ", i);
    }
}

void LocalNet::showNetInfo() const
{
    for (int i = 0; i < computerAmount; i++)
    {
        if (computersList[i]->getOS()->defendFromVirusProbability - 0.5 < 0.05)
        {
            printf("%d computer(WindowsOS).\n", i);
        }
        else if(computersList[i]->getOS()->defendFromVirusProbability - 0.7 < 0.05)
        {
            printf("%d computer(LinuxOS).\n", i);
        }
        else if(computersList[i]->getOS()->defendFromVirusProbability - 0.85 < 0.05)
        {
            printf("%d computer(MacOS).\n", i);
        }
    }
}

void LocalNet::makePause(int duration) const
{
    QTime pauseTime;
    pauseTime.start();
    while(pauseTime.elapsed() <= duration)
    {

    }
}

LocalNet::~LocalNet()
{
    for (int i = 0; i < computerAmount; i++)
    {
        computersList[i]->~Computer();
    }
    delete[] computersList;
    delete[] toBeIgnoredAtThisStep;
}

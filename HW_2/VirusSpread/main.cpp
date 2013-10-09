#include "LocalNet.h"
#include "BasicRandomiserTester.h"
#include "LocalNetTester.h"
#include "GraphTester.h"
#include <stdio.h>

const int workingMiliseconds = 8008;
const int pauseDuration = 1001;

int main()
{
    BasicRandomiserTester randomosTester;
    LocalNetTester netTester;
    GraphTester graphTester;
    QTest::qExec(&randomosTester);
    QTest::qExec(&netTester);
    QTest::qExec(&graphTester);
    Randomiser* randomos = new BasicRandomiser();
    FILE* netFile = fopen("net.txt", "r");
    LocalNet* net = new LocalNet(netFile, randomos);
    net->sendVirus();
    net->showNetInfo();
    QTime* workTime = new QTime();
    workTime->start();
    printf("%d:%d:%d \n",workTime->hour(),workTime->minute(), workTime->second());
    while(workTime->elapsed() < workingMiliseconds)
    {
        net->work();
        net->makePause(pauseDuration);
        net->showNetStatus();
        printf("(%d seconds elapsed)", workTime->elapsed() / 1000);
    }
    delete net;
    delete workTime;
    fclose(netFile);
    printf("\nComputers are destroyed\n");
}

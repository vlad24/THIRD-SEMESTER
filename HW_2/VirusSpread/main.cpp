#include "LocalNet.h"
#include "RandomiserTester.h"
#include "LocalNetTester.h"
#include "GraphTester.h"
#include <stdio.h>

const int workingSeconds = 10000;
const int pauseDuration = 250;

int main()
{
    RandomiserTester randomosTester;
    LocalNetTester netTester;
    GraphTester graphTester;
    QTest::qExec(&randomosTester);
    QTest::qExec(&netTester);
    QTest::qExec(&graphTester);
    FILE* netFile = fopen("net.txt", "r");
    LocalNet* net = new LocalNet(netFile);
    net->sendVirus();
    net->showNetInfo();
    QTime* workTime = new QTime();
    workTime->start();
    printf("%d:%d:%d \n",workTime->hour(),workTime->minute(), workTime->second());
    while(workTime->elapsed() < workingSeconds)
    {
        net->work();
        net->makePause(pauseDuration);
        net->showNetStatus();
        printf("(%d milliseconds elapsed)", workTime->elapsed());
    }
    delete net;
    delete workTime;
    fclose(netFile);
    printf("\nComputers are destroyed\n");
}

#include <stdio.h>
#include "RobotDestroyerTester.h"
#include "PointerListTester.h"
#include "GraphTester.h"

int main()
{
    int o = 0;
    scanf("%d", &o);
    RobotDestroyer* destroyer = new RobotDestroyer();
    FILE* fieldFile = fopen("_fieldFile.txt", "r");
    destroyer->createField(fieldFile);
    FILE* positionsFile = fopen("_robotsConfiguration.txt", "r");
    destroyer->fillStartPositions(positionsFile);
    fclose(positionsFile);
    delete destroyer;

    PointerListTester lTester;
    QTest::qExec(&lTester);
    RobotDestroyerTester dTester;
    QTest::qExec(&dTester);
    GraphTester gTester;
    QTest::qExec(&gTester);
}


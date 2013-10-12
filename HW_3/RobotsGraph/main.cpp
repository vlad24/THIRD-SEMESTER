#include "RobotDestroyerTester.h"
#include "GraphTester.h"

int main()
{
    GraphTester gTester;
    QTest::qExec(&gTester);
    RobotDestroyerTester dTester;
    QTest::qExec(&dTester);

    printf("#Field and robots start positions are going to be read from files\n");
    FILE* fieldFile = fopen("_fieldFile.txt", "r");
    FILE* robotsFile = fopen("_robotsConfiguration.txt", "r");

    RobotDestroyer* destroyer = new RobotDestroyer();
    destroyer->createField(fieldFile);
    destroyer->fillStartPositions(robotsFile);
    printf("#Field's been created, robots are put at their start positions.\n");

    if (destroyer->robotsCanDestroy())
        printf("Robots CAN destroy\n");
    else
        printf("Robots CANNOT destroy\n");

    delete destroyer;
    fclose(fieldFile);
    fclose(robotsFile);
}

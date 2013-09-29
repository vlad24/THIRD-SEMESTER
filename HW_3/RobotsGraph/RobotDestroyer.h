#pragma once
#include "Graph.h"
#include "PointerList.h"

class RobotDestroyer
{
    friend class RobotDestroyerTester;
public:
    RobotDestroyer();
    void createField(FILE *fieldFile);
    void fillStartPositions(FILE* positionsFile);
    void markVertecesByRobots();
    ~RobotDestroyer();
private:
    Graph* field;
    int robotsAmount;
    PointerList** robotsAtTheVertex;
    void markVertexByOneRobot(int robot, int robotPosition, int step);
    int* startPositions;
    int* alive;
};

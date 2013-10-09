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
    bool robotsCanDestroy();
    ~RobotDestroyer();
private:
    Graph* field;
    int* robotFromThisVertex;
    Graph* pathField;
    int robotsAmount;
    void createPathField();
    void markComponent(int currentVertex, bool *&passedNow);
    int countRobotsInComponent(bool* isInComponent);
};

#pragma once
#include "Graph.h"

/*! A class which can figure out if robots with predefined positions at the predefined field can destroy
    after some sequence of steps (zero or double steps)*/

class RobotDestroyer
{
    friend class RobotDestroyerTester;
public:
    RobotDestroyer();
    //! A function which creates a field from the special file, representing the field as a graph
    void createField(FILE *fieldFile);
    //! A function which puts robots at their start positions, getting info from file where robot-vertex is written
    void fillStartPositions(FILE* positionsFile);
    //! A function which figures out whether their is a sequence of steps after which all robots will be crashed
    bool robotsCanDestroy();
    ~RobotDestroyer();
private:
    Graph* field;
    int* robotFromThisVertex;
    //! New graph where two verteces are connected if there was a vertex between them in the old one
    Graph* pathField;
    int robotsAmount;
    void createPathField();
    //! A function which indicates a component containing currentVertex by setting flags in passedNow array
    void markComponent(int currentVertex, bool *&passedNow);
    //! @param isInComponent array of flags which defines a component
    int countRobotsInComponent(bool* isInComponent);
};

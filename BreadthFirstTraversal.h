#ifndef BREADTHFIRSTTRAVERSAL_H
#define BREADTHFIRSTTRAVERSAL_H
#include <iostream>
#include <queue>
#include <unordered_set>
#include "FarmTraversal.h"
#include "CompositeFarm.h"
#include "FarmUnit.h"
#include "CropField.h"
#include "ExtraBarn.h"
using namespace std;

class BreadthFirstTraversal : public FarmTraversal
{
private:
    FarmUnit *root;
    queue<FarmUnit *> que;
    FarmUnit *curr;
    std::unordered_set<FarmUnit *> visited;

public:
    BreadthFirstTraversal(FarmUnit *root);
    ~BreadthFirstTraversal();
    FarmUnit *firstFarm() override;
    FarmUnit *next() override;
    bool isDone() override;
    FarmUnit *currentFarm() override;
};

#endif
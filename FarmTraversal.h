#ifndef FARMTRAVERSAL_H
#define FARMTRAVERSAL_H
#include <iostream>
using namespace std;
#include "FarmUnit.h"

class FarmTraversal
{
public:
    virtual ~FarmTraversal() = default;
    virtual FarmUnit *firstFarm() = 0;
    virtual FarmUnit *next() = 0;
    virtual bool isDone() = 0;
    virtual FarmUnit *currentFarm() = 0;
};
#endif
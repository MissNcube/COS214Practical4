#ifndef DEPTHFIRSTTRAVERSAL_H 
#define DEPTHFIRSTTRAVERSAL_H
#include  <iostream>
#include  <stack>
#include <unordered_set>
using namespace std;
#include "FarmTraversal.h"
#include "CompositeFarm.h"
#include "CropField.h"
#include "ExtraBarn.h"

class DepthFirstTraversal : public FarmTraversal
{
    private:
        FarmUnit * root;
        stack<FarmUnit*> stk;
        FarmUnit* curr;
        std::unordered_set<FarmUnit*> visited;
        
    public:
        DepthFirstTraversal(FarmUnit* root);
        ~DepthFirstTraversal();
        FarmUnit* firstFarm() override;
        FarmUnit* next() override;
        bool isDone() override;
        FarmUnit* currentFarm() override;
};

#endif //DEPTHFIRSTTRAVERSAL_H
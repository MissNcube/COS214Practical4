#include "DepthFirstTraversal.h"

DepthFirstTraversal::DepthFirstTraversal(FarmUnit *root) : root(root), curr(NULL)
{
    this->stk.push(this->root);
    visited.clear();
}

DepthFirstTraversal::~DepthFirstTraversal()
{
    while (!stk.empty())
    {
        FarmUnit *unit = stk.top();
        stk.pop();
        delete unit;
    }
    visited.clear();
}

FarmUnit *DepthFirstTraversal::firstFarm()
{
    if (!stk.empty())
    {
        curr = stk.top();
        return curr;
    }
    return NULL;
}

FarmUnit *DepthFirstTraversal::next()
{
    if (!stk.empty())
    {
        curr = stk.top();
        stk.pop();

        if (curr == NULL)
        {
            return NULL;
        }
        CompositeFarm *farm = dynamic_cast<CompositeFarm *>(curr);
        if (farm != NULL)
        {
            for (auto &it : farm->getFarmUnits())
            {
                if (it != NULL && visited.find(it) == visited.end())
                {
                    stk.push(it);
                    visited.insert(it);
                }
            }
        }
        return curr;
    }
    return NULL;
}

bool DepthFirstTraversal::isDone()
{
    return stk.empty();
}

FarmUnit *DepthFirstTraversal::currentFarm()
{
    return curr;
}

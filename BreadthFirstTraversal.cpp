#include "BreadthFirstTraversal.h"

BreadthFirstTraversal::BreadthFirstTraversal(FarmUnit *root) : root(root), curr(NULL)
{
    que.push(root);
    visited.insert(root);
}

BreadthFirstTraversal::~BreadthFirstTraversal()
{
    if (!que.empty())
    {
        que.pop();
    }
}

FarmUnit *BreadthFirstTraversal::firstFarm()
{
    if (!que.empty())
    {
        curr = que.front();
        return curr;
    }
    return NULL;
}

FarmUnit *BreadthFirstTraversal::next()
{
    if (!que.empty())
    {
        curr = que.front();
        que.pop();

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
                    que.push(it);
                    visited.insert(it);
                }
            }
        }
        return curr;
    }
    return NULL;
}

bool BreadthFirstTraversal::isDone()
{
    return que.empty();
}

FarmUnit *BreadthFirstTraversal::currentFarm()
{
    return curr;
}

#include "DepthFirstTraversal.h"

DepthFirstTraversal::DepthFirstTraversal(FarmUnit *root) : root(root), curr(nullptr)
{
    this->stk.push(this->root);
    visited.clear();
}

DepthFirstTraversal::~DepthFirstTraversal()
{
    while (!stk.empty())
    {
        // If stk contains pointers to dynamically allocated FarmUnits, delete them.
        FarmUnit* unit = stk.top();
        stk.pop();
        delete unit; // Assuming you own the memory
    }
    // Clear visited if necessary (not usually needed)
    visited.clear();
}

FarmUnit *DepthFirstTraversal::firstFarm()
{
    if(!stk.empty())
    {
        curr = stk.top();
        return curr;
    }
    return nullptr;
}

FarmUnit *DepthFirstTraversal::next()
{    if(!stk.empty())
    {
        curr = stk.top();
        stk.pop();

            if(curr == nullptr)
            {
                return nullptr;
            }
        CompositeFarm* ptr =  dynamic_cast<CompositeFarm*>(curr);
        if(ptr != nullptr)
        {
            for(auto& it :  ptr->getFarmUnits())
            {
                if(it != nullptr && visited.find(it) == visited.end())
                {
                    stk.push(it);
                    visited.insert(it);
                }
            }
        }
        return curr;
    }
    return nullptr;
}

bool DepthFirstTraversal::isDone()
{
    return stk.empty();
}

FarmUnit *DepthFirstTraversal::currentFarm()
{
    return curr;
}

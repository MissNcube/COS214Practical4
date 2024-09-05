#include "BreadthFirstTraversal.h"

BreadthFirstTraversal::BreadthFirstTraversal(FarmUnit* root) : root(root), curr(nullptr)
{
    que.push(root);
    visited.insert(root);
}

BreadthFirstTraversal::~BreadthFirstTraversal()
{
    if(!que.empty())
    {
        que.pop();
    }
    //que.clear();
    //delete root;
    //delete curr;
}

FarmUnit *BreadthFirstTraversal::firstFarm()
{
    if(!que.empty())
    {
        curr = que.front();
        return  curr;
    }
    return  nullptr;
}

FarmUnit *BreadthFirstTraversal::next()
{
    if(!que.empty())
    {
        curr = que.front();
        que.pop();

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
                    que.push(it);
                    visited.insert(it);
                }
            }
        }
        return curr;
    }
    return nullptr;
}

bool BreadthFirstTraversal::isDone()
{
    return que.empty();
}

FarmUnit *BreadthFirstTraversal::currentFarm()
{
    return curr;
}

#include "DepthFirstTraversal.h"

DepthFirstTraversal::DepthFirstTraversal(FarmUnit *root) : root(root), curr(nullptr)
{
    this->stk.push(this->root);
}

DepthFirstTraversal::~DepthFirstTraversal()
{
    if(!stk.empty())
    {
        delete stk.top();
        stk.pop();
    }
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
{    while (!stk.empty()) {
        curr = stk.top();
        stk.pop();

        // Skip if the current node is already visited or null
        if (curr == nullptr) {
            continue; // Skip to the next iteration
        }

        // Check if already visited
        if (visited.find(curr) != visited.end() || curr == nullptr) {
            continue; // Skip to the next iteration
        }

        visited.insert(curr); // Mark this node as visited

        // Check if the current node is a CompositeFarm
        CompositeFarm* ptr = dynamic_cast<CompositeFarm*>(curr);
        if (ptr != nullptr) {
            // Push child farms onto the stack in reverse order
            for (auto index = ptr->getFarmUnits().rbegin(); index != ptr->getFarmUnits().rend(); ++index) {
                if (*index != nullptr) {
                    cout << "Pushing onto stack: " << (*index)->getName() << endl;
                    stk.push(*index);
                } else {
                    cout << "Encountered null farm unit" << endl; // Debug output for null units
                }
            }
        }

        return curr; // Return the current valid node
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

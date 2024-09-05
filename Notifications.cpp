#include "Notifications.h"
#include <iostream>
#include <algorithm>


using namespace std;


Notifications::~Notifications()
{
    for(Truck* truck : obs)
    {
        delete truck;
    }
}

void Notifications::addTruck(Truck *trk)
{
    obs.push_back(trk);
    std::cout << "Truck added to notifications." << std::endl;
}

void Notifications::removeTruck(Truck *trk)
{
    obs.erase(std::remove(obs.begin(), obs.end(), trk), obs.end());
        std::cout << "Truck removed from notifications." << std::endl;
}

void Notifications::notifyTruck()
{
    for(Truck* truck : obs)
    {
        truck->callTruck();
    }
}

size_t Notifications::getCount() const
{
    return obs.size();
}

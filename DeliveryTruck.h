#ifndef DELIVERYTRUCK_H
#define DELIVERYTRUCK_H

#include "Truck.h"
#include "CropField.h"


class DeliveryTruck : public Truck
{
    private:
    CropField* field;
    Truck* count;
    int id;
    int called;

    public:
    DeliveryTruck( CropField* field ,int threshold , int id,int cap);
    ~DeliveryTruck();
    void callTruck() override;
    void startEngine() override;
    int getId() ;
    int getCallCounter();
    // std::string getType() const override;
};


#endif
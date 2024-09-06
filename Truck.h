#ifndef TRUCK_H
#define TRUCK_H

class CropField;

class Truck
{

protected:
    int threshold;
    int id;
    int capacity;
    int callCounter;
    CropField *field;

public:
    Truck(CropField *field, int threshold, int id, int capacity);
    virtual ~Truck() = default;
    virtual void callTruck() = 0;
    virtual void startEngine() = 0;
    int getId() const;
    int getThreshold() const;
    int getCapacity() const;
    int getCallCounter() const;
};

#endif
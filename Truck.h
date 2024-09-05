#ifndef TRUCK_H
#define TRUCK_H


class CropField;

class Truck
{
    protected:
    int thresH;
    int id;
    int capacity;
    CropField* field;


    private:
    int callCounter;
   

    public:
    Truck(CropField* field, int threshold, int id, int capacity);
    virtual ~Truck()=default;
    virtual void callTruck() = 0;
    virtual void startEngine() =0;
    // virtual std::string getType() const =0;

    // virtual void stopEngine() = 0;
    bool shouldSell() const;
    void increCounter();

    int getCalls() const;
    int getId() const;
};

#endif

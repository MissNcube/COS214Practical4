#include <iostream>
#include "CompositeFarm.h"
#include "CropField.h"
#include "FarmUnit.h"
#include "FloodedSoil.h"
#include "Fertilizer.h"
#include "ExtraBarn.h"
#include "DeliveryTruck.h"
#include "FertilizerTruck.h"
#include "TruckFactory.h"
#include "FarmTraversal.h"
#include "DepthFirstTraversal.h"
#include "BreadthFirstTraversal.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "Notifications.h"
#include "Truck.h"


void testComponent1();
void testComponent2();
void testComponent3();
void testComponent4();
void testComponent5();

int main()
{

    testComponent1();
    testComponent2();
    testComponent3();
    testComponent4();
    testComponent5();

    return 0;
}

void testComponent1()
{

    CropField *cornField = new CropField("Corn", 100, "CF001", "Field 1", 10.0, 20);
    std::cout << "+++++++++++++++++++CORNFIELD DATA+++++++++++++++++++++" << std::endl;
    cornField->displayDetails();
    cornField->updateSensorData("Pest Control(sPs/ml)", 880);
    std::cout << "Increased the pest control sensor to : " << cornField->getSensorData("Pest Control(sPs/ml)") << std::endl;

    CropField *wheatField = new CropField("Wheat", 150, "CF002", "Field 2", 15.0, 40);
    std::cout << "+++++++++++++++++++WheatField DATA+++++++++++++++++++++" << std::endl;
    wheatField->displayDetails();
    wheatField->updateSensorData("Moisture Level(%)", 70);
    std::cout << "Inceased the moisture to: " << wheatField->getSensorData("Moisture Level(%)") << std::endl;

    CompositeFarm *myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    std::cout << "+++++++++++++++++++FARM DATA+++++++++++++++++++++" << std::endl;
    myFarm->addUnit(cornField);
    myFarm->addUnit(wheatField);
    std::cout << "Total Capacity of the Farm: " << myFarm->getTotalCapacity() << std::endl;
    std::cout << "Crop Types in the Farm: " << myFarm->getCropType() << std::endl;
    std::cout << "Unit IDs in the Farms: " << myFarm->getUnitID() << std::endl;
    std::cout << "Locations in the Farms: " << myFarm->getLocation() << std::endl;
    std::cout << "Energy Consumption of the Farm(kWh): " << myFarm->getEnergyConsumption() << std::endl;

    cornField->updateSensorData("Moisture", 25.5);
    std::cout << "Corn Field Moisture: " << cornField->getSensorData("Moisture") << std::endl;
    wheatField->updateSensorData("Temperature", 28.0);
    std::cout << "Wheat Field Temperature: " << wheatField->getSensorData("Temperature") << std::endl;

    delete myFarm;
}

void testComponent2()
{

    CropField *wheatField = new CropField("Wheat", 100, "CF001", "North Field", 500.0, 60);
    CropField *cornField = new CropField("Corn", 150, "CF002", "Field 2", 300.0, 45);

    CompositeFarm *myFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);

    myFarm->addUnit(wheatField);
    myFarm->addUnit(cornField);

    std::cout << "++++++++++++++++++++++++++STATES+++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Intial state of Wheat: " << wheatField->getSoilStateName() << std::endl;
    std::cout << "Intial state of Corn: " << cornField->getSoilStateName() << std::endl;

    DrySoil dy;
    FruitfulSoil fs;
    FloodedSoil fs2;

    double rainfall = 18.0;
    double rainfall2 = 14.0;
    double rainfall3 = 30.0;
    double rainfall4 = 9.0;

    // dry to fruitful
    std::cout << "\n=== Changing from dry to fruitful ===" << std::endl;
    int yield = dy.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield);
    std::cout << "State: " << dy.getName() << std::endl;
    std::cout << "Yield: " << yield << " units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << wheatField->getTotalCapacity() << std::endl;
    wheatField->rain(wheatField, rainfall);
    std::cout << "After rain, soil state: " << wheatField->getSoilStateName() << std::endl;

    std::cout << "\n=== Frutiful to flooed ===" << std::endl;
    int yield2 = fs.harvestCrops(cornField);
    cornField->setTotalCapacity(yield2);
    std::cout << "State: " << fs.getName() << std::endl;
    std::cout << "Yield: " << yield2 << " units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << cornField->getTotalCapacity() << std::endl;
    std::cout << "State name of cornfield: " << cornField->getSoilStateName() << std::endl;
    cornField->rain(cornField, rainfall3);
    std::cout << "After rain, soil state: " << cornField->getSoilStateName() << std::endl;

    std::cout << std::endl;

    wheatField->setSoilState(new FloodedSoil());
    cornField->setSoilState(new DrySoil());

    std::cout << "\n=== Set state manually ===" << std::endl;
    std::cout << wheatField->getSoilStateName() << std::endl;
    std::cout << cornField->getSoilStateName() << std::endl;

    std::cout << "\n=== Changing from flooded to dry ===" << std::endl;
    int yield3 = fs2.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield3);
    std::cout << "Yield: " << yield3 << " times units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << wheatField->getTotalCapacity() << std::endl;
    wheatField->rain(wheatField, rainfall4);
    std::cout << "After more rain, soil state: " << wheatField->getSoilStateName() << std::endl;
    int yield4 = dy.harvestCrops(wheatField);
    wheatField->setTotalCapacity(yield4);
    std::cout << "Yield: " << yield4 << " units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << wheatField->getTotalCapacity() << std::endl;

    std::cout << "\n=== Staying in dry state ===" << std::endl;
    int yield5 = dy.harvestCrops(cornField);
    cornField->setTotalCapacity(yield5);
    std::cout << "Yield: " << yield5 << " times units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << cornField->getTotalCapacity() << std::endl;
    cornField->rain(cornField, rainfall2);
    std::cout << "After more rain, soil state: " << cornField->getSoilStateName() << std::endl;
    int yield6 = dy.harvestCrops(cornField);
    cornField->setTotalCapacity(yield6);
    std::cout << "Yield: " << yield6 << " units of crops harvested." << std::endl;
    std::cout << "Total Capacity: " << cornField->getTotalCapacity() << std::endl;

    delete myFarm;
}

void testComponent3()
{
    CropField *cornField = new CropField("Tomatoes", 1000, "Field1", "North", 200, 50);
    CropField *potatoes = new CropField("Potato", 900, "CFT8", "Section6", 150, 50);
    CompositeFarm *farm1 = new CompositeFarm("OpenLand", "SpringField", 400);

    Fertilizer *ftl = new Fertilizer(tomatoes);
    ftl->increaseProduction();
    ftl2->increaseProduction();

    int yield = ftl->harvest();
    int t = ftl2->harvest();

    std::cout << "Increased Yield  of Tomatoes: " << yield << std::endl;
    std::cout << "Increased Yield of Potatoes: " << t << std::endl;

    ExtraBarn *barn = new ExtraBarn(tomatoes, 50);
    barn->add();
    barn2->add();

    int cap = barn->getLeftoverCapacity();
    std::cout << "Total increased capacity after an extra barn: " << cap << std::endl;

    farm1->addUnit(tomatoes);
    farm1->addUnit(potatoes);
    farm1->displayD();

    delete  farm1;
    delete barn;
    delete barn2;
    delete ftl;
    delete ftl2;

}

void testComponent4()
{
    std::cout << "++++++++++++++++++++++++++++++++CROPS++++++++++++++++++++++++++++++++++++++ " << std::endl;
    CropField *wheatField = new CropField("Wheat", 1500, "CF01", "North Field", 50.5, 500);
    CropField *potatoField = new CropField("Potato", 2500, "GYG8", "South Corner", 690, 800);
    CropField *sugarcaneField = new CropField("SugarCane", 3000, "DG8J", "Central Farm", 100, 1200);
    CropField *sunflowerField = new CropField("Sunflower", 2000, "FDF9", "Down East", 80, 600);
    std::cout << "Details of crops: " << std::endl;
    wheatField->displayDetails();
    potatoField->displayDetails();
    sugarcaneField->displayDetails();
    sunflowerField->displayDetails();
    std::cout << "++++++++++++++++++++++++++++++++FARM++++++++++++++++++++++++++++++++++++++++ " << std::endl;
    CompositeFarm *farm = new CompositeFarm("SIMBAFARM", "North West", 1500);
    farm->addUnit(wheatField);
    farm->addUnit(potatoField);
    farm->addUnit(sugarcaneField);
    farm->addUnit(sunflowerField);
    farm->displayD();
    std::cout << "++++++++++++++++++++++++++++TRUCKS FOR FIELDS++++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "=== Buying Trucks ===" << std::endl;
    Truck *truck = wheatField->buyTruck("DeliveryTruck", 100, 1, 200);
    DeliveryTruck *dtk = dynamic_cast<DeliveryTruck *>(truck);
    Truck *truck2 = potatoField->buyTruck("FertilizerTruck", 468, 55, 200);
    FertilizerTruck *ftk = dynamic_cast<FertilizerTruck *>(truck2);
    Truck *truck3 = sugarcaneField->buyTruck("FertilizerTruck", 468, 20, 200);
    FertilizerTruck *ftk2 = dynamic_cast<FertilizerTruck *>(truck3);
    Truck *truck4 = sunflowerField->buyTruck("DeliveryTruck", 580, 31, 880);
    DeliveryTruck *dtk2 = dynamic_cast<DeliveryTruck *>(truck4);

    std::cout << "\n=== Notifying Trucks ===" << std::endl;
    wheatField->notifyTrucks();
    std::cout << "Count of delivery truck for wheatfield: " << dtk->getCallCounter() << std::endl;
    potatoField->notifyTrucks();
    std::cout << "Count of fertilizer truck for potatofield: " << ftk->getCallCounter() << std::endl;
    sugarcaneField->notifyTrucks();
    std::cout << "Count of fertilizer truck for potatofield: " << ftk2->getCallCounter() << std::endl;
    // sunflowerField->notifyTrucks();
    std::cout << "Count of delivery truck for sunflowerfield: " << dtk2->getCallCounter() << std::endl;

    std::cout << "Details of crops: " << std::endl;
    wheatField->displayDetails();
    potatoField->displayDetails();
    sugarcaneField->displayDetails();
    sunflowerField->displayDetails();

    std::cout << "\n=== Notifying a specific Truck ===" << std::endl;
    sugarcaneField->notifyTruck(ftk2);
    std::cout << "Details of crop: " << std::endl;
    sugarcaneField->displayDetails();

    std::cout << "\n=== Simulate Crop Storage Capacity and When soil is dry===" << std::endl;
    wheatField->currStorageCap();
    wheatField->currSoilState();
    std::cout << "Details of wheatField: " << std::endl;
    wheatField->displayDetails();
    potatoField->currStorageCap();
    potatoField->currSoilState();
    std::cout << "Details of potatoField: " << std::endl;
    potatoField->displayDetails();

    sugarcaneField->currStorageCap();
    sugarcaneField->currSoilState();
    std::cout << "Details of sugarcaneField: " << std::endl;
    sugarcaneField->displayDetails();

    std::cout << "\n===Attempting to sell an unused truck===" << std::endl;
    sunflowerField->sellTruck();
    std::cout << "\n===Attempting to sell a used truck===" << std::endl;
    wheatField->sellTruck();
    sugarcaneField->sellTruck();
    potatoField->sellTruck();

    std::cout << "++++++++++++++++++++++++++++TRUCKS FOR Farm++++++++++++++++++++++++++++++++ " << std::endl;

    std::cout << "\n===Total trucks in each field:===" << std::endl;
    std::cout << "Total trucks in wheatField: " << wheatField->getCount() << std::endl;
    std::cout << "Total trucks in potatoField: " << potatoField->getCount() << std::endl;
    std::cout << "Total trucks in sugarcaneField: " << sugarcaneField->getCount() << std::endl;
    std::cout << "Total trucks in sunflowerField: " << sunflowerField->getCount() << std::endl;
    std::cout << "\n===Total trucks in the farm:===" << std::endl;
    farm->addTruck(dtk);
    farm->addTruck(ftk);
    farm->addTruck(ftk2);
    farm->addTruck(dtk2);
     std::cout << "\n===Removing some trucks from the farm:===" << std::endl;
     farm->removeTruck(dtk);
     farm->removeTruck(ftk2);
     std::cout<<"Total Trucks in Farm: "<<farm->getTruckCount()<<std::endl;
    farm->updateSensorData("Temperature" , 50.60);
    std::cout<<"Updating the temperature sensors of the farm  to : "<<farm->getSensorData("Temperature")<<std::endl;



    


    



   




















    

}

void testComponent5()
{
    std::cout << "++++++++++++++++++++Adding CROPFields++++++++++++++++++++++ " << std::endl;
    CropField *cornField = new CropField("Corn", 100, "CF001", "North Field", 50.0, 20);
    CropField *wheatField = new CropField("Wheat", 150, "CF002", "South Field", 40.0, 25);
    CropField *soybeanField = new CropField("Soybean", 200, "CF003", "South-West Field", 60.0, 85);
    CropField *riceField = new CropField("Rice", 300, "CF004", "East Field", 30.0, 95);
    CropField *maizefield = new CropField("Maize", 100, "CF005", "West-side", 78.6, 100);

    std::cout << "++++++++++++++++++++++++++Adding Farm++++++++++++++++++++++++++++ " << std::endl;
    CompositeFarm *mainFarm = new CompositeFarm("Farm001", "Main Farm Location", 50.0);
    mainFarm->addUnit(cornField);
    mainFarm->addUnit(wheatField);
    mainFarm->addUnit(soybeanField);
    mainFarm->addUnit(riceField);
    mainFarm->addUnit(maizefield);

    std::cout << "++++++++++++++++++++++++++++BFT++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "Breadth-First Traversal:" << std::endl;
    BreadthFirstTraversal bfs(mainFarm);

    while (!bfs.isDone())
    {
        FarmUnit *current = bfs.next();
        if (current != NULL)
        {
            std::cout << "Visiting: " << current->getName() << std::endl;
        }
    }

    std::cout << std::endl;

    std::cout << "++++++++++++++++++++++++++++DFT+++++++++++++++++++++++++++++++ " << std::endl;
    std::cout << "Depth-First Traversal:" << std::endl;
    DepthFirstTraversal dfs(mainFarm);

    while (!dfs.isDone())
    {
        FarmUnit *current = dfs.next();
        if (current != NULL)
        {
            std::cout << "Visiting: " << current->getName() << std::endl;
        }
    }

    // Clean up dynamically allocated memory
    delete mainFarm; // This should recursively delete the other farm units
}

void testAll()
{

}
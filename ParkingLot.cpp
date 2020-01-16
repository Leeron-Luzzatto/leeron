#include "ParkingLot.h"
#include "ParkingLotPrinter.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorbike.h"
#include "Handicapped.h"
#include <iostream>

namespace MtmParkingLot{

    using std::cout;
    using std::endl;

    const int vehicle_types=3;
    ParkingLot::ParkingLot(unsigned int *parkingBlockSizes):
    blocks() {
        for(int i=0; i<vehicle_types; i++)
        blocks.push_back((UniqueArray<Vehicle>(parkingBlockSizes[i])));
    }

    Vehicle* createVehicle(VehicleType vehicleType, const LicensePlate& licensePlate, const Time& entranceTime){
        if(vehicleType==CAR) return new Car(licensePlate, entranceTime);
        if(vehicleType==MOTORBIKE) return new Motorbike(licensePlate, entranceTime);
        return new Handicapped(licensePlate, entranceTime);
    }

    bool ParkingLot::isExist(const Vehicle& v,VehicleType& block, unsigned int& index) const{
        VehicleType type=v.getType();
        block=type;
        if(type==MOTORBIKE)
            return blocks[MOTORBIKE].getIndex(v, index);
        bool is_in_cars=blocks[CAR].getIndex(v, index);
        if(type==CAR)
            return is_in_cars;
        if(type==HANDICAPPED){
            if(is_in_cars) {
                block = CAR;
                return true;
            }
            return blocks[HANDICAPPED].getIndex(v, index);
        }
        return false;
    }

    ParkingResult ParkingLot::enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime){
        Vehicle* new_v=createVehicle(vehicleType, licensePlate, entranceTime);
        unsigned int index;
        if(isExist(*new_v)){
            cout<<*new_v<<endl;
            ParkingLotPrinter::printEntryFailureAlreadyParked(cout,)
        }

    }

}
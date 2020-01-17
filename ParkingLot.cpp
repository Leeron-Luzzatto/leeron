#include "ParkingLot.h"
#include "ParkingLotPrinter.h"
#include "UniqueArray.h"
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

    ParkingResult ParkingLot::getParkingSpot(LicensePlate licensePlate, ParkingSpot& parkingSpot) const{
        VehicleType block;
        for(int b=0; b<vehicle_types; b++){
            block=(VehicleType)b;
            for(UniqueArray<Vehicle>::iterator i= blocks[block].begin(); i!=blocks[block].end(); ++i)

        }
    }

    bool ParkingLot::isEmptyBlock4Vehicle(VehicleType type, VehicleType &block) const{
        if(blocks[type].getSize()>blocks[type].getCount()){
            block=type;
            return true;
        }
        else if(type==HANDICAPPED && blocks[CAR].getSize()>blocks[CAR].getCount()){
            block=CAR;
            return true;
        }
        return false;
    }

    ParkingResult ParkingLot::enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime){
        Vehicle* new_v=createVehicle(vehicleType, licensePlate, entranceTime);
        unsigned int index;
        VehicleType block=MOTORBIKE;
        cout<<*new_v<<endl;
        if(isExist(*new_v, block, index)){
            ParkingLotPrinter::printEntryFailureAlreadyParked(cout, ParkingSpot(block, index));
            delete(new_v);
            return VEHICLE_ALREADY_PARKED;
        }
        if(isEmptyBlock4Vehicle(vehicleType, block)){
            index=blocks[block].insert(*new_v);
            ParkingLotPrinter::printEntrySuccess(cout, ParkingSpot(block, index));
            delete(new_v);
            return SUCCESS;
        }
        ParkingLotPrinter::printEntryFailureNoSpot(cout);
        delete(new_v);
        return NO_EMPTY_SPOT;
    }

}
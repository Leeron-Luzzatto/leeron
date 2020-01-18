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

    ParkingResult ParkingLot::getVehicle(const ParkingSpot &spot, Vehicle* result) const {
        VehicleType block=spot.getParkingBlock();
        unsigned index=spot.getParkingNumber();
        for(UniqueArray<Vehicle>::iterator i=blocks[block].begin(); i!=blocks[block].end(); ++i)
            if (i.getIndex()==index){
                result=&(*i);
                return SUCCESS;
            }
        return VEHICLE_NOT_FOUND;
    }

    ParkingResult ParkingLot::getParkingSpot(LicensePlate licensePlate, ParkingSpot& parkingSpot) const{
        VehicleType block;
        for(int b=0; b<vehicle_types; b++){
            block=(VehicleType)b;
            for(UniqueArray<Vehicle>::iterator i= blocks[block].begin(); i!=blocks[block].end(); ++i)
                if((*i).getLicensePlate()==licensePlate){
                    parkingSpot = ParkingSpot(block, i.getIndex());
                    return SUCCESS;
                }
        }
        return VEHICLE_ALREADY_PARKED;
    }

    bool ParkingLot::isEmptyBlock4Vehicle(const VehicleType& type, VehicleType &block) const{
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
        ParkingSpot spot(MOTORBIKE);
        if(getParkingSpot(licensePlate, spot)){
            Vehicle* found= nullptr;
            getVehicle(spot, found);
            cout<<*found<<endl;
            ParkingLotPrinter::printEntryFailureAlreadyParked(cout, spot);
            return VEHICLE_ALREADY_PARKED;
        }
        Vehicle* new_v=createVehicle(vehicleType, licensePlate, entranceTime);
        cout<<*new_v<<endl;
        VehicleType block=MOTORBIKE;
        if(isEmptyBlock4Vehicle(vehicleType, block)){
            unsigned index=blocks[block].insert(*new_v);
            ParkingLotPrinter::printEntrySuccess(cout, ParkingSpot(block, index));
            delete(new_v);
            return SUCCESS;
        }
        ParkingLotPrinter::printEntryFailureNoSpot(cout);
        delete(new_v);
        return NO_EMPTY_SPOT;
    }

    void ParkingLot::inspectParkingLot(Time inspectionTime){
        VehicleType block;
        unsigned fines=0;
        for(int b=0; b<vehicle_types; b++){
            block=(VehicleType)b;
            for(UniqueArray<Vehicle>::iterator i= blocks[block].begin(); i!=blocks[block].end(); ++i)
                if((*i).fineVehicle(inspectionTime)){
                    cout<<*i<<endl;
                    fines++;
                }
        }
        ParkingLotPrinter::printInspectionResult(cout, inspectionTime, fines);
    }

}
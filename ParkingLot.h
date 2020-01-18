#ifndef MTMPARKINGLOT_PARKINGLOT_H
#define MTMPARKINGLOT_PARKINGLOT_H

#include <vector>
#include "ParkingLotTypes.h"
#include "Time.h"
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "UniqueArray.h"

namespace MtmParkingLot {

    using namespace ParkingLotUtils;
    using std::ostream;
    using std::vector;
    const int fine_price=250;

    class ParkingLot {
        vector<UniqueArray<Vehicle> > blocks;

        static Vehicle* createVehicle(VehicleType vehicleType,
                const LicensePlate& licensePlate, const Time& entranceTime);
        bool isEmptyBlock4Vehicle(const VehicleType& type, VehicleType& block) const;
        ParkingResult getVehicle(const ParkingSpot& spot, Vehicle* result) const;
        void insertVehicleToBlock(VehicleType vehicleType, LicensePlate licensePlate,
                Time entranceTime, VehicleType block); //the method assumes there us a place 4 the vehicle in the block
    public:

        explicit ParkingLot(unsigned int parkingBlockSizes[]);
        ~ParkingLot()= default;
        ParkingResult enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime);
        ParkingResult exitParking(LicensePlate licensePlate, Time exitTime);
        ParkingResult getParkingSpot(LicensePlate licensePlate, ParkingSpot& parkingSpot) const;
        void inspectParkingLot(Time inspectionTime);
        friend ostream& operator<<(ostream& os, const ParkingLot& parkingLot);

    };

}

#endif //MTMPARKINGLOT_PARKINGLOT_H

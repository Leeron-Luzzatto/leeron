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
        bool isExist(const Vehicle& v,VehicleType& block, unsigned int& index) const;
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

#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	class Motorbike : public Vehicle {
	public:
		explicit Motorbike(LicensePlate licensePlate, Time entrance) :
			Vehicle(MOTORBIKE, licensePlate, entrance, Time(0, 6, 0), 10, 5) {
		}

		Motorbike(const Motorbike& other) = default;
	};
}
#endif //MOTORBIKE_H
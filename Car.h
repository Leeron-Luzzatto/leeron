#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	class Car: public Vehicle {
	public:
		explicit Car(LicensePlate licensePlate, Time entrance):
			Vehicle(CAR, licensePlate, entrance, Time(0,6,0), 20, 10) {
		}

		Car(const Car& other) = default;
	};
}
#endif //CAR_H

#ifndef HANDICAPPED_H
#define HANDICAPPED_H

#include "Car.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	class Handicapped : public Car {
	public:
		explicit Handicapped(LicensePlate licensePlate, Time entrance) :
			Car(HANDICAPPED, licensePlate, entrance) {
		}

		Handicapped(const Handicapped& other) = default;
		
		unsigned int getPrice(Time exit, unsigned int fine) const override final { return 15; }
	};
}
#endif //HANDICAPPED_H

#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {
	const unsigned int motorbike_first_price = 10;
	const unsigned int motorbike_extra_price = 5;
	const unsigned int motorbike_max_hour = 6;

	class Motorbike : public Vehicle {
	public:
		explicit Motorbike(LicensePlate licensePlate, Time entrance) :
			Vehicle(ParkingLotUtils::MOTORBIKE, licensePlate, entrance, Time(0, motorbike_max_hour, 0),
				motorbike_first_price, motorbike_extra_price) {
		}

		Motorbike(const Motorbike& other) = default;
	};
}
#endif //MOTORBIKE_H
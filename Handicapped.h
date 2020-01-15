#ifndef HANDICAPPED_H
#define HANDICAPPED_H

#include "Car.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace MtmParkingLot {

	const unsigned int handicapped_first_price = 15;
	const unsigned int handicapped_extra_price = 0;
	const unsigned int handicapped_max_hour = 1;

	class Handicapped : public Car {
	public:
		explicit Handicapped(LicensePlate licensePlate, Time entrance) :
			Car(licensePlate, entrance, handicapped_max_hour,
				handicapped_first_price, handicapped_extra_price) {}

		Handicapped(const Handicapped& other) = default;
		
		virtual VehicleType getType() const override {
			return ParkingLotUtils::HANDICAPPED;
}
	};
}
#endif //HANDICAPPED_H

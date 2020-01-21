#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace MtmParkingLot{

	const unsigned int car_first_price = 20;
	const unsigned int car_extra_price = 10;
	const unsigned int car_max_hour = 6;

	class Car : public Vehicle {
	public:
		explicit Car(LicensePlate licensePlate, Time entrance):
		Vehicle(licensePlate, entrance, Time(0, car_max_hour, 0), car_first_price, car_extra_price) {
		}

		Car(const Car& other) = default;

		virtual VehicleType getType() const override {
			return ParkingLotUtils::CAR;
		}
	};
}
#endif //CAR_H

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	const unsigned int car_first_price = 20;
	const unsigned int car_extra_price = 10;
	const unsigned int car_max_hour = 6;

	class Car: public Vehicle {
	public:
		explicit Car(LicensePlate licensePlate, Time entrance):
<<<<<<< HEAD
			Vehicle(ParkingLotUtils::CAR, licensePlate, entrance, Time(0,6,0),
			        20, 10) {
=======
			Vehicle(ParkingLotUtils::CAR, licensePlate, entrance, Time(0, car_max_hour,0),
				car_first_price, car_extra_price) {
>>>>>>> b7e955f21d3c463b957ae41b1a66ccdd22009012
		}

		Car(const Car& other) = default;
	};
}
#endif //CAR_H

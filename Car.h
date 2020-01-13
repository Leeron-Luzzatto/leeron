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
<<<<<<< HEAD
		explicit Car(LicensePlate licensePlate, Time entrance,
			VehicleType type= ParkingLotUtils::CAR): Vehicle(type, licensePlate, entrance,
				Time(0, car_max_hour,0), car_first_price, car_extra_price) {
=======
		explicit Car(LicensePlate licensePlate, Time entrance):
			Vehicle(CAR, licensePlate, entrance, Time(0,6,0), 20, 10) {
>>>>>>> ae1d8f7810b93d9efb7e35f50fdb169f9f1a9919
		}

		Car(const Car& other) = default;
	};
}
#endif //CAR_H

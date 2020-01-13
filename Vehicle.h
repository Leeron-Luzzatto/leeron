#ifndef VEHICLE_H
#define VEHICLE_H

#include "ParkingLotTypes.h"
#include "Time.h"
#include <iostream>

using std::ostream;
using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	class Vehicle {
		VehicleType type;
		LicensePlate licensePlate;
		Time entrance;
		unsigned int fines_counter;
		Time max_time;
		unsigned int price_for_first;
		unsigned int price_for_extra;

	public:
		explicit Vehicle(VehicleType vehicleType, LicensePlate licensePlate, Time entrance,
			Time max_time=Time(), unsigned int price_for_first=0, unsigned int price_for_extra=0)
			: type(vehicleType), licensePlate(licensePlate), entrance(entrance),max_time(max_time),
			fines_counter(0), price_for_first(price_for_first), price_for_extra(price_for_extra){
		}

		Vehicle(const Vehicle& other) = default;

		VehicleType getType() const { return type; }
		LicensePlate getLicensePlate() const { return licensePlate; }
		Time getEntranceTime() const { return entrance; }
		void fineVehicle() { fines_counter++; }
		virtual unsigned int getPrice(Time exit, unsigned int fine) const;
		friend ostream& operator<<(ostream& os, Vehicle vehicle);

		class Compare {
		public:
			Compare() = default;
			Compare(const Compare&) = default;
			bool operator()(Vehicle vehicle_one, Vehicle vehicle_two) const {
				return vehicle_one.licensePlate == vehicle_two.licensePlate;
			}
		};

	};
}
#endif //VEHICLE_H

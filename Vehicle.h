#ifndef VEHICLE_H
#define VEHICLE_H

#include "ParkingLotTypes.h"
#include "Time.h"

using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;

namespace Vehicle {

	class Vehicle {
	protected:
		VehicleType type;
		LicensePlate licensePlate;
		Time entrance;
		unsigned int fines_counter;

	public:
		explicit Vehicle(VehicleType vehicleType, LicensePlate licensePlate, Time entrance)
			: type(vehicleType), licensePlate(licensePlate), entrance(entrance), fines_counter(0) {}
		Vehicle(const Vehicle& other) : type(other.type), licensePlate(other.licensePlate),
			entrance(other.entrance), fines_counter(0) {}

		VehicleType getType() const { return type; }
		LicensePlate getLicensePlate() const { return licensePlate; }
		Time getEntranceTime() const { return entrance; }
		void fineVehicle() { fines_counter++; }
		virtual unsigned int getPrice(Time exit, unsigned int fine) const {}

		class Compare {
		public:
			bool operator()(Vehicle vehicle_one, Vehicle vehicle_two) const {
				return vehicle_one.licensePlate == vehicle_two.licensePlate;
			}
		};

	};
}
#endif //VEHICLE_H

#ifndef VEHICLE_H
#define VEHICLE_H

#include "ParkingLotTypes.h"
#include "Time.h"
#include "ParkingSpot.h"
#include <iostream>

using std::ostream;
using ParkingLotUtils::VehicleType;
using ParkingLotUtils::LicensePlate;
using ParkingLotUtils::Time;
using ParkingLotUtils::ParkingSpot;

namespace MtmParkingLot {

	class Vehicle {
		LicensePlate licensePlate;
		Time entrance;
		bool fine;
		Time max_time;
		ParkingSpot spot;
		unsigned int price_for_extra;
		unsigned int price_for_first;

	public:
		explicit Vehicle(LicensePlate licensePlate, Time entrance, Time max_time=Time(),
			ParkingSpot spot=ParkingSpot((VehicleType)0, 0),
			unsigned int price_for_extra=0, unsigned int price_for_first = 0)
			: licensePlate(licensePlate), entrance(entrance),max_time(max_time),
			spot(spot), fine(false), price_for_extra(price_for_extra), price_for_first(price_for_first) {
		}

		Vehicle(const Vehicle& other) = default;
        virtual ParkingSpot getSpot() const { return  spot; }
        virtual void setSpot(const ParkingSpot& new_spot) {spot=new_spot;}
		virtual VehicleType getType() const = 0;
		LicensePlate getLicensePlate() const { return licensePlate; }
		Time getEntranceTime() const { return entrance; }
        bool fineVehicle(const Time& inspection_time);
		bool operator==(const Vehicle& other) const{
			return licensePlate == other.licensePlate;
		}
		unsigned int getPrice(Time exit, unsigned int fine) const;
		friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
	};
}
#endif //VEHICLE_H

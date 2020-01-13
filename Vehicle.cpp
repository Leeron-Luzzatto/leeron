#include "Vehicle.h"

namespace Vehicle {
	unsigned int Vehicle::getPrice(Time exit, unsigned int fine) const {
		Time::Hour parking_duration = (exit - entrance).toHours();
		if (parking_duration > max_time.toHours()) {
			parking_duration = max_time.toHours();
		}
		unsigned int price = 0;
		for (Time::Hour i = 0; i < parking_duration; i++) {
			(i == 0) ? price += price_for_first : price += price_for_extra;
		}
		return price + fine * fines_counter;
	}
}
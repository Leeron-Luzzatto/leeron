cmake_minimum_required(VERSION 3.15)
project(untitled15)

set(CMAKE_CXX_STANDARD 14)

add_executable(UniqueArrayImp.h UniqueArray.h ParkingSpot.h
        ParkingSpot.cpp MtmParkingLot.cpp ParkingLot.h ParkingLot.cpp
        ParkingLotPrinter.h ParkingLotPrinter.cpp
        ParkingLotTypes.h Time.h Time.cpp
        Car.h Handicapped.h Motorbike.h IteratedUniqueArray.h Vehicle.h Vehicle.cpp
        )
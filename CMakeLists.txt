cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror -Wextra -g -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined")
elseif(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror -Wextra -g -fno-omit-frame-pointer")
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

project(AEDAProject)

add_executable(AEDAProject main.cpp
        source/manager/airportManager.cpp source/manager/airportManager.h
        source/objects/airport.cpp source/objects/airport.h
        source/objects/flight.cpp source/objects/flight.h
        source/objects/maintenanceService.cpp source/objects/maintenanceService.h
        source/objects/passenger.cpp source/objects/passenger.h
        source/objects/plane.cpp source/objects/plane.h
        source/objects/ticket.cpp source/objects/ticket.h
        source/objects/groundTransport.cpp source/objects/groundTransport.h
        source/objects/dateTime.cpp source/objects/dateTime.h
        source/objects/luggageCar.h source/objects/luggageCar.cpp
        source/Menu.cpp source/Menu.h source/manager/flightManager.h
        source/manager/planeManager.cpp source/manager/planeManager.h
        source/manager/flightManager.cpp source/manager/luggageCarManager.cpp
        source/manager/luggageCarManager.h source/manager/maintenanceServiceManager.cpp
        source/manager/maintenanceServiceManager.h source/objects/luggage.cpp source/objects/luggage.h)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)


project(airportTest)

add_executable(airportTest testers/testAirport.cpp
        source/objects/airport.cpp source/objects/airport.h
        source/objects/dateTime.cpp source/objects/dateTime.h
        source/objects/groundTransport.cpp source/objects/groundTransport.h
        source/objects/flight.cpp source/objects/flight.h
        source/objects/passenger.cpp source/objects/passenger.h
        testers/testLuggageCar.cpp testers/testMaintenanceService.cpp
        )

project(planeTest)

add_executable(planeTest testers/testPlane.cpp
        source/objects/groundTransport.cpp source/objects/groundTransport.h
        source/objects/plane.cpp source/objects/plane.h
        source/objects/dateTime.cpp source/objects/dateTime.h
        source/manager/planeManager.cpp source/manager/planeManager.h
        source/objects/flight.cpp source/objects/flight.h)

project(groundTest)

add_executable(groundTest
        source/objects/groundTransport.cpp source/objects/groundTransport.h
        source/objects/plane.cpp source/objects/plane.h
        source/objects/dateTime.cpp source/objects/dateTime.h
        source/objects/flight.cpp source/objects/flight.h)

project(flightTest)

add_executable(flightTest testers/testFlight.cpp
        source/objects/groundTransport.cpp source/objects/groundTransport.h
        source/objects/plane.cpp source/objects/plane.h
        source/objects/dateTime.cpp source/objects/dateTime.h
        source/manager/flightManager.cpp source/manager/flightManager.h
        source/objects/flight.cpp source/objects/flight.h)



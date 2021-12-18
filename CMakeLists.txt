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
        source/airport.cpp source/airport.h
        source/flight.cpp source/flight.h
        source/maintenanceService.cpp source/maintenanceService.h
        source/passenger.cpp source/passenger.h
        source/plane.cpp source/plane.h
        source/ticket.cpp source/ticket.h
        source/groundTransport.cpp source/groundTransport.h
        source/dateTime.cpp source/dateTime.h
        source/luggageCar.h source/luggageCar.cpp
        source/globalVariables.cpp source/globalVariables.h
        source/Menu.cpp source/Menu.h source/flightManager.h
        source/flightManager.cpp source/manager.h)

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
        source/airport.cpp source/airport.h
        source/dateTime.cpp source/dateTime.h
        source/groundTransport.cpp source/groundTransport.h
        source/flight.cpp source/flight.h
        source/passenger.cpp source/passenger.h source/manager.h)

project(planeTest)

add_executable(planeTest testers/testPlane.cpp
        source/groundTransport.cpp source/groundTransport.h
        source/plane.cpp source/plane.h
        source/dateTime.cpp source/dateTime.h
        source/planeManager.cpp source/planeManager.h
        source/flight.cpp source/flight.h source/manager.h)

project(groundTest)

add_executable(groundTest testers/testGroundTransport.cpp
        source/groundTransport.cpp source/groundTransport.h
        source/plane.cpp source/plane.h
        source/dateTime.cpp source/dateTime.h
        source/flight.cpp source/flight.h source/manager.h)

project(flightTest)

add_executable(flightTest testers/testFlight.cpp
        source/groundTransport.cpp source/groundTransport.h
        source/plane.cpp source/plane.h
        source/dateTime.cpp source/dateTime.h
        source/flightManager.cpp source/flightManager.h
        source/flight.cpp source/flight.h source/manager.h)



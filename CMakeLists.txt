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
        airportSystem/airport.cpp airportSystem/airport.h
        airportSystem/flight.cpp airportSystem/flight.h
        airportSystem/maintenanceService.cpp airportSystem/maintenanceService.h
        airportSystem/passenger.cpp airportSystem/passenger.h
        airportSystem/plane.cpp airportSystem/plane.h
        airportSystem/ticket.cpp airportSystem/ticket.h
        airportSystem/groundTransport.cpp airportSystem/groundTransport.h
        airportSystem/dateTime.cpp airportSystem/dateTime.h airportSystem/luggageCar.h airportSystem/luggageCar.cpp
        airportSystem/globalVariables.cpp airportSystem/globalVariables.h
        airportSystem/Menu.cpp airportSystem/Menu.h airportSystem/flightManager.h airportSystem/flightManager.cpp flightManagerTest.cpp)

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


project(groundTest)

add_executable(groundTest testGroundTransport.cpp
        airportSystem/dateTime.cpp airportSystem/dateTime.h
        airportSystem/groundTransport.cpp airportSystem/groundTransport.h)

project(airportTest)

add_executable(airportTest testAirport.cpp
        airportSystem/airport.cpp airportSystem/airport.h
        airportSystem/dateTime.cpp airportSystem/dateTime.h
        airportSystem/groundTransport.cpp airportSystem/groundTransport.h)

project(readerTest)

add_executable(readerTest testReader.cpp
        airportSystem/plane.cpp airportSystem/plane.h
        airportSystem/reader.cpp airportSystem/reader.h)




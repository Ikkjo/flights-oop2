//============================================================================
// Name        : Flight.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 
// Copyright   : 
// Description : 
//============================================================================
#pragma once

#include <string>
#include "FlightNumber.h"
#include "GateNumber.h"

class Flight
{
private:
	std::string destination;
	std::string departure;
	FlightNumber flight_num;
	GateNumber gate_num;
public:

};

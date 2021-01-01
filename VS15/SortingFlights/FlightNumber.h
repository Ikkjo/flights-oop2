//============================================================================
// Name        : Flight.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 
// Copyright   : 
// Description : 
//============================================================================
#pragma once

#include <string>
#include <regex>

class FlightNumber
{
private:
	std::string f_num;
public:
	FlightNumber(std::string);
	static bool isFlightNumber(std::string);
	bool operator==(const FlightNumber& other);
	bool operator>(const FlightNumber& other);

};


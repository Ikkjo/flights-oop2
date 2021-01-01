//============================================================================
// Name        : FlightNumber.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 28.12.2020.
// Copyright   : 
// Description : FlightNumber class header
//============================================================================
#pragma once

#include <string>
#include <regex>

class FlightNumber
{

public:
	std::string f_num;

	FlightNumber(std::string);

	static bool isFlightNum(std::string);

	bool operator==(const FlightNumber& p_rhs);
	bool operator>(const FlightNumber& p_rhs);
	bool operator<(const FlightNumber& p_rhs);

};


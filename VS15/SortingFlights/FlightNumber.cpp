//============================================================================
// Name        : FlightNumber.cpp
// Author      : Ilija Kalinic SW65/2019 
// Date        : 28.12.2020.
// Copyright   : 
// Description : Function definitions for FlightNumber class
//============================================================================
#include "FlightNumber.h"

FlightNumber::FlightNumber(std::string f_num) {
	if (FlightNumber::isFlightNum(f_num)) {
		this->f_num = f_num;
	}
	else {
		throw "Invalid Flight Number format! (Should be like: AB123)";
	}
}

bool FlightNumber::isFlightNum(std::string str) {
	/*Used for checking if input string
	matches the flight number format using std::regex
	*/
	bool is_fl_num = false;
	std::regex fnum_format = std::regex("[A-Z][A-Z][0-9][0-9][0-9]");

	if (std::regex_match(str, fnum_format) && str.length() == 5) {
		is_fl_num = true;
	}

	return is_fl_num;
}

// FlightNumber relation operators:
// Flight number comparison boils down to comparing strings

bool FlightNumber::operator==(const FlightNumber& p_rhs) {
	return this->f_num == p_rhs.f_num;
}

bool FlightNumber::operator>(const FlightNumber& p_rhs) {
	return this->f_num > p_rhs.f_num;
}

bool FlightNumber::operator<(const FlightNumber& p_rhs) {
	return this->f_num < p_rhs.f_num;
}
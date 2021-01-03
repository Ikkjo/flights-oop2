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


class Flight
{
private:
	std::string destination;
	std::string departure;
	std::string flightNo;
	std::string gateNo;

	static bool isFlightNo(std::string);
	static bool isGateNo(std::string);

public:
	Flight();
	Flight(std::string, std::string, std::string, std::string);
	~Flight();

	std::string getFlightNo();
	std::string getGateNo();
	std::string getDeparture();
	std::string getDestination();

	void setFlightNo(std::string);
	void setGateNo(std::string);
	void setDeparture(std::string);
	void setDestination(std::string);

	bool operator==(const Flight &p_rhs);
	Flight& operator=(const Flight &p_rhs);

};

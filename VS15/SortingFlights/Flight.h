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

using namespace std;

class Flight
{
private:
	string destination;
	string departure;
	string flightNo;
	string gateNo;

	static bool isFlightNo(string);
	static bool isGateNo(string);

public:
	Flight();
	Flight(std::string, std::string, std::string, std::string);
	~Flight();

	string getFlightNo();
	string getGateNo();
	string getDeparture();
	string getDestination();

	void setFlightNo(string);
	void setGateNo(string);
	void setDeparture(string);
	void setDestination(string);

	bool operator==(const Flight &p_rhs);
	Flight& operator=(const Flight &p_rhs);

};

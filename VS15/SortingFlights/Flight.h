//============================================================================
// Name        : Flight.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 
// Copyright   : 
// Description : 
//============================================================================
#pragma once

#include <string>

using namespace std;

class Flight
{
private:
	string destination;
	string departure;
	string flight_num;
	string gate_num;

	static bool isFlightNum(string);
	static bool isGateNum(string);

public:
	Flight(std::string, std::string, std::string, std::string);

	string getNumber();
	string getGateNumber();
	string getDeparture();
	string getDestination();

	void setNumber(string);
	void setGateNumber(string);
	void setDeparture(string);
	void setDestination(string);

	bool operator==(const Flight& p_rhs);
}
;
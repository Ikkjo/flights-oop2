//============================================================================
// Name        : Flight.h
// Author      : Ilija Kalinic SW65/2019 
// Description : Main class for data manipulation
//============================================================================
#pragma once

#include <string>
#include <regex>
#include <iostream>

enum class FlightDataMember {
	dest,
	dep,
	flNo,
	gtNo
};

class Flight
{
private:

	std::string destination;
	std::string departure;
	std::string flightNo;
	std::string gateNo;

	static bool is_valid_format(std::string, std::regex, int);
	static bool is_valid_format(std::string, std::regex, int, int);
	static bool is_valid_datamember(std::string, FlightDataMember);

public:
	// Constructors
	Flight();
	Flight(std::string, std::string, std::string, std::string);
	// Destructor
	~Flight();

	// Getters
	std::string getFlightNo();
	std::string getGateNo();
	std::string getDeparture();
	std::string getDestination();

	// Setters
	void setFlightNo(std::string);
	void setGateNo(std::string);
	void setDeparture(std::string);
	void setDestination(std::string);

	// Operator overloads
	bool operator==(const Flight &p_rhs);
	Flight& operator=(const Flight& p_rhs);

	// I/O stream operators
	friend std::istream& operator>>(std::istream&, Flight&);
	friend std::ostream& operator<<(std::ostream&, Flight&);

	// Other functions
	static std::vector<Flight> copy(std::vector<Flight> flights);
	static Flight copy(Flight fl);

	
};

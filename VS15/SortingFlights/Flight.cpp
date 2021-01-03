//============================================================================
// Name        : Flight.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the Flight class
//============================================================================

#include "Flight.h"

// Constructors

Flight::Flight() {
	flightNo = "AA000";
	gateNo = "A0";
	destination = std::string();
	departure = std::string();
};

Flight::Flight(std::string f_num, std::string dest,
			   std::string depart, std::string gate_num) {
	Flight::setFlightNo(f_num);
	this->destination = dest;
	this->departure = depart;
	Flight::setGateNo(gate_num);
}

//Destructor

Flight::~Flight() {}

// Private functions

bool Flight::isGateNo(std::string str) {
	/*Used for checking if input string
	matches the gate number format using std::regex
	*/
	bool is_gt_num = false;
	std::regex fnum_format = std::regex("[A-Z][0-9]");

	if (std::regex_match(str, fnum_format) && str.length() == 2) {
		is_gt_num = true;
	}

	return is_gt_num;
}


bool Flight::isFlightNo(std::string str) {
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

// Getters

std::string Flight::getDeparture() {
	return this->departure;
}

std::string Flight::getFlightNo() {
	return this->flightNo;
}

std::string Flight::getGateNo() {
	return this->gateNo;
}

std::string Flight::getDestination() {
	return this->destination;
}

// Setters

void Flight::setFlightNo(std::string fl_num) {
	if (Flight::isFlightNo(fl_num)) {
		this->flightNo = fl_num;
	}
	else {
		throw std::exception("Invalid Flight Number format! (Should be like: AB123)");
	}
}

void Flight::setGateNo(std::string gate_num) {
	if (Flight::isGateNo(gate_num)) {
		this->gateNo = gate_num;
	}
	else {
		throw std::exception("Invalid Gate Number format! (Should be like: A0)");
	}
}

void Flight::setDeparture(std::string departure) {
	this->departure = departure;
}

void Flight::setDestination(std::string destination) {
	this->destination = destination;
}

// Operator overloads

bool Flight::operator==(const Flight &p_rhs) {
	bool des = this->destination == p_rhs.destination;
	bool flNo = this->flightNo == p_rhs.flightNo;
	bool gtNo = this->gateNo == p_rhs.gateNo;
	bool dep = this->departure == p_rhs.departure;

	return des && flNo && gtNo && dep;
}

Flight& Flight::operator=(const Flight &p_rhs) {
	// String buffer allocation
	const int buffer = 50;
	char departure_buffer[buffer];
	char destination_buffer[buffer];
	char flightNo_buffer[buffer];
	char gateNo_buffer[buffer];

	// String copying
	size_t dep_len = p_rhs.departure.copy(departure_buffer, buffer);
	size_t dest_len = p_rhs.destination.copy(destination_buffer, buffer);
	size_t flightNo_len = p_rhs.flightNo.copy(flightNo_buffer, buffer);
	size_t gateNo_len = p_rhs.gateNo.copy(gateNo_buffer, buffer);

	// Adding string end
	departure_buffer[dep_len] = '\0';
	destination_buffer[dest_len] = '\0';
	flightNo_buffer[flightNo_len] = '\0';
	gateNo_buffer[gateNo_len] = '\0';

	this->destination = std::string(destination_buffer);
	this->departure = std::string(departure_buffer);
	this->flightNo = std::string(flightNo_buffer);
	this->gateNo = std::string(gateNo_buffer);

	return *this;
}
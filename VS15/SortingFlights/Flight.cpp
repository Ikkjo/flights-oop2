//============================================================================
// Name        : Flight.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the Flight class
//============================================================================

#include "Flight.h"
#include <algorithm>
// Constructors

Flight::Flight() {
	flightNo = "AA000";
	gateNo = "A0";
	destination = std::string();
	departure = "00:00";
};

Flight::Flight(std::string dest, std::string depart,
			   std::string f_num, std::string gate_num) {
	Flight::setFlightNo(f_num);
	this->destination = dest;
	Flight::setDeparture(depart);
	Flight::setGateNo(gate_num);
}

//Destructor

Flight::~Flight() {}

// Private functions

bool Flight::is_valid_format(std::string given_str, std::regex regex_format, int str_len) {

	if (std::regex_match(given_str, regex_format) && given_str.length() == str_len) {
		return true;
	}
	return false;
}

bool Flight::is_valid_format(std::string given_str, std::regex regex_format, int lower_bound, int upper_bound) {

	int given_len = given_str.length();
	if (std::regex_match(given_str, regex_format) &&  (given_len >= lower_bound && given_len <= upper_bound)) {
		return true;
	}
	return false;
}

bool Flight::is_valid_datamember(std::string given_str, FlightDataMember member) {
	/*Used for checking the correct string format of input data 
	Flight No., Departure and Gate No. atributes*/

	std::regex member_format;
	int member_strlen;
	int member_lb_len;
	int member_ub_len;
	bool is_valid = false;

	switch (member) {
	case FlightDataMember::flNo:
		member_format = std::regex("[A-Z][A-Z][0-9][0-9][0-9]");
		member_strlen = 5;
		is_valid = Flight::is_valid_format(given_str, member_format, member_strlen);
		break;

	case FlightDataMember::dep:
		member_format = std::regex("([0-1][0-9]|2[0-4]|[0-9]):[0-6][0-9]");
		member_lb_len = 3;
		member_ub_len = 5;
		is_valid = Flight::is_valid_format(given_str, member_format, member_lb_len, member_ub_len);
		break;

	case FlightDataMember::gtNo:
		member_format = std::regex("[A-Z][0-9]");
		member_strlen = 2;
		is_valid = Flight::is_valid_format(given_str, member_format, member_strlen);
		break;

	default:
		break;
	}

	return is_valid;

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
	if (Flight::is_valid_datamember(fl_num, FlightDataMember::flNo)) {
		this->flightNo = fl_num;
	}
	else {
		throw std::exception("Invalid Flight Number format! (Should be like: AB123)");
	}
}

void Flight::setGateNo(std::string gate_num) {
	if (Flight::is_valid_datamember(gate_num, FlightDataMember::gtNo)) {
		this->gateNo = gate_num;
	}
	else {
		throw std::exception("Invalid Gate Number format! (Should be like: A0)");
	}
}

void Flight::setDeparture(std::string departure) {
	if (Flight::is_valid_datamember(departure, FlightDataMember::dep)) {
		this->departure = departure;
	}
	else {
		throw std::exception("Invalid departure format! (Should be: HH:MM)");
	}
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

// @TODO: Refactor to use "string = string" operator
// Below definition is tested to be worki ng

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


std::istream& operator>>(std::istream& is, Flight& flight) {

	std::string dest;
	std::string dep;
	std::string flight_no;
	std::string gate_no;

	is >> dest >> dep >> flight_no >> gate_no;

	flight.setDestination(dest);
	flight.setDeparture(dep);
	flight.setFlightNo(flight_no);
	flight.setGateNo(gate_no);

	return is;
}

std::ostream& operator<<(std::ostream& os, Flight& flight) {
	os << "Flight No.  : " << flight.getFlightNo() << std::endl
	   << "Destination : " << flight.getDestination() << std::endl
	   << "Departure   : " << flight.getDeparture() << std::endl
	   << "Gate No.    : " << flight.getGateNo() << std::endl;

	return os;
		
}
//============================================================================
// Name        : Flight.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the Flight class
//============================================================================

#include "Flight.h"

Flight::Flight(string f_num, string dest, string depart, string gate_num) {
	this->flight_num = f_num;
	this->destination = dest;
	this->departure = depart;
	this->gate_num = gate_num;
}


bool Flight::isGateNum(std::string str) {
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


bool Flight::isFlightNum(std::string str) {
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


string Flight::getDeparture() {
	return this->departure;
}

string Flight::getNumber() {
	return this->flight_num;
}

string Flight::getGateNumber() {
	return this->gate_num;
}

string Flight::getDestination() {
	return this->destination;
}

void Flight::setNumber(string fl_num) {
	if (Flight::isFlightNum(fl_num)) {
		this->flight_num = fl_num;
	}
	else {
		throw "Invalid Flight Number format! (Should be like: AB123)";
	}
}

void Flight::setGateNumber(string gate_num) {
	if (Flight::isGateNum(gate_num)) {
		this->gate_num = gate_num;
	}
	else {
		throw "Invalid Gate Number format! (Should be like: A0)";
	}
}
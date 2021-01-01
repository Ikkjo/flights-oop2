//============================================================================
// Name        : GateNumber.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 01.01.2021.
// Copyright   : 
// Description : GateNumber class header
//============================================================================

#include "GateNumber.h"

GateNumber::GateNumber(std::string gate_num) {
	if (GateNumber::isGateNum(gate_num)) {
		this->gate_num = gate_num;
	}
	else {
		throw "Invalid Flight Number format! (Should be like: A0)";
	}
}

bool GateNumber::isGateNum(std::string str) {
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

bool GateNumber::operator==(const GateNumber& p_rhs) {
	return this->gate_num == p_rhs.gate_num;
}

bool GateNumber::operator<(const GateNumber& p_rhs) {
	return this->gate_num < p_rhs.gate_num;
}

bool GateNumber::operator>(const GateNumber& p_rhs) {
	return this->gate_num > p_rhs.gate_num;
}
//============================================================================
// Name        : GateNumber.h
// Author      : Ilija Kalinic SW65/2019 
// Date        : 01.01.2021.
// Copyright   : 
// Description : GateNumber class header
//============================================================================
#pragma once

#include <string>
#include <regex>

class GateNumber
{
public:
	std::string gate_num;

	GateNumber(std::string);

	static bool isGateNum(std::string gate_num);

	bool operator==(const GateNumber& p_rhs);
	bool operator<(const GateNumber& p_rhs);
	bool operator>(const GateNumber& p_rhs);

};


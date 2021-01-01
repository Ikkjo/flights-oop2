#include "FlightNumber.h"

FlightNumber::FlightNumber(std::string f_num) {
	if (FlightNumber::isFlightNumber(f_num)) {
		this->f_num = f_num;
	}
	else {
		throw "Invalid Flight Number format! (Should be: AB123)";
	}

}

bool FlightNumber::isFlightNumber(std::string str) {
	bool is_fl_num = false;

	std::regex fnum_format = std::regex("[A-Z][A-Z][0-9][0-9][0-9]");
	if (std::regex_match(str, fnum_format) && str.length() == 5) {
		is_fl_num = true;
	}

	return is_fl_num;
}
//============================================================================
// Name        : Sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the sort classes
//============================================================================

#include "Sort.h"

using namespace std;

unsigned long Sort::getNumCmps() {
	return this->num_cmps;
}

void Sort::resetNumCmps() {
	this->num_cmps = 0;
}


void SelectionSort::sort(vector<Flight>& flight_data, FlightDataMember sort_criterium) {
	
	// Switch case is used to call corresponding atribute SelectionSort alg
	 
	switch (sort_criterium) {
	case FlightDataMember::flNo:
		_sort_flNo(flight_data);
		break;

	case FlightDataMember::dep:
		_sort_dep(flight_data);
		break;

	case FlightDataMember::dest:
		_sort_dest(flight_data);
		break;

	default:
		_sort_flNo(flight_data);
		break;
	}
}

void SelectionSort::_sort_flNo(vector<Flight>& flight_data) {
	
	Flight min = flight_data[0];

	for (int i = 0; i < flight_data.size(); i++) {
		if (flight_data[i].getFlightNo() < min.getFlightNo()) {
			
		}
	}
}

void SelectionSort::_sort_dep(vector<Flight>& flight_data) {

}

void SelectionSort::_sort_dest(vector<Flight>& flight_data) {

}

void MergeSort::sort(vector<Flight>& flight_data, FlightDataMember sort_criterium) {

}
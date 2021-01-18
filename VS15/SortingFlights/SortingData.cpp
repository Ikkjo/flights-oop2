//============================================================================
// Name        : SortingData.cpp
// Author      : Ilija Kalinic SW65/2019
// Description : SortingData class used for displaying sort algorithm in gui definitions
//============================================================================


#include "SortingData.h"


SortingData::SortingData() {
	this->cmps = std::vector<unsigned long>();
	this->swaps = std::vector<unsigned long>();
	this->all_flights = std::vector<std::vector<Flight>>();
	this->iter = 0;
}

SortingData::SortingData(std::vector<unsigned long> cmps,
						 std::vector<unsigned long> swaps,
						 std::vector<std::vector<Flight>> flights,
	                     unsigned long iter) {
	this->cmps = cmps;
	this->swaps = swaps;
	this->all_flights = flights;
	this->iter = iter;

}

std::vector<unsigned long> SortingData::getNumCmps() {
	return cmps;
}

std::vector<unsigned long> SortingData::getNumSwaps() {
	return swaps;
}

std::vector<std::vector<Flight>> SortingData::getAllFlights() {
	return all_flights;
}

unsigned long SortingData::getIter() {
	return iter;
}
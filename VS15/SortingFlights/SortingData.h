//============================================================================
// Name        : SortingData.h
// Author      : Ilija Kalinic SW65/2019
// Description : DTO for GUI, used when displaying sort through iterations
//============================================================================


#pragma once

#include <vector>
#include "Flight.h"


class SortingData
{
private:
	// number of comparisons performed in sort function for each iteration
	std::vector<unsigned long> cmps;

	// number of element swapsperformed in sort function for each iteration
	std::vector<unsigned long> swaps;

	// poistions of all flights in vector from beggining to end
	std::vector<std::vector<Flight>> all_flights;

	// number of iterations (should be the same as size of vectors num_cmps, num_swaps, all_flights)
	unsigned long iter;

public:
	SortingData();
	SortingData(std::vector<unsigned long>,
				std::vector<unsigned long>,
				std::vector<std::vector<Flight>>,
				unsigned long iter);

	std::vector<unsigned long> getNumCmps();
	std::vector<unsigned long> getNumSwaps();
	std::vector<std::vector<Flight>> getAllFlights();
	unsigned long getIter();

};


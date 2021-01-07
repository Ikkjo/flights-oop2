//============================================================================
// Name        : Sort.h
// Author      : 
// Date        :
// Copyright   : 
// Description : Sort interface class and various sorting algorithms in C++
//============================================================================
#pragma once

#include "Flight.h"
#include <vector>


// Sort class
class Sort
{
protected:
	// number of comparisons performed in sort function
	unsigned long num_cmps;
	unsigned long num_swaps;
	unsigned long curr_iteration;
	std::vector<Flight> *current;
	
public:
	// main entry point
	virtual void sort(std::vector<Flight>& data, FlightDataMember) = 0;
	// returns number of comparisons
	unsigned long getNumCmps();
	// resets the number of comparisons
	void resetNumCmps();

	unsigned long getNumSwaps();

	unsigned long getIter();

	std::vector<Flight> getCurrentVec();

	void resetNumSwaps();

	void resetIter();

	void setCurrentVec(std::vector<Flight>* p_vec);
};

// SelectionSort class
class SelectionSort : public Sort
{
public:
	// main entry point
	SelectionSort();
	void sort(std::vector<Flight>& data, FlightDataMember);
};

// MergeSort class
class MergeSort : public Sort {
private:
	void merge(std::vector<Flight>& left, std::vector<Flight>& right, std::vector<Flight>& result, FlightDataMember sort_crit);
public:
	MergeSort();
	void sort(std::vector<Flight>& data, FlightDataMember);

};

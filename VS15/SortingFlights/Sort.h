//============================================================================
// Name        : Sort.h
// Author      : Ilija Kalinic
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
	// number of comparisons performed in sort function for each iteration
	std::vector<unsigned long> num_cmps;

	// number of element swapsperformed in sort function for each iteration
	std::vector<unsigned long> num_swaps;

	// poistions of all flights in vector from beggining to end
	std::vector<std::vector<Flight>> all_flights;

	// current (sorted) flight iteration
	std::vector<Flight> *current;

	// number of iterations (should be the same as size of vectors num_cmps, num_swaps, all_flights
	unsigned long iter;
	
public:
	// constructor
	Sort();

	// destructor
	~Sort();

	// main entry point
	virtual void sort(std::vector<Flight>& data, FlightDataMember) = 0;

	// getters

	std::vector<unsigned long> getNumSwaps();

	std::vector<unsigned long> getNumCmps();

	std::vector<Flight> getCurrentVec();

	std::vector<std::vector<Flight>> getAllFlights();

	unsigned long getIter();

	// setters

	//void setNumSwaps(std::vector<unsigned long>);

	//void setNumCmps(std::vector<unsigned long>);

	//void setAllFlights(std::vector<std::vector<Flight>>);

	//void setCurrentVec(std::vector<Flight>* p_vec);

	//void setIter(unsigned long);

	// additional functions

	void addNumSwaps(unsigned long, int index);

	void addNumCmps(unsigned long, int index);

	void addFlightIter(std::vector<Flight>, int index);

};

// SelectionSort class
class SelectionSort : public Sort
{
public:
	
	SelectionSort();
	// main entry point
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

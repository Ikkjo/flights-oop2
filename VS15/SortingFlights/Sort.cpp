//============================================================================
// Name        : Sort.cpp
// Author      : Iilja Kalinic SW65/2019
// Description : Implementation of the sort classes
//============================================================================

#include "Sort.h"

// getter definitions

std::vector<unsigned long> Sort::getNumCmps() {
	return this->cmps;
}

std::vector<unsigned long> Sort::getNumSwaps() {
	return this->swaps;
}

unsigned long Sort::getIter() {
	return this->iter;
}

std::vector<Flight> Sort::getCurrentVec() {
	
	const std::vector<Flight> vec_og = *this->current;
	std::vector<Flight> vec_cpy = std::vector<Flight>(vec_og);

	return vec_cpy;
}

std::vector<std::vector<Flight>> Sort::getAllFlights() {
	return this->all_flights;
}

Sort::Sort() {
	cmps = std::vector<unsigned long>();
	swaps = std::vector<unsigned long>();
	all_flights = std::vector<std::vector<Flight>>();
	current = nullptr;
	iter = 0;
}

Sort::~Sort() {}

// SelectionSort

SelectionSort::SelectionSort(): Sort() {}

void SelectionSort::sort(std::vector<Flight>& flight_data, FlightDataMember sort_criterium) {
	
	
	unsigned long num_of_cmps = 0, num_of_swaps = 0, iteration = 0;

	int i, j, min_index;
	Flight min, sub_first;
	bool new_min;

	for (i = 0; i < flight_data.size() - 1; i++) {

		min_index = i;

		

		for (j = i + 1; j < flight_data.size(); j++) {

			current = &flight_data;
			
			// Switch case is used to call corresponding atribute comparison
			switch (sort_criterium) {

			case FlightDataMember::flNo:
				new_min = flight_data[j].getFlightNo() <= flight_data[min_index].getFlightNo();
				break;

			case FlightDataMember::dep:
				new_min = flight_data[j].getDeparture() <= flight_data[min_index].getDeparture();
				break;

			case FlightDataMember::dest:
				new_min = flight_data[j].getDestination() <= flight_data[min_index].getDestination();
				break;

			default:
				new_min = false;
				break;
			}
			

			if (new_min) {
				min_index = j;

				min = flight_data[min_index];
				sub_first = flight_data[i];

				flight_data[i] = min;
				flight_data[min_index] = sub_first;
			
				num_of_swaps++;

			}

			iteration++;
			num_of_cmps++;

			this->cmps.push_back(num_of_cmps);
			this->swaps.push_back(num_of_swaps);

			std::vector<Flight> fls_cpy = flight_data;
			all_flights.push_back(fls_cpy);
		}
			
	}

	iter = iteration;
}

bool compareFlightAtribute(Flight& left, Flight& right, FlightDataMember sort_crit) {
	bool left_smaller_or_eq;

	switch (sort_crit) {

	case FlightDataMember::flNo:
		left_smaller_or_eq = left.getFlightNo() <= right.getFlightNo();
		break;

	case FlightDataMember::dep:
		left_smaller_or_eq = left.getDeparture() <= right.getDeparture();
		break;

	case FlightDataMember::dest:
		left_smaller_or_eq = left.getDestination() <= right.getDestination();
		break;

	default:
		left_smaller_or_eq = false;
		break;
	}

	return left_smaller_or_eq;
}

//MergeSort

MergeSort::MergeSort() : Sort() {}

void MergeSort::sort(std::vector<Flight>& flight_data, FlightDataMember sort_criterium) {

	std::vector<Flight>left;
	std::vector<Flight>right;

	if (flight_data.size() <= 1) {
		return;
	}

	int mid = flight_data.size() / 2;

	if (flight_data.size() % 2 == 1) {
		left = std::vector<Flight>(flight_data.begin(), flight_data.end() - mid - 1);
	}
	else {
		left = std::vector<Flight>(flight_data.begin(), flight_data.end() - mid);
	}
	
	right = std::vector<Flight>(flight_data.begin() + mid, flight_data.end());


	sort(left, sort_criterium);

	sort(right, sort_criterium);

	merge(left, right, flight_data, sort_criterium);

	std::vector<Flight> fls_cpy = flight_data;
	all_flights.push_back(fls_cpy);


}



void MergeSort::merge(std::vector<Flight>& left, std::vector<Flight>& right, std::vector<Flight>& result, FlightDataMember sort_crit) {
	unsigned long cmps = 0, swaps = 0, iterations = 0;

	int r_size = right.size();
	int l_size = left.size();
	int  j = 0, k = 0;

	while (j + k < result.size()) {
		
		if (k == r_size || (j < l_size && compareFlightAtribute(left[j], right[k], sort_crit))) {

			result[j+k] = left[j];
			
			if (k < r_size) {
				if (compareFlightAtribute(left[j], right[k], sort_crit)) {
					cmps++;
				}
			}


			j++;
			swaps++;
		}
		else {
			result[j+k] = right[k];
			
			if (j < l_size) {
				if (!compareFlightAtribute(left[j], right[k], sort_crit)) {
					cmps++;
				}
			}


			k++;
			swaps++;
		}

		iter = iterations;
		this->cmps.push_back(cmps);
		this->swaps.push_back(swaps);

		iterations++;
	}
}
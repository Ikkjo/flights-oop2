//============================================================================
// Name        : Sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of the sort classes
//============================================================================

#include "Sort.h"

// getter definitions

std::vector<unsigned long> Sort::getNumCmps() {
	return this->num_cmps;
}

std::vector<unsigned long> Sort::getNumSwaps() {
	return this->num_swaps;
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

// setter definitions

//void Sort::setCurrentVec(std::vector<Flight>* p_vec) {
//	current = p_vec;
//}
//
//void Sort::setNumSwaps(std::vector<unsigned long>) {
//	
//}
//
//void Sort::setNumCmps(std::vector<unsigned long>) {
//
//}
//
//void Sort::setAllFlights(std::vector<std::vector<Flight>>) {
//
//}
//
//void Sort::setIter(unsigned long) {
//
//}

Sort::Sort() {
	num_cmps = std::vector<unsigned long>();
	num_swaps = std::vector<unsigned long>();
	all_flights = std::vector<std::vector<Flight>>();
	current = nullptr;
	iter = 0;
}

Sort::~Sort() {}

// additional functions

void Sort::addNumSwaps(unsigned long, int index) {

}

void Sort::addNumCmps(unsigned long, int index) {

}

void Sort::addFlightIter(std::vector<Flight>, int index) {

}

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
				new_min = flight_data[j].getFlightNo() < flight_data[min_index].getFlightNo();
				break;

			case FlightDataMember::dep:
				new_min = flight_data[j].getDeparture() < flight_data[min_index].getDeparture();
				break;

			case FlightDataMember::dest:
				new_min = flight_data[j].getDestination() < flight_data[min_index].getDestination();
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

			num_cmps.push_back(num_of_cmps);
			num_swaps.push_back(num_of_swaps);

			std::vector<Flight> fls_cpy = Flight::copy(flight_data);
			all_flights.push_back(fls_cpy);
		}
			
	}

	iter = iteration;
}

//MergeSort

MergeSort::MergeSort() : Sort() {}

void MergeSort::sort(std::vector<Flight>& flight_data, FlightDataMember sort_criterium) {

	

	if (flight_data.size() <= 1) {
		return;
	}

	int mid = flight_data.size() / 2;

	std::vector<Flight>left(flight_data.begin(), flight_data.end() - mid);
	std::vector<Flight>right(flight_data.begin() + mid, flight_data.end());

	//cout << "Sort Left" << endl;
	sort(left, sort_criterium);
	//cout << "Sort Right" << endl;
	sort(right, sort_criterium);
	//cout << "Merge L and R" << endl;
	merge(left, right, flight_data, sort_criterium);


}

void MergeSort::merge(std::vector<Flight>& left, std::vector<Flight>& right, std::vector<Flight>& result, FlightDataMember sort_crit) {
	int r_size = right.size();
	int l_size = left.size();
	int i = 0, j = 0, k = 0;
	bool smaller;

	while (j < l_size && k < r_size) {
		switch (sort_crit) {

		case FlightDataMember::flNo:
			smaller = left[j].getFlightNo() < right[k].getFlightNo();
			break;

		case FlightDataMember::dep:
			smaller = left[j].getDeparture() < right[k].getDeparture();
			break;

		case FlightDataMember::dest:
			smaller = left[j].getDestination() < right[k].getDestination();
			break;

		default:
			smaller = false;
			break;
		}
		if (smaller) {
			result[i] = std::move(left[j]);
			j++;
		}
		else {
			result[i] = std::move(left[j]);
			k++;
		}
		i++;
	}

	//if (j < l_size && k < r_size) {
	std::move(&left[j], &left[l_size - 1], &result[i]);
	std::move(&right[k], &right[r_size - 1], &result[i]);
	//}
	//else if (j >= l_size) {
	//	move(&left[j - 1], &left[l_size], &result[i]);
	//	move(&right[k], &right[r_size], &result[i]);
	//}
	//else if (k >= l_size) {
	//	move(&left[j], &left[l_size], &result[i]);
	//	move(&right[k - 1], &right[r_size], &result[i]);
	//}
	//else {
	//	move(&left[j - 1], &left[l_size], &result[i]);
	//	move(&right[k - 1], &right[r_size], &result[i]);
	//}


	//cout << r_size << endl << l_size << endl << i << " " << j << " " << k << endl;

}
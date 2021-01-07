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

unsigned long Sort::getNumSwaps() {
	return this->num_swaps;
}

unsigned long Sort::getIter() {
	return this->curr_iteration;
}

vector<Flight> Sort::getCurrentVec() {
	
	const vector<Flight> vec_og = *this->current;
	vector<Flight> vec_cpy = vector<Flight>(vec_og);

	return vec_cpy;
}

void Sort::resetIter() {
	this->curr_iteration = 0;
}

void Sort::resetNumSwaps() {
	this->num_swaps = 0;
}

void Sort::setCurrentVec(vector<Flight>* p_vec) {
	current = p_vec;
}

SelectionSort::SelectionSort() {
	current = nullptr;
	this->curr_iteration = 0;
	this->num_cmps = 0;
	this->num_swaps = 0;
}

void SelectionSort::sort(vector<Flight>& flight_data, FlightDataMember sort_criterium) {
	
	// Switch case is used to call corresponding atribute comparison

	int i, j, min_index;
	Flight min, sub_first;
	bool new_min;

	for (i = 0; i < flight_data.size() - 1; i++) {

		min_index = i;

		this->curr_iteration++;

		for (j = i + 1; j < flight_data.size(); j++) {

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
			this->num_cmps++;

			if (new_min) {
				min_index = j;

				min = flight_data[min_index];
				sub_first = flight_data[i];

				flight_data[i] = min;
				flight_data[min_index] = sub_first;

				this->num_swaps++;

			}
		}
			
	}
}


MergeSort::MergeSort() {
	this->curr_iteration = 0;
	this->num_cmps = 0;
	this->num_swaps = 0;
	current = nullptr;
}

void MergeSort::sort(vector<Flight>& flight_data, FlightDataMember sort_criterium) {

	if (flight_data.size() <= 1) {
		return;
	}

	int mid = flight_data.size() / 2;
	vector<Flight> left(flight_data.begin(), flight_data.end() - mid);
	vector<Flight> right(flight_data.begin() + mid, flight_data.end());

	sort(left, sort_criterium);
	sort(right, sort_criterium);
	merge(left, right, flight_data, sort_criterium);


}

void MergeSort::merge(vector<Flight>& left, vector<Flight>& right, vector<Flight>& result, FlightDataMember sort_crit) {
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
			result[i] = left[j];
			j++;
		}
		else {
			result[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < l_size) {
		result[i] = left[j];
		j++;
		i++;
	}
	while (k < r_size) {
		result[i] = right[k];
		k++;
		i++;
	}

}
//============================================================================
// Name        : main.cpp
// Author      : Ilija Kalinic SW65/2019
// Date        : 28.12.2020.
// Copyright   :
// Description : Main project file used for running the program
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "Flight.h"
#include "Sort.h"
// #include "IOException.h"

using namespace std;

vector<Flight> readInputFile(string, char);
void writeOutputFile(vector<Flight>*, string, char);
void writeToConsole(vector<Flight>*);

void main(int argc, char* argv[])
{	
	string test_in = "C:\\Users\\Ilija\\Git Repos\\GitHub\\flights-oop2\\VS15\\Resources\\inputFileExample.txt";
	char csv_delimiter = ';';
	
	try{
		vector<Flight> flights = readInputFile(test_in, csv_delimiter);
		MergeSort s = MergeSort();
		cout << "============Unsorted=============" << endl;
		writeToConsole(&flights);
		s.sort(flights, FlightDataMember::dest);
		cout << "============Sorted===============" << endl;
		writeToConsole(&flights);
	}
	catch (exception e) {

	}
	
}

vector<Flight> readInputFile(string input_file, char delimiter) {
	/* NOTE: 
	*		- handles only CSV files with a char as a delimiter AND first line as header
	*		- there must be EXACTLY 4 data fields, corresponding to Flight constructor parameters,
	*		  in the exact order of [ destination, departure, flightNo, gateNo ]
	*	
	*  Veliki pozdrav
	*/

	vector<Flight> file_contents;
	ifstream ifs;
	ifs.open(input_file);

	// Invalid input handling
	if (ifs.bad() || ifs.fail()) {
		cout << "Invalid input file path! (" << input_file << ")" << endl;
		throw exception("Invalid input file path!");
	}

	// Reading input file
	string dest;
	string depart;
	string flightNo;
	string gateNo;
	
	string csv_header;
	getline(ifs, csv_header);
	
	while (!ifs.eof() && file_contents.size() < 10) {
		getline(ifs, dest, delimiter);
		getline(ifs, depart, delimiter);
		getline(ifs, flightNo, delimiter);
		getline(ifs, gateNo, delimiter);

		// Removes \n if dest starts with it

		if (dest.find('\n') != string::npos) {
			dest.erase(remove(dest.begin(), dest.end(), '\n'),
				dest.end());
			dest = dest.substr(1, dest.size()-1);
		};

		// Adds Flight to vector
		
		file_contents.push_back(Flight(dest, depart, flightNo, gateNo));
	}

	/* @TODO: FIX BUG
		last data entry appears twice in vector, second time without destination.
		The ifs buffer is probably being mishandled.
		- Fixed?
		The bug above dosent happen when only 10 data entries are loaded.
	*/
	return file_contents;

}


void writeOutputFile(vector<Flight>* sorted_flights, string output_path, char delimiter) {
	ofstream ofs;
	ofs.open(output_path);

	// Invalid path handling
	if (ofs.bad() || ofs.fail()) {
		cout << "Invalid output file path! (" << output_path << ")" << endl;
		throw exception("Invalid output file path!");
	}

	// Writing to output


}

void writeToConsole(vector<Flight>* p_flights) {
	for (Flight fl : *p_flights) {
		cout << fl << endl;
	}
	cout << endl << endl;
}

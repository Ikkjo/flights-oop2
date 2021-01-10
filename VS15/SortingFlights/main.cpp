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

vector<Flight> readInputFile(string, string* header, char);
void writeOutputFile(vector<Flight>*, string, string, char);
void writeToConsole(vector<Flight>*);
void setParamsFromArgs(int argc, char* argv[], string* in_f, string* out_f, FlightDataMember* crit, bool* merge_sort);

FlightDataMember getFDMFromStr(string);

void main(int argc, char* argv[])
{	
	string in_f, out_f, header;
	FlightDataMember criterium;
	bool merge_sort;		// If merge_sort flag is false, the sorting algorithm will be selection sort
	

//	string test_in = "..\\Resources\\inputFileExample.txt";

	setParamsFromArgs(argc, argv, &in_f, &out_f, &criterium, &merge_sort);
	char csv_delimiter = ';';
	


	try{
		vector<Flight> flights = readInputFile(in_f, &header, csv_delimiter);
		SelectionSort s = SelectionSort();
		cout << "============Unsorted=============" << endl;
		writeToConsole(&flights);
		s.sort(flights, FlightDataMember::dest);
		cout << "============Sorted===============" << endl;
		writeToConsole(&flights);

		writeOutputFile(&flights, out_f, header, csv_delimiter);

	}
	catch (exception e) {

	}
	
}

vector<Flight> readInputFile(string input_file, string* header, char delimiter) {
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
	*header = csv_header;
	
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


void writeOutputFile(vector<Flight>* sorted_flights, string output_path, string header, char delimiter) {
	ofstream ofs;
	ofs.open(output_path);

	// Invalid path handling
	if (ofs.bad() || ofs.fail()) {
		cout << "Invalid output file path! (" << output_path << ")" << endl;
		throw exception("Invalid output file path!");
	}

	// Writing to output file
	string dest;
	string depart;
	string flightNo;
	string gateNo;
	string csv_line;

	ofs << header << endl;

	for (Flight fl : *sorted_flights) {
		dest = fl.getDestination();
		depart = fl.getDeparture();
		flightNo = fl.getFlightNo();
		gateNo = fl.getGateNo();

		csv_line = dest + delimiter + depart + delimiter + flightNo + delimiter + gateNo + delimiter;

		ofs << csv_line << endl;
	}

}

void writeToConsole(vector<Flight>* p_flights) {
	for (Flight fl : *p_flights) {
		cout << fl << endl;
	}
	cout << endl << endl;
}

FlightDataMember getFDMFromStr(string crit_str) {
	FlightDataMember criterium;

	if (crit_str == "flNo" || crit_str == "flightNo") {
		criterium = FlightDataMember::flNo;
	}
	else if (crit_str == "gtNo" || crit_str == "gateNo") {
		criterium = FlightDataMember::gtNo;
	} else {
		criterium = FlightDataMember::dep;
	}
	

	return criterium;
}

void setParamsFromArgs(int argc, char* argv[], string* in_f,
	string* out_f, FlightDataMember* crit, bool* merge_sort) {
	
	string default_in_f = "..\\Resources\\inputFileExample.txt";
	string default_out_f = "..\\Resources\\outputFileExample.txt";

	if (argc >= 4) {
		*in_f = string(argv[1]);
		*out_f = string(argv[2]);
		*crit = getFDMFromStr(string(argv[3]));

		if (argc >= 5) {
			if (argv[4] == "merge") {
				*merge_sort = true;
			} 
		}
		else {
			*merge_sort = false;
		}
	}
	else
	{
		*in_f = default_in_f;
		*out_f = default_out_f;
		*crit = FlightDataMember::dep;
		*merge_sort = false;
	}
}

//============================================================================
// Name        : main.cpp
// Author      :
// Date        :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "Flight.h"

using namespace std;

vector<Flight> readInputFile(string, char);

void main(int argc, char* argv[])
{	
	string test_in = "C:\\Users\\Ilija\\Git Repos\\GitHub\\flights-oop2\\VS15\\Resources\\inputFileExample.txt";
	char csv_delimiter = ';';

	vector<Flight> flights = readInputFile(test_in, csv_delimiter);



	/*
	Previous test:


	Flight fl1, fl3;
	Flight* fl2;
	try {
		fl1 = Flight("LAS VEGAS", "21:15", "AA23", "A3");
	}
	catch (exception e) {
		cout << "An error has occured!" << endl;
		fl1 = Flight("LAS VEGAS", "21:15", "AA023", "A3");
	}
	
	fl2 = new Flight("DALLAS", "21:00", "BA036","A3");

	fl3 = fl1;

	fl1 = *fl2;
	string fl2flno = fl2->getFlightNo();
	bool cond = fl1.getFlightNo() == fl2flno;
	cout << fl3;
	cout << cond <<endl;

	delete fl2;
	*/
	
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
	
	while (!ifs.eof()) {
		getline(ifs, dest, delimiter);
		getline(ifs, depart, delimiter);
		getline(ifs, flightNo, delimiter);
		getline(ifs, gateNo, delimiter);
		
		file_contents.push_back(Flight(dest, depart, flightNo, gateNo));
	}

	/* @TODO: FIX BUG 
		last data entry appears twice in vector, second time without destination.
		The ifs buffer is probably being mishandled.
	*/
	return file_contents;

}

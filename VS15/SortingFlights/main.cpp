//============================================================================
// Name        : main.cpp
// Author      : Ilija Kalinic SW65/2019
// Description : Main project file used for running the program
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include "Flight.h"
#include "Sort.h"
#include "MainWindow.h"
#include "FileHandler.h"

using namespace std;

void writeToConsole(vector<Flight>*);
void setParamsFromArgs(int argc, char* argv[], string* in_f, string* out_f, FlightDataMember* crit, bool* merge_sort);
void GUI_main();

FlightDataMember getFDMFromStr(string);

void main(int argc, char* argv[])
{	
	
	// Command line arguments example -> inputFileExample.txt out1.txt flNo merge <-

	if (argc > 1) {
		string test_in = "..\\Resources\\inputFileExample.txt";
		string header;
		string in_f = "..\\Resources\\";
		string out_f = "..\\Resources\\";
		FlightDataMember criterium;
		bool merge_sort;		// If merge_sort flag is false, the sorting algorithm will be selection sort

		setParamsFromArgs(argc, argv, &in_f, &out_f, &criterium, &merge_sort);

		try {
			char csv_delimiter = ';';

			vector<Flight> flights = FileHandler::readInputFile(in_f, &header, csv_delimiter);

			MergeSort s = MergeSort();

			cout << "============Unsorted=============" << endl;

			writeToConsole(&flights);

			s.sort(flights, FlightDataMember::dest);

			cout << "============Sorted===============" << endl;

			writeToConsole(&flights);

			FileHandler::writeOutputFile(&flights, out_f, header, csv_delimiter);

		}
		catch (exception e) {}

	}
	else {
		try {
			GUI_main();
		}
		catch (exception e) {}
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
		*in_f += string(argv[1]);
		*out_f += string(argv[2]);
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
		cout << "Invalid arguments, sorting with default parameters..." << endl << endl;
		*in_f = default_in_f;
		*out_f = default_out_f;
		*crit = FlightDataMember::dep;
		*merge_sort = false;
	}
}


void GUI_main()
{
	MainWindow win(Point(200, 200), WINDOW_W, WINDOW_H, "Flight Sorter");
	win.setParameterOptionsAndSort();
}

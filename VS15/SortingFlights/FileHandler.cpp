#include "FileHandler.h"



vector<Flight> FileHandler::readInputFile(string input_file, string* header, char delimiter) {
	/* NOTE:
	*		- handles only CSV files with a char as a delimiter AND first line as header
	*		- there must be EXACTLY 4 data fields, corresponding to Flight constructor parameters,
	*		  in the exact order of [ destination, departure, flightNo, gateNo ]
	*
	*  
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
	string dest = "";
	string depart = "";
	string flightNo = "";
	string gateNo = "";

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
			dest = dest.substr(1, dest.size() - 1);
		};

		// Adds Flight to vector

		file_contents.push_back(Flight(dest, depart, flightNo, gateNo));
	}
	return file_contents;

}


void FileHandler::writeOutputFile(vector<Flight>* sorted_flights, string output_path, string header, char delimiter) {
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
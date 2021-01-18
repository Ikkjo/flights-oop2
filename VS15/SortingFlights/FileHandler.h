//============================================================================
// Name        : FileHandler.h
// Author      : Ilija Kalinic SW65/2019
// Description : File I/O handler class definition
//============================================================================


#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Flight.h"

using namespace std;

class FileHandler
{
public:
	static vector<Flight> readInputFile(string input_file, string* header, char delimiter);
	static void writeOutputFile(vector<Flight>* sorted_flights, string output_path, string header, char delimiter);

};


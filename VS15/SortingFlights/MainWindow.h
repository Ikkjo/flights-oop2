//============================================================================
// Name        : MainWindow.h
// Author      : Ilija Kalinic SW65/2019
// Description : Main Window class definition for GUI
//============================================================================

#pragma once


#define WINDOW_W			800
#define WINDOW_H			600
#define HOR_OFFSET			20
#define VER_OFFSET			20
#define BUTTON_W			100
#define BUTTON_H			20
#define SPACE				5
#define INBOX_H				20
#define INBOX_W				150
#define OUTBOX_H			20
#define OUTBOX_W			300

#include "Simple_window.h"
#include "Graph.h"
#include "Flight.h"
#include "FileHandler.h"
#include "SortingData.h"
#include "Sort.h"

using namespace Graph_lib;

class MainWindow : public Window
{
private:
	Button loadButton;
	Button quitButton;
	Button nextButton;

	In_box inputFileInBox;
	In_box outputFileInBox;
	In_box sortAlgInBox;
	In_box sortCriteriumInBox;

	Out_box vecPosition0;
	Out_box vecPosition1;
	Out_box vecPosition2;
	Out_box vecPosition3;
	Out_box vecPosition4;
	Out_box vecPosition5;
	Out_box vecPosition6;
	Out_box vecPosition7;
	Out_box vecPosition8;
	Out_box vecPosition9;

	Text iterationText;
	Text numOfCmpsText;
	Text numOfSwapsText;

	string input_file;
	string output_file;
	FlightDataMember sort_crit;
	bool merge_sort;

	unsigned int current_iter;

	SortingData sort_data;

	static void cb_load(Address, Address);
	static void cb_quit(Address, Address);
	static void cb_next(Address, Address);

	bool loadPushed;
	bool quitPushed;
	bool nextPushed;

	void load();
	void quit();
	void next();

	void updateOutBoxes(vector<Flight>);
	void updateIterationText(string);
	void updateNumOfCmpsText(string);
	void updateNumOfSwapsText(string);

	std::vector<Flight> initializeFlights(std::string in_f, std::string* header);
	void saveSortedFlights(string out_f, std::vector<Flight>, std::string);

public:
	MainWindow(Point xy, int w, int h, const string& title);
	void setParameterOptionsAndSort();
	~MainWindow();
};


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

using namespace Graph_lib;

class MainWindow : public Window
{
private:
	Button loadButton;
	Button quitButton;

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

	string input_file;
	string output_file;
	FlightDataMember sort_crit;
	bool merge_sort;

	static void cb_load(Address, Address);
	static void cb_quit(Address, Address);

	bool loadPushed;
	bool quitPushed;

	void load();
	void quit();

	void updateOutBoxes(vector<Flight>);

	void showInitialFlights(string* in_f);


	
public:
	MainWindow(Point xy, int w, int h, const string& title);
	void setParameterOptionsAndSort();
	~MainWindow();
};


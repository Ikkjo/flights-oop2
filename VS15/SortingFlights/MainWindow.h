#pragma once

#define WINDOW_W			800
#define WINDOW_H			800
#define HOR_OFFSET			20
#define VER_OFFSET			20
#define BUTTON_W			100
#define BUTTON_H			20

#include "Simple_window.h"
#include "Graph.h"
#include "Flight.h"

using namespace Graph_lib;

class MainWindow : public Window
{
private:
	Button sortButton;
	Button quitButton;

	In_box inputFileInBox;
	In_box outputFileInBox;
	In_box sortAlgInBox;
	In_box sortCriteriumInBox;

	static void cb_sort(Address, Address);
	static void cb_quit(Address, Address);

	bool sortPushed;
	bool quitPushed;

	void sort();
	void quit();


	
public:
	MainWindow(Point xy, int w, int h, const string& title);
	void getParameterOptions(string* in_f, string* out_f, FlightDataMember* crit, bool* merge_sort);
	~MainWindow();
};


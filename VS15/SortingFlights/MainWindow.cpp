//============================================================================
// Name        : MainWindow.cpp
// Author      : Ilija Kalinic SW65/2019
// Description : All graphical elements and display processes for MainWindow
//============================================================================


#include "MainWindow.h"


MainWindow::MainWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),

	loadButton(
		Point(x_max() - 2 * BUTTON_W - 5, 0),
		BUTTON_W,
		BUTTON_H,
		"LOAD",
		cb_load
	),

	quitButton(
		Point(x_max() - BUTTON_W, 0),
		BUTTON_W,
		BUTTON_H,
		"QUIT",
		cb_quit
	),

	nextButton(
		Point(20 * HOR_OFFSET, 100 * SPACE),
		BUTTON_W,
		BUTTON_H,
		"NEXT",
		cb_next
	),

	inputFileInBox(
		Point(9 * HOR_OFFSET, VER_OFFSET + 4 * SPACE),
		INBOX_W,
		INBOX_H,
		"Input file path: "
	),

	outputFileInBox(
		Point(9 * HOR_OFFSET, VER_OFFSET + 8 * SPACE),
		INBOX_W,
		INBOX_H,
		"Output file path: "
	),

	sortAlgInBox(
		Point(9 * HOR_OFFSET, VER_OFFSET + 12 * SPACE),
		INBOX_W,
		INBOX_H,
		"Sort algorithm selection: "
	),

	sortCriteriumInBox(
		Point(9 * HOR_OFFSET, VER_OFFSET + 16 * SPACE),
		INBOX_W,
		INBOX_H,
		"Sort criterium selection: "
	),

	vecPosition0(
		Point(20 * HOR_OFFSET, VER_OFFSET + 4 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H, 
		"1"),

	vecPosition1(
		Point(20 * HOR_OFFSET, VER_OFFSET + 8 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"2"),

	vecPosition2(
		Point(20 * HOR_OFFSET, VER_OFFSET + 12 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"3"),

	vecPosition3(
		Point(20 * HOR_OFFSET, VER_OFFSET + 16 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"4"),

	vecPosition4(
		Point(20 * HOR_OFFSET, VER_OFFSET + 20 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"5"),

	vecPosition5(
		Point(20 * HOR_OFFSET, VER_OFFSET + 24 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"6"),

	vecPosition6(
		Point(20 * HOR_OFFSET, VER_OFFSET + 28 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"7"),

	vecPosition7(
		Point(20 * HOR_OFFSET, VER_OFFSET + 32 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"8"),

	vecPosition8(
		Point(20 * HOR_OFFSET, VER_OFFSET + 36 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"9"),

	vecPosition9(
		Point(20 * HOR_OFFSET, VER_OFFSET + 40 * SPACE + 100),
		OUTBOX_W,
		OUTBOX_H,
		"10"),

	iterationText(
		Point(9 * HOR_OFFSET, VER_OFFSET + 32 * SPACE),
		"Iteration: "

	),

	numOfCmpsText(
		Point(9 * HOR_OFFSET, VER_OFFSET + 36 * SPACE),
		"Comparisons: "
	),

	numOfSwapsText(
		Point(9 * HOR_OFFSET, VER_OFFSET + 40 * SPACE),
		"Swaps: ")

{
	current_iter = 0;

	loadPushed = false;
	quitPushed = false;
	nextPushed = false;
	sort_data = SortingData();

	this->attach(loadButton);
	this->attach(quitButton);
	this->attach(nextButton);

	iterationText.set_color(Color::black);
	numOfCmpsText.set_color(Color::black);
	numOfSwapsText.set_color(Color::black);

	this->attach(iterationText);
	this->attach(numOfCmpsText);
	this->attach(numOfSwapsText);

	this->attach(inputFileInBox);
	this->attach(outputFileInBox);
	this->attach(sortAlgInBox);
	this->attach(sortCriteriumInBox);

	this->attach(vecPosition0);
	this->attach(vecPosition1);
	this->attach(vecPosition2);
	this->attach(vecPosition3);
	this->attach(vecPosition4);
	this->attach(vecPosition5);
	this->attach(vecPosition6);
	this->attach(vecPosition7);
	this->attach(vecPosition8);
	this->attach(vecPosition9);

	nextButton.hide();

}

MainWindow::~MainWindow(){}

void MainWindow::cb_load(Address, Address pw)
{
	reference_to<MainWindow>(pw).load();
}


void MainWindow::cb_quit(Address, Address pw)
{
	reference_to<MainWindow>(pw).quit();
}

void MainWindow::cb_next(Address, Address pw)
{
	reference_to<MainWindow>(pw).next();
}


void MainWindow::load()
{
	loadPushed = true;
	input_file = "..\\Resources\\"  + inputFileInBox.get_string();
	output_file = "..\\Resources\\" + outputFileInBox.get_string();

	int sort = sortAlgInBox.get_int();
	switch (sort) {
	case 1:
		merge_sort = false;
		break;

	case 2:
		merge_sort = true;
		break;
	}
	
	int criterium = sortCriteriumInBox.get_int();
	switch (criterium) {
	case 1:
		sort_crit = FlightDataMember::dep;
		break;

	case 2:
		sort_crit = FlightDataMember::dest;
		break;

	case 3:
		sort_crit = FlightDataMember::flNo;
		break;
	default:
		sort_crit = FlightDataMember::flNo;
		break;
	}
	string out_file_header = "";
	vector<Flight> init_flights = initializeFlights(input_file, &out_file_header);
	
	if (merge_sort) {
		MergeSort sort = MergeSort();
		sort.sort(init_flights, sort_crit);
		sort_data = SortingData(sort.getNumCmps(),
								sort.getNumSwaps(),
								sort.getAllFlights(),
								sort.getIter());
	}
	else {
		SelectionSort sort = SelectionSort();
		sort.sort(init_flights, sort_crit);
		sort_data = SortingData(sort.getNumCmps(),
			sort.getNumSwaps(),
			sort.getAllFlights(),
			sort.getIter());
	}

	saveSortedFlights(output_file, init_flights, out_file_header);

	nextButton.show();

}

void MainWindow::next() {
	if (current_iter < sort_data.getIter()) {

		updateOutBoxes(sort_data.getAllFlights()[current_iter]);
		string curr_swaps = to_string(sort_data.getNumSwaps()[current_iter]);
		string curr_cmps = to_string(sort_data.getNumCmps()[current_iter]);
		string curr_it_str = to_string(current_iter);

		updateIterationText(curr_it_str);
		updateNumOfCmpsText(curr_cmps);
		updateNumOfSwapsText(curr_swaps);
		redraw();

		current_iter++;
	}
	
	return;
}


void MainWindow::quit()
{
	quitPushed = true;
	this->hide();
}

void MainWindow::setParameterOptionsAndSort() {
	this->show();

	while (true) {
		loadPushed = false;
		quitPushed = false;

		while (!loadPushed && !quitPushed) Fl::wait();

		if (quitPushed) {
			break;
		}
		
	}
}

std::vector<Flight> MainWindow::initializeFlights(std::string in_f, std::string* header) {
	vector<Flight> flights = FileHandler::readInputFile(in_f, header, ';');
	return flights;
}

void MainWindow::saveSortedFlights(string out_f, std::vector<Flight> sorted_fls, string header) {
	FileHandler::writeOutputFile(&sorted_fls, out_f, header, ';');
}


void MainWindow::updateOutBoxes(vector<Flight> flights) {

	vector<string> flights_str = vector<string>();

	string current_flight_str;
	string delim = " | ";

	for (int i = 0; i < 10; i++) {

		if (i < flights.size()) {
			Flight fl = flights[i];
			current_flight_str = fl.getDestination() + delim + fl.getDeparture() + delim + fl.getFlightNo() + delim + fl.getGateNo();
		}
		else {
			current_flight_str = "";
		}
		

		flights_str.push_back(current_flight_str);
	}

	vecPosition0.put(flights_str[0]);
	vecPosition1.put(flights_str[1]);
	vecPosition2.put(flights_str[2]);
	vecPosition3.put(flights_str[3]);
	vecPosition4.put(flights_str[4]);
	vecPosition5.put(flights_str[5]);
	vecPosition6.put(flights_str[6]);
	vecPosition7.put(flights_str[7]);
	vecPosition8.put(flights_str[8]);
	vecPosition9.put(flights_str[9]);

}

void MainWindow::updateIterationText(string num) {
	string new_label = "Iteration: " + num;
	iterationText.set_label(new_label);
	
}

void MainWindow::updateNumOfCmpsText(string num) {
	string new_label = "Comparisons: " + num;
	numOfCmpsText.set_label(new_label);
}

void MainWindow::updateNumOfSwapsText(string num) {
	string new_label = "Swaps: " + num;
	numOfSwapsText.set_label(new_label);
}
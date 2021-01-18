#include "MainWindow.h"



MainWindow::MainWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),

	loadButton(
		Point(x_max() - 2*BUTTON_W - 5, 0),
		BUTTON_W,
		BUTTON_H,
		"LOAD",
		cb_load),

	quitButton(
		Point(x_max() - BUTTON_W, 0),
		BUTTON_W,
		BUTTON_H,
		"QUIT",
		cb_quit),

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
		"10")

{

	loadPushed = false;
	quitPushed = false;

	this->attach(loadButton);
	this->attach(quitButton);

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


void MainWindow::load()
{
	loadPushed = true;
	input_file = inputFileInBox.get_string();
	output_file = outputFileInBox.get_string();

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
	}

	showInitialFlights(&input_file);


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

		
		if (loadPushed) {
			load();
		}

		if (quitPushed) {
			quit();
			break;
		}
		
	}
}


void MainWindow::showInitialFlights(string* in_f) {
	string header = "";
	vector<Flight> flights = FileHandler::readInputFile(*in_f, &header, ';');
	updateOutBoxes(flights);

}


void MainWindow::updateOutBoxes(vector<Flight> flights) {

	vector<string> flights_str = vector<string>(flights.size());

	string current_flight_str;
	string delim = " | ";

	for (Flight fl : flights) {
		current_flight_str = fl.getDestination() + delim + fl.getDeparture() + delim + fl.getFlightNo() + delim + fl.getGateNo();

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
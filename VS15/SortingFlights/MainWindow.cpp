#include "MainWindow.h"



MainWindow::MainWindow(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),

	sortButton(
		Point(x_max() - 2*BUTTON_W - 5, 0),
		BUTTON_W,
		BUTTON_H,
		"SORT",
		cb_sort),

	quitButton(
		Point(x_max() - BUTTON_W, 0),
		BUTTON_W,
		BUTTON_H,
		"QUIT",
		cb_quit)

	

{
	sortPushed = false;
	quitPushed = false;

	this->attach(sortButton);
	this->attach(quitButton);
}

MainWindow::~MainWindow(){}

void MainWindow::cb_sort(Address, Address pw)
{
	reference_to<MainWindow>(pw).sort();
}


void MainWindow::cb_quit(Address, Address pw)
{
	reference_to<MainWindow>(pw).quit();
}


void MainWindow::sort()
{
	sortPushed = true;
}


void MainWindow::quit()
{
	quitPushed = true;
}

void MainWindow::getParameterOptions(string* in_f, string* out_f, FlightDataMember* crit, bool* merge_sort) {
	this->show();

	while (true) {
		sortPushed = false;
		quitPushed = false;

		while (!sortPushed && !quitPushed) Fl::wait();

		/*
		if (sortPushed) {

		}
		*/
	}
}


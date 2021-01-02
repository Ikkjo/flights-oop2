//============================================================================
// Name        : main.cpp
// Author      :
// Date        :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "Flight.h"


void main()
{	
	Flight fl1, fl3;
	Flight* fl2;
	try {
		fl1 = Flight("AA23", "LAS VEGAS", "21:15", "A3");
	}
	catch (exception e) {
		cout << "An error has occured!" << endl;
		fl1 = Flight("AA023", "LAS VEGAS", "21:15", "A3");
	}
	
	fl2 = new Flight("BA036", "DALLAS", "21:00", "A3");

	fl3 = fl1;

	fl1 = *fl2;
	string fl2flno = fl2->getFlightNo();
	bool cond = fl1.getFlightNo() == fl2flno;
	cout << fl3.getFlightNo() << endl;
	cout << cond <<endl;

	delete fl2;
}

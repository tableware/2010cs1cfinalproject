#include "header.h"
#include <limits>
#include <ios>

driver::driver() : active(true)
{

}

driver::~driver()
{

}

void driver::main()
{
	vector<Winery> wineryList;
	int option = 0;

	// main run loop for the driver
	do
	{
		// display the menu
		this->menu();

		// input check loop
		do
		{
			cout << "Please make a selection: ";
			if(!(cin >> option))
			{
				cout << "Invalid input.";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while(option < 1 || option > 5);

		cout << "\n\n";

		// execute the option
		switch(option)
		{
			case 1:
				this->listWineries();
			break;

			case 2:
				this->planDayTrip();
			break;

			case 3:
				this->tourWineriesAndPurchaseWines();
			break;

			case 4:
				this->performFileMaintenace();
			break;

			case 5:
				this->quit();
			break;
		}

		cout << "\n\n";

	} while(this->active);
}

void driver::menu()
{
	cout << "1. View our list of wineries\n"
		 << "2. Plan a day trip\n"
		 << "3. Tour your wineries and purchase wines\n"
		 << "4. Perform file maintenance (administrator only)\n"
		 << "5. Quit\n\n";
}

void driver::listWineries()
{
	cout << "driver::listWineries()\n";
}

void driver::planDayTrip()
{
	cout << "driver::planDayTrip()\n";
}

void driver::tourWineriesAndPurchaseWines()
{
	cout << "driver::tourWineriesAndPurchaseWines()\n";
}

void driver::performFileMaintenace()
{
	cout << "driver::performFileMaintenace()\n";
}

void driver::quit()
{
	// set our state to inactive
	this->active = false;
}

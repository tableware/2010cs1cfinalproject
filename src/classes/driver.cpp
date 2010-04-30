#include "../header.h"

int Winery::numOfWineries = 0;

driver::driver() : active(true)
{

}

driver::~driver()
{

}

void driver::main()
{
	// --   TESTING CODE  -- //
	// This code is meant to demonstrate how to populate our wineries
//	Winery* temp;
//	WineryDistance* dTemp;
//	Wine* wTemp;
//
//
//	temp = new Winery(1, "Winery Number One");
//	dTemp = new WineryDistance(1,2.34);
//	temp->distanceList.push_back(dTemp);
//	dTemp = new WineryDistance(2,3.45);
//	wTemp = new Wine("Somewine", .99, 1999, 3);
//	temp->setNumOfWines(1);
//	temp->distanceList.push_back(dTemp);
//	temp->wineList.push_back(wTemp);
//	this->wineries.push_back(temp);
//	Winery::numOfWineries++;
//
//	// we can reassign temp since we now assume the vector owns the memory
//	temp = new Winery();
//	temp->setNumber(2);
//	temp->setName("Winery Number Two");
//	dTemp = new WineryDistance(1,2.34);
//	temp->distanceList.push_back(dTemp);
//	dTemp = new WineryDistance(2,3.45);
//	wTemp = new Wine("Otherwine", 9.99, 2100, 1);
//	temp->setNumOfWines(1);
//	temp->wineList.push_back(wTemp);
//	temp->distanceList.push_back(dTemp);
//	this->wineries.push_back(temp);
//	Winery::numOfWineries++;
//
//	createBinaryFile(this->wineries);
//	this->wineries =(readBinaryFile());
//
//	this->listWineries();

	// -- END TESTING CODE --//
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

	for (unsigned int i = 0; i < this->wineries.size(); ++i)
	{
		cout << "------\n"
			 << "Number: " << this->wineries[i]->getNumber() << endl
			 << "Name:   " << this->wineries[i]->getName() << endl;

		cout << "\n+- Wines\n";
		for (unsigned int j = 0; j < this->wineries[i]->wineList.size(); ++j)
		{
			cout << "  ---\n"
				 << "  Name:  " << this->wineries[i]->wineList[j]->getName() << endl
				 << "  Year:  " << this->wineries[i]->wineList[j]->getYear() << endl
				 << "  Price: " << this->wineries[i]->wineList[j]->getPrice() << endl;
		}

		cout << "\n+- WineryDistances\n";
		for (unsigned int j = 0; j < this->wineries[i]->distanceList.size(); ++j)
		{
			cout << "  ---\n"
				 << "  Number:   " << this->wineries[i]->distanceList[j]->getNumber() << endl
				 << "  Distance: " << this->wineries[i]->distanceList[j]->getDistance() << endl;
		}

		// throw in a couple of new lines if we aren't expecting the menu to be next
		if(i < this->wineries.size() - 1)
		{
			cout << "\n\n";
		}
	}

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

	adminDriver *admin = new adminDriver(this->wineries);
	admin->main();
	delete admin;
}

void driver::quit()
{
	// set our state to inactive
	this->active = false;
}

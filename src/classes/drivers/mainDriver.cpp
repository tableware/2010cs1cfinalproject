#include "mainDriver.h"

int Winery::numOfWineries = 0;

mainDriver::mainDriver() : active(true)
{

}

mainDriver::~mainDriver()
{

}

void mainDriver::main()
{
	// --   TESTING CODE  -- //
	// This code is meant to demonstrate how to populate our wineries
	Winery* temp;
	WineryDistance* dTemp;
	Wine* wTemp;


	temp = new Winery(1, "Winery Number One");
	dTemp = new WineryDistance(1,2.34);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,3.45);
	wTemp = new Wine("Somewine", .99, 1999, 3);
	temp->setNumOfWines(1);
	temp->distanceList.push_back(dTemp);
	temp->wineList.push_back(wTemp);
	this->wineries.push_back(temp);
	Winery::numOfWineries++;

	// we can reassign temp since we now assume the vector owns the memory
	temp = new Winery();
	temp->setNumber(2);
	temp->setName("Winery Number Two");
	dTemp = new WineryDistance(1,2.34);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,3.45);
	wTemp = new Wine("Otherwine", 9.99, 2100, 1);
	temp->setNumOfWines(1);
	temp->wineList.push_back(wTemp);
	temp->distanceList.push_back(dTemp);
	this->wineries.push_back(temp);
	Winery::numOfWineries++;

	createBinaryFile(this->wineries);
	this->wineries =(readBinaryFile());

	this->listWineries();

	cout << endl;
	outputWineryTable(this->wineries);
	cout << endl;

	cout << endl;
	this->wineries[0]->outputWineTable();
	cout << endl;

//	unsigned int finder = FindName(this->wineries[0]->wineList, "Somewine");
//	if (finder == this->wineries[0]->wineList.size())
//	{
//		cout << "\noutta bounds fool!\n";
//	}
//	else
//	{
//		cout << endl << "wine: " << this->wineries[0]->wineList[finder]->getName() << endl;
//	}
//
//	cout << endl << "Place in vector: " << finder << endl;
	Winery* temp;
	WineryDistance* dTemp;
	Wine* wTemp;


	temp = new Winery(1, "Winery Number One");
	dTemp = new WineryDistance(1,2.34);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,3.45);
	wTemp = new Wine("Somewine", .99, 1999, 3);
	temp->setNumOfWines(1);
	temp->distanceList.push_back(dTemp);
	temp->wineList.push_back(wTemp);
	this->wineries.push_back(temp);
	Winery::numOfWineries++;

	// we can reassign temp since we now assume the vector owns the memory
	temp = new Winery();
	temp->setNumber(2);
	temp->setName("Winery Number Two");
	dTemp = new WineryDistance(1,2.34);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,3.45);
	wTemp = new Wine("Otherwine", 9.99, 2100, 1);
	temp->setNumOfWines(1);
	temp->wineList.push_back(wTemp);
	temp->distanceList.push_back(dTemp);
	this->wineries.push_back(temp);
	Winery::numOfWineries++;

	createBinaryFile(this->wineries);
	this->wineries =(readBinaryFile());

	this->listWineries();

	unsigned int finder = FindName(this->wineries[0]->wineList, "Somewine");
	if (finder == this->wineries[0]->wineList.size())
	{
		cout << "\noutta bounds fool!\n";
	}
	else
	{
		cout << endl << "wine: " << this->wineries[0]->wineList[finder]->getName() << endl;
	}

	cout << endl << "Place in vector: " << finder << endl;

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

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

void mainDriver::menu()
{
	cout << "1. View our list of wineries\n"
		 << "2. Plan a day trip\n"
		 << "3. Tour your wineries and purchase wines\n"
		 << "4. Perform file maintenance (administrator only)\n"
		 << "5. Quit\n\n";
}

void mainDriver::listWineries()
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

void mainDriver::planDayTrip()
{
	cout << "driver::planDayTrip()\n";
}

void mainDriver::tourWineriesAndPurchaseWines()
{
	cout << "driver::tourWineriesAndPurchaseWines()\n";
}

void mainDriver::performFileMaintenace()
{
	cout << "driver::performFileMaintenace()\n";

	adminDriver::getInstance().main(this->wineries);
//	adminDriver *admin = new adminDriver(this->wineries);
//	admin->main();
//	delete admin;
}

void mainDriver::quit()
{
	// set our state to inactive
	this->active = false;
}

mainDriver& mainDriver::getInstance()
{
	static mainDriver instance;
	return instance;
}

/*
 * adminDriver.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: darkstar1103
 */
#include "adminDriver.h"

adminDriver::adminDriver(vector<Winery*>& wineries)
{
	this->wineries = &wineries;
	this->active = true;
}

adminDriver::~adminDriver()
{

}

void adminDriver::menu()
{
	cout << "1. Quit\n"
		 << "2. Load initial data\n\n";
}

void adminDriver::main()
{
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
		} while(option < 1 || option > 2);

		cout << "\n\n";

		// execute the option
		switch(option)
		{
			case 1:
				this->quit();
			break;

			case 2:
				this->loadInitialData();
			break;
		}

		cout << "\n\n";

	} while(this->active);
}

void adminDriver::quit()
{

	// set our state to inactive
	this->active = false;
}

void adminDriver::loadInitialData()
{
	cout << "adminDriver::loadInitialData()\n";

	// sample load
		Winery* tempWinery;
		WineryDistance* tempDistance;
		Wine* tempWine;

		string temp;
		string temp2;
		int tempInt;
		float tempFloat;
		ifstream stream;
		stream.open("src/data/wineries.txt");

		while(stream)
		{
			tempWinery = new Winery;

			// grab the name
			getline(stream, temp);
			tempWinery->setName(temp);

			// grab the number of the Winery
			getline(stream, temp);
			tempWinery->setNumber(atoi(temp.c_str()));

			// grab the number of the number of distances
			getline(stream, temp);

			// loop to grab all of the distances
			for(int i = 0; i < atoi(temp.c_str()); ++i)
			{
				stream >> tempInt;
				stream >> tempFloat;
				stream.ignore(numeric_limits<streamsize>::max(), '\n');

				tempDistance = new WineryDistance(tempInt, tempFloat);

				tempWinery->distanceList.push_back(tempDistance);
			}

			// this is a random float that I have no idea what it's for, I think it may be the distance of the
			//   winery that we are reading from the main winery that we are supposed to be at...
			getline(stream, temp);

			// grab the number of wines
			getline(stream, temp);

			for(int i = 0; i < atoi(temp.c_str()); ++i)
			{
				getline(stream, temp2);
				stream >> tempInt;
				stream >> tempFloat;
				stream.ignore(numeric_limits<streamsize>::max(), '\n');

				tempWine = new Wine;
				tempWine->setName(temp2);
				tempWine->setYear(tempInt);
				tempWine->setPrice(tempFloat);

				tempWinery->wineList.push_back(tempWine);
			}

			this->wineries->push_back(tempWinery);

		}

		stream.close();
}

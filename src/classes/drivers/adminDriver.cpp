/*
 * adminDriver.cpp
 *
 *  Created on: Apr 29, 2010
 *      Author: darkstar1103
 */
#include "adminDriver.h"

adminDriver::adminDriver() :
	wineries(NULL),
	password("silly llamas")
{
	this->_registerMenuItem("Load inital data", &adminDriver::loadInitialData);
	this->_registerMenuItem("Add new winery", &adminDriver::addWinery);
	this->_registerMenuItem("Change price of wine", &adminDriver::changePriceOfWine);
	this->_registerMenuItem("Add new wine to winery", &adminDriver::addWineToWinery);
}

adminDriver::~adminDriver()
{

}

void adminDriver::main(vector<Winery*>& wineries)
{
	this->wineries = &wineries;

	// validate password
	string pass;
	cout << "Password: ";
	getline(cin, pass);

	if(pass == this->password)
	{
		driver<adminDriver>::main();
	}
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

void adminDriver::addWinery()
{
	cout << "adminDriver::addWinery()\n";

	Winery* tempWinery = new Winery();
	WineryDistance* tempDistance;
	Wine* tempWine;

	string temp;
	string temp2;


	// grab the name
	cout << "Winery name: ";
	getline(cin, temp);
	tempWinery->setName(temp);

	// our winery number should be the current number of wineries + 1
	tempWinery->setNumber(this->wineries->size() + 1);

	// get the number of wines
	cout << "Number of wines: ";
	getline(cin, temp);

	// get all of the wines from the administrator
	for(int i = 0; i < atoi(temp.c_str()); ++i)
	{
		tempWine = new Wine();

		cout << "Name of Wine: ";
		getline(cin, temp2);
		tempWine->setName(temp2);

		cout << "Quantity of Wine: ";
		getline(cin, temp2);
		tempWine->setQuantity(atoi(temp2.c_str()));

		cout << "Price of Wine: ";
		getline(cin, temp2);
		tempWine->setPrice(atof(temp2.c_str()));

		cout << "Year of Wine: ";
		getline(cin, temp2);
		tempWine->setYear(atoi(temp2.c_str()));

		tempWinery->wineList.push_back(tempWine);
	}

	// loop through all of the current wineries and get the distances to the,
	for(unsigned int i = 0; i < this->wineries->size(); ++i)
	{
		// get the distance for the current winery
		cout << "Distance from " << (*this->wineries)[i]->getName() << ": ";
		getline(cin, temp);

		// create the distance and add it to the winery
		tempDistance = new WineryDistance((*this->wineries)[i]->getNumber(), atof(temp.c_str()));
		tempWinery->distanceList.push_back(tempDistance);

		// update the old winery to link the distance to the new winery
		tempDistance = new WineryDistance(tempWinery->getNumber(), atof(temp.c_str()));
		(*this->wineries)[i]->distanceList.push_back(tempDistance);

	}

	// add a distance to ourself
	tempWinery->distanceList.push_back(new WineryDistance(tempWinery->getNumber(), 0.0));

	// add the winery to the list
	this->wineries->push_back(tempWinery);
}

void adminDriver::addWineToWinery()
{
	cout << "adminDriver::addWinesToWinery()\n";
}

void adminDriver::changePriceOfWine()
{
	cout << "adminDriver::changePriceOfWine()\n";
}

adminDriver& adminDriver::getInstance()
{
	static adminDriver instance;
	return instance;
}

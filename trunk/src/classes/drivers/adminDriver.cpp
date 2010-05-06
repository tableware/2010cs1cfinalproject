/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "adminDriver.h"

adminDriver::adminDriver() :
	wineries(NULL),
	password("silly llamas")
{
	// register all of the appropriate actions with driver
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

	// check to see if we have the right password
	if(pass == this->password)
	{
		// password was good, enter the main run loop for the application
		driver<adminDriver>::main();
	}
}

void adminDriver::loadInitialData()
{
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
		tempWinery->setDistance(atof(temp.c_str()));

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
		tempWinery->setDistance(atof(temp.c_str()));

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

	// get the distance from the our location
	cout << "Distance for Canyon Villa: ";
	getline(cin, temp);
	tempWinery->setDistance(atof(temp.c_str()));

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
	string temp;
	unsigned int option;

	option = this->_selectWinery();

	// make sure we didn't get an exit command
	if(option < this->wineries->size())
	{
		Wine* tempWine = new Wine();

		cout << "Name of Wine: ";
		getline(cin, temp);
		tempWine->setName(temp);

		cout << "Price of Wine: ";
		getline(cin, temp);
		tempWine->setPrice(atof(temp.c_str()));

		cout << "Year of Wine: ";
		getline(cin, temp);
		tempWine->setYear(atoi(temp.c_str()));

		(*this->wineries)[option]->wineList.push_back(tempWine);
	}
}

void adminDriver::changePriceOfWine()
{

	string temp;
	unsigned int winery;
	unsigned int wine;

	winery = this->_selectWinery();

	if(winery < this->wineries->size())
	{
		// loop and output the menu
		for (unsigned int i = 0; i < (*this->wineries)[winery]->wineList.size(); ++i)
		{
			cout << i + 1 << ". " << (*this->wineries)[winery]->wineList[i]->getName() << "\n";
		}

		// add the quit option to the menu
		cout << (*this->wineries)[winery]->wineList.size() + 1 << ". Cancel\n\n";

		// input check loop
		do
		{
			cout << "Please make a selection: ";
			if(!(cin >> wine))
			{
				cout << "Invalid input.";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while(wine < 1 || wine > (*this->wineries)[winery]->wineList.size() + 1);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		--wine;

		if(wine < (*this->wineries)[winery]->wineList.size())
		{
			cout << "Old price of wine: " << (*this->wineries)[winery]->wineList[wine]->getPrice() << endl;
			cout << "New price of wine: ";
			getline(cin, temp);
			(*this->wineries)[winery]->wineList[wine]->setPrice(atof(temp.c_str()));

		}
	}

}

unsigned int adminDriver::_selectWinery()
{
	unsigned int option;

	// loop and output the menu
	for (unsigned int i = 0; i < this->wineries->size(); ++i)
	{
		cout << i + 1 << ". " << (*this->wineries)[i]->getName() << "\n";
	}

	// add the quit option to the menu
	cout << this->wineries->size() + 1 << ". Cancel\n\n";

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
	} while(option < 1 || option > this->wineries->size() + 1);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return option - 1;
}

adminDriver& adminDriver::getInstance()
{
	static adminDriver instance;

	return instance;
}

void adminDriver::printHeader()
{
	cout << endl;

	cout << ' ' << setfill('*')<< setw(95) << ' ' << endl;

	cout << '*' << setfill(' ') << right <<  setw(60)  << "Welcome to Canyon Villa";
	cout << setfill(' ') << setw(35) << '*' << endl;

	cout << '*' << setfill(' ') << right <<  setw(56)  << "Paso Robles, CA";
	cout << setfill(' ') << setw(39) << '*' << endl;

	cout << '*' << setfill(' ')  << right <<  setw(69) << "Computer Science 1C: Advanced Programming";
	cout << setfill(' ') << setw(26) << '*' << endl;

	cout << '*' << setfill(' ')<< right <<  setw(59)  << "Version 1.00 5/4/2010";
	cout << setfill(' ') << setw(36) << '*' << endl;

	cout << '*' << setfill(' ')<< right << setw(58) << "Administrator Menu"
		 << setfill(' ') << setw(37) << '*' << endl;

	cout << ' ' << setfill('*')<< setw(95) << ' ' << setfill(' ') << endl;

	cout << "\n\n";
}

#include "../header.h"

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
//
//	temp = new Winery(1, "Winery Number One");
//	this->wineries.push_back(temp);
//
//	// we can reassign temp since we now assume the vector owns the memory
//	temp = new Winery();
//	temp->setNumber(2);
//	temp->setName("Winery Number Two");
//	this->wineries.push_back(temp);

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

		this->wineries.push_back(tempWinery);

	}

	stream.close();
}

void driver::quit()
{
	// set our state to inactive
	this->active = false;
}

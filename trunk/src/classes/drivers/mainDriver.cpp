#include "mainDriver.h"


mainDriver::mainDriver()
{
	this->_registerMenuItem("View our list of wineries", &mainDriver::listWineries);
	this->_registerMenuItem("Plan a day trip", &mainDriver::planDayTrip);
	this->_registerMenuItem("Tour your wineries and purchase wines", &mainDriver::tourWineriesAndPurchaseWines);
	this->_registerMenuItem("Perform file maintenance (administrator only)", &mainDriver::performFileMaintenace);

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
	trip* tour;

	temp = new Winery(1, "Winery Number One");
	dTemp = new WineryDistance(1,3.45);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,1);
	wTemp = new Wine("Somewine", .99, 1999, 3);
	temp->distanceList.push_back(dTemp);
	temp->wineList.push_back(wTemp);
	wTemp = new Wine("Goodone", 5.99, 1988, 2);
	temp->wineList.push_back(wTemp);
	this->wineries.push_back(temp);

	// we can reassign temp since we now assume the vector owns the memory
	temp = new Winery();
	temp->setNumber(2);
	temp->setName("Winery Number Two");
	dTemp = new WineryDistance(1,5);
	temp->distanceList.push_back(dTemp);
	dTemp = new WineryDistance(2,3.45);
	wTemp = new Wine("Otherwine", 9.99, 2100, 1);
	//temp->setNumOfWines(1);
	temp->wineList.push_back(wTemp);
	temp->distanceList.push_back(dTemp);
	this->wineries.push_back(temp);

	tour = new trip;
	//this->listWineries();

	//makes the tour trip winery vector point to the main's winery vector
	//tour->wineries = this->wineries;

	//You will have to select what winery to put in here
	// If you want to do a new winery, you will have to pop the winePurchase vector

//	int x = tour->makeNumberTripSelect();
//	cout << "exited make number select" << endl;
//	tour->setNumberVisitList(x);
	//cout << "Distance Traveled: " << tour->getDistanceTraveled() << endl;

	cout << "size: " << this->wineries.size() << endl;

	tour->touring(this->wineries);

//	tour->setWinesPurchases(this->wineries, 0);
////
//	tour->winePurchases(0);
//
//	cout << endl;
//	tour->outputTableWineCheckout(0);
//	cout << endl;
//
//	tour->clearPurchases();
//	tour->setWinesPurchases(this->wineries, 1);
//
//	cout << endl;
//	tour->outputTableWineCheckout(1);
//	cout << endl;

	//tour->setVisitList();
/*
	int tempHolder = 0;
	tempHolder = tour->findShortestDist(0);
	while (tempHolder >= 0)
	{
		tour->wineries[tempHolder]->setVisited(true);
		cout << "Visiting " << tour->wineries[tempHolder]->getName() << endl;
		tempHolder = tour->findShortestDist(tempHolder);
	}
	cout << endl;

	//resetting
	tour->resetVisited();
	tour->setVisitList();
	tour->setDistanceTraveled(0.0);
	tempHolder = tour->findShortestDist(0);
	cout << tour->getDistanceTraveled() << endl;

	while (tempHolder >= 0)
	{
		tour->wineries[tempHolder]->setVisited(true);
		cout << "Visiting " << tour->wineries[tempHolder]->getName() << endl;
		tempHolder = tour->findShortestDist(tempHolder);
		cout << tour->getDistanceTraveled() << endl;
	}
	cout << endl;*/

//	createBinaryFile(this->wineries);
//	this->wineries =(readBinaryFile());

//	this->listWineries();
//

//  //dont think we'll need this function cause I eliminated it with checkout
//	cout << endl;
//	this->wineries[0]->outputWineTable();
//	cout << endl;

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

	// -- END TESTING CODE --//

	driver<mainDriver>::main();
}

void mainDriver::listWineries()
{
	cout << "driver::listWineries()\n";

	cout << "Wineres size is: " << this->wineries.size() << endl;
	if(this->wineries.size() != 0){
		for (unsigned int i = 0; i < this->wineries.size()-1; i+=2)
		{

			cout << setfill('-')<< setw(96) << '-' << endl;

			cout << ' ' << setfill(' ') << left <<  setw(50) << this->wineries[i]->getName()
				 << "| " << setfill(' ') << left  << setw(46) << this->wineries[i+1]->getName()
				 << endl;

			cout << ' ' << setfill(' ') << left <<  setw(49) << "Wine List: "
				 << setfill(' ') << left <<  setw(48)<< " | Wine List: "
				 << endl;


			for (unsigned int j = 0; j < 10; j++)
				{
				string outputWinery1;
				bool output1;
				output1 = false;
				string outputWinery2;
				bool output2;
				output2 = false;

				if(j < this->wineries[i]->wineList.size())
					{
					outputWinery1 = wineries[i]->wineList[j]->getName();
					output1 = true;
					}
				else
					{
					outputWinery1 = "";
					}
				if(j < this->wineries[i+1]->wineList.size())
					{
					outputWinery2 = wineries[i+1]->wineList[j]->getName();
					output2 = true;
					}
				else
					{
					outputWinery2 = "";
					}




				if (output1 && output2)
					{
					cout << " " << j+1 << ". " << setfill(' ') << left <<  setw(46)  << outputWinery1
						 << " | " << j+1 << ". " << outputWinery2
						 << endl;

					cout << "   Price:" << left <<  setfill(' ') << setw(10) << wineries[i]->wineList[j]->getPrice();
					cout << " Year: " << left <<  setfill(' ') << setw(25)  << wineries[i]->wineList[j]->getYear();
					cout << "|   Price:" << left <<  setfill(' ') << setw(10) << wineries[i+1]->wineList[j]->getPrice();
					cout << " Year: " << left <<  setfill(' ') << setw(36)  << wineries[i+1]->wineList[j]->getYear();
					cout << endl;
					}
				else if(output1)
					{
					cout << " " << j+1 << ". " << setfill(' ') << left <<  setw(46)  << outputWinery1
						 << " | " << j+1 << ". " << outputWinery2
						 << endl;

					cout << "   Price:" << left <<  setfill(' ') << setw(10) << wineries[i]->wineList[j]->getPrice();
					cout << " Year: " << left <<  setfill(' ') << setw(25)  << wineries[i]->wineList[j]->getYear()
						 << "|";
					cout << endl;
					}
				else if(output2)
					{
					cout << " " << j+1 << ". " << setfill(' ') << left <<  setw(46)  << outputWinery1
						 << " | " << j+1 << ". " << outputWinery2
						 << endl;

					cout << left << setfill(' ') << setw(53) << " ";
					cout << "    Price:" << left <<  setfill(' ') << setw(10) << wineries[i+1]->wineList[j]->getPrice();
					cout << " Year: " << left <<  setfill(' ') << setw(25)  << wineries[i+1]->wineList[j]->getYear();
					cout << endl;
					}
			}

		}

		if(this->wineries.size()%2 == 1){
			cout << setfill('-')<< setw(96) << '-' << endl;

			cout << ' ' << setfill(' ') << left <<  setw(50) << this->wineries[this->wineries.size() - 1]->getName()
				 << "| " << setfill(' ') << left  << setw(50)
				 << endl;

			cout << " Wine List: " << setfill(' ') << left <<  setw(55) << '|'
				 << endl;

			for(unsigned int j = 0; j  < this->wineries[this->wineries.size() - 1]->wineList.size(); ++j)
				{
				cout << " " << j+1 << ". " << setfill(' ') << left <<  setw(46)  << this->wineries[this->wineries.size() - 1]->getName()
					 << " | "
					 << endl;

				cout << "   Price:" << left <<  setfill(' ') << setw(10) << wineries[this->wineries.size() - 1]->wineList[j]->getPrice();
				cout << " Year: " << left <<  setfill(' ') << setw(25)  << wineries[this->wineries.size() - 1]->wineList[j]->getYear()
					 << "|";
				cout << endl;
				}
}
	}


	/*****************************BEGIN OLD OUTPUT WINERIES*********************************

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
	}***************************** END OLD OUTPUT WINERIES**********************************/

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
}

mainDriver& mainDriver::getInstance()
{
	static mainDriver instance;
	return instance;
}



void mainDriver::printHeader(){
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

		cout << '*' << setfill(' ')<< right << setw(55) << "Main Menu"
			 << setfill(' ') << setw(40) << '*' << endl;

		cout << ' ' << setfill('*')<< setw(95) << ' ' << endl;

		cout << "\n\n";
}

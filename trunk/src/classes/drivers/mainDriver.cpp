/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "mainDriver.h"


mainDriver::mainDriver()
{
	// load up the menu
	this->_registerMenuItem("View our list of wineries", &mainDriver::listWineries);
	this->_registerMenuItem("Tour your wineries and purchase wines", &mainDriver::tourWineriesAndPurchaseWines);
	this->_registerMenuItem("Perform file maintenance (administrator only)", &mainDriver::performFileMaintenace);

}

mainDriver::~mainDriver()
{

}

void mainDriver::main()
{
	driver<mainDriver>::main();
}

void mainDriver::listWineries()
{
	if(this->wineries.size() != 0){
		for (unsigned int i = 0; i < this->wineries.size()-1; i+=2)
		{

			cout << setfill('-')<< setw(96) << '-' << endl;

			cout << ' ' << setfill(' ') << left <<  setw(50) << this->wineries[i]->getName()
				 << "| " << setfill(' ') << left  << setw(46) << this->wineries[i+1]->getName()
				 << endl;

			cout << ' ' << setfill(' ') << left << "Distance from Canyon Villa: "  << setw(22) << this->wineries[i]->getDistance()
				 << "| " << setfill(' ') << left << "Distance from Canyon Villa: "  << setw(28) << this->wineries[i+1]->getDistance()
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
}

void mainDriver::tourWineriesAndPurchaseWines()
{
	trip* tour = new trip;
	tour->touring(this->wineries);
	delete tour;
}

void mainDriver::performFileMaintenace()
{
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

		cout << ' ' << setfill('*')<< setw(95) << ' ' << setfill(' ') << endl;

		cout << "\n\n";
}

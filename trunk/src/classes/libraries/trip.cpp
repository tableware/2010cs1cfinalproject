/*
 * trip.cpp
 *
 *  Created on: May 3, 2010
 *      Author: jgibbins1
 */

#include "trip.h"

trip::trip() :
	subTotal(0),
	tax(0.0),
	distanceTraveled(0.0)
{ }

trip::~trip()
{

}

void trip::outputTableWineCheckout(int place)
{
	unsigned int count;
	int finder;

	count = 0;
	cout << right << setw(3) << "#" << left << setw(35) << " Name of wine"
		 << right << setw(10) << "Price" << setw(8) << "Year"
		 << setw(4) << "Qty" << endl;
	cout << setfill('-');
	cout << setw(60) << "-";
	cout << setfill(' ');
	cout << endl << fixed << setprecision(2);
	while (count < this->boozeList.size())
	{
		cout << right << setw(3) << count + 1 << left << " " << setw(34)
			 << this->boozeList[count]->wine->getName() << right;

		finder = FindName(this->wineries[place]->wineList,
						  this->boozeList[count]->wine->getName());

		cout << setw(10) << this->wineries[place]->wineList[finder]->getPrice()
			 << setw(8)
			 << this->wineries[place]->wineList[finder]->getYear()
			 << setw(4) << this->boozeList[count]->quantity << endl;
		count++;
	}
}

void trip::setWinesPurchases(vector<Winery*> mainList, unsigned int loc)
{
	unsigned int count;
	winePurchase* temp;

	count = 0;
	while (count < mainList[loc]->wineList.size())
	{
		temp = new winePurchase;
		temp->quantity = 0;
		temp->wine = mainList[loc]->wineList[count];
		this->boozeList.push_back(temp);
		count++;
	}
}

void trip::clearPurchases()
{
	unsigned int count;
	count = this->boozeList.size();

	while (count-- != 0)
	{
		this->boozeList.pop_back();
	}
}

void trip::outputWineryTable()
{
	unsigned int count;

	count = 0;
	cout << right << setw(3) << "#" << left << setw(35) << " Name of winery"
		 << right << setw(10) << "# of Wines" << endl;
	cout << setfill('-');
	cout << setw(48) << "-";
	cout << setfill(' ');
	cout << endl;
	while (count < this->wineries.size())
	{
		cout << right << setw(3) << this->wineries[count]->getNumber() << left
			 << " " << setw(34)
			 << this->wineries[count]->getName() << right << setw(10)
			 << this->wineries[count]->getNumOfWines() << endl;
		count++;
	}

}

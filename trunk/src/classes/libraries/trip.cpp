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
	distanceTraveled(0.0),
	total(0.0)
{ }

trip::~trip()
{

}

float trip::getDistanceTraveled()
{
	return distanceTraveled;
}

float trip::getSubTotal()
{
	return subTotal;
}

float trip::getTax()
{
	return tax;
}

float trip::getTotal()
{
	return total;
}

void trip::setDistanceTraveled(float distTraveled)
{
	distanceTraveled = distTraveled;
}

void trip::outputTableWineCheckout(int place)
{
	int finder;

	cout << right << setw(3) << "#" << left << setw(35) << " Name of wine"
		 << right << setw(10) << "Price" << setw(8) << "Year"
		 << setw(4) << "Qty" << endl;
	cout << setfill('-');
	cout << setw(60) << "-";
	cout << setfill(' ');
	cout << endl << fixed << setprecision(2);

	for(unsigned int count = 0; count < this->boozeList.size(); ++count)
	{
		cout << right << setw(3) << count + 1 << left << " " << setw(34)
			 << this->boozeList[count]->wine->getName() << right;

		finder = FindName(this->wineries[place]->wineList,
						  this->boozeList[count]->wine->getName());

		cout << setw(10) << this->wineries[place]->wineList[finder]->getPrice()
			 << setw(8)
			 << this->wineries[place]->wineList[finder]->getYear()
			 << setw(4) << this->boozeList[count]->quantity << endl;
	}
}

void trip::setWinesPurchases(vector<Winery*> mainList, unsigned int loc)
{
	winePurchase* temp;

	for(unsigned int count = 0; count < mainList[loc]->wineList.size(); ++count)
	{
		temp = new winePurchase;
		temp->quantity = 0;
		temp->wine = mainList[loc]->wineList[count];
		this->boozeList.push_back(temp);
	}
}

void trip::clearPurchases()
{
	for(unsigned int count = this->boozeList.size(); count > 0; --count)
	{
		this->boozeList.pop_back();
	}
}

void trip::outputWineryTable()
{
	cout << right << setw(3) << "#" << left << setw(35) << " Name of winery"
		 << right << setw(10) << "# of Wines" << endl;
	cout << setfill('-');
	cout << setw(48) << "-";
	cout << setfill(' ');
	cout << endl;

	for(unsigned int count = 0; count < this->wineries.size(); ++count)
	{
		if (this->wineries[count]->getVisited())
		{
			cout << right << setw(3) << this->wineries[count]->getNumber()
				 << left << " " << setw(34)
				 << this->wineries[count]->getName() << right << setw(10)
				 << this->wineries[count]->wineList.size() << endl;
		}

	}
}

void trip::resetVisited()
{
	for(unsigned int count = 0; count < this->wineries.size(); ++count)
	{
		this->wineries[count]->setVisited(true);
	}
}

void trip::makeAllUnvisited()
{
	for(unsigned int count = 0; count < this->wineries.size(); count++)
	{
		this->wineries[count]->setVisited(false);
	}
}

int trip::findShortestDist(int loc, bool firstInstance)
{
	float shortestDist;

	int positionHolder = -1;
	unsigned int position = 0;
	bool foundFirstInstance = false;
	while (position < this->wineries.size() && !foundFirstInstance)
	{
		if (!this->wineries[position]->getVisited())
		{
			positionHolder = position;
			foundFirstInstance = true;
			if (firstInstance)
			{
				shortestDist = this->wineries[position]->getDistance();
			}
			else
			{
				shortestDist = this->wineries[loc]->distanceList[position]->getDistance();
			}

		}
		position++;
	}
	while (position < this->wineries.size())
	{
		if (firstInstance)
		{
			if (shortestDist > this->wineries[position]->getDistance()
								&& !this->wineries[position]->getVisited())
			{
				positionHolder = position;
				shortestDist = this->wineries[position]->getDistance();
			}
		}
		else
		{
			if (shortestDist > this->wineries[loc]->distanceList[position]->getDistance()
				&& !this->wineries[position]->getVisited())
			{
				positionHolder = position;
				shortestDist = this->wineries[loc]->distanceList[position]->getDistance();
			}
		}

		position++;
	}

	if (positionHolder >= 0)
	{
		this->distanceTraveled += shortestDist;
	}
	return positionHolder;
}

void trip::setVisitList()
{
	unsigned int option;
	bool wineriesLeft = true;

	cout << endl << setw(15) << " " << "Wineries to pick from\n";
	this->outputWineryTable();
	cout << endl;

	option = this->inputCheck();

	while (option != 0 && wineriesLeft)
	{
		this->wineries[option - 1]->setVisited(false);
		wineriesLeft = this->checkIfMore();

		if (wineriesLeft)
		{
			cout << endl << setw(15) << " " << "Wineries you picked\n";
			this->outputWineryTableMaker();
			cout << endl;
			cout << endl << setw(15) << " " << "Wineries to pick from\n";
			this->outputWineryTable();
			cout << endl;

			option = this->inputCheck();
		}
	}




}

void trip::outputWineryTableMaker()
{
	cout << right << setw(3) << "#" << left << setw(35) << " Name of winery"
		 << right << setw(10) << "# of Wines" << endl;
	cout << setfill('-');
	cout << setw(48) << "-";
	cout << setfill(' ');
	cout << endl;

	for(unsigned int count = 0; count < this->wineries.size(); ++count)
	{
		if (!this->wineries[count]->getVisited())
		{
			cout << right << setw(3) << this->wineries[count]->getNumber()
				 << left << " " << setw(34)
				 << this->wineries[count]->getName() << right << setw(10)
				 << this->wineries[count]->wineList.size() << endl;
		}
	}

}

unsigned int trip::inputCheck()
{
	unsigned int option;

	do
	{
		cout << "\nEnter the number of the winery you want"
				" to visit (0 to exit): ";
		if(!(cin >> option))
		{
			cout << "\nInvalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while(option < 0 || option > this->wineries.size());

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return option;
}

int trip::tourSelect()
{
	int choice;

	cout << "1 - Select the number number of wineries you want to tour\n"
			"2 - Make your own tour\n"
			"0 - Exit\n\n";
	do
	{
		cout << "Make a selection: ";
		if(!(cin >> choice))
		{
			cout << "\nInvalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while (choice < 0 || choice > 2);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return choice;
}

bool trip::checkIfMore()
{
	bool temp = false;
	unsigned int count = 0;

	while (count < this->wineries.size() && !temp)
	{
		if (this->wineries[count]->getVisited())
		{
			temp = true;
		}
		count++;
	}
	return temp;
}

unsigned int trip::makeNumberTripSelect()
{
	unsigned int choice;

	do
	{
		cout << "Select the number of wineries you want to visit(0 to exit): ";
		if(!(cin >> choice))
		{
			cout << "\nInvalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while (choice < 0 || choice > this->wineries.size());

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return choice;
}

vector<int> trip::setNumberVisitList(int choice)
{
	int position;
	vector<int> placesToVisit;

	int counter = 0;
	this->makeAllUnvisited();

	position = this->findShortestDist(counter++, true);
	placesToVisit.push_back(position);
	this->wineries[position]->setVisited(true);
	while (counter < choice)
	{
		position = this->findShortestDist(position, false);
		placesToVisit.push_back(position);
		this->wineries[position]->setVisited(true);
		counter++;
	}

	this->resetVisited();
	for (unsigned int i = 0; i < placesToVisit.size(); i++)
	{
		this->wineries[placesToVisit[i]]->setVisited(false);
	}
	return placesToVisit;
}

int trip::wineQuantitySelect()
{
	int choice;
	bool loop = true;

	do
	{
		cout << "How many do you want? (-number to exit): ";
		if(!(cin >> choice))
		{
			cout << "\nInvalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			loop = false;
		}
	}while (loop);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return choice;
}

void trip::winePurchases(int pos)
{
	string wineName;
	int quantity;
	int location;

	cout << right << setw(40) << this->wineries[pos]->getName() << endl;
	this->outputTableWineCheckout(pos);
	cout << endl;
	this->outputTotals();
	cout << endl;
	location = this->wineNumberSelect();
	while (location != 0)
	{
		quantity = this->wineQuantitySelect();
		if (quantity >= 0)
		{
			this->boozeList[location - 1]->quantity = quantity;
		}

		cout << endl << endl;
		cout << right << setw(40) << this->wineries[pos]->getName() << endl;
		this->outputTableWineCheckout(pos);
		cout << endl;
		this->calculateTotals();
		this->outputTotals();
		cout << endl;
		location = this->wineNumberSelect();
	}


}

unsigned int trip::wineNumberSelect()
{
	unsigned int choice;

	do
	{
		cout << "Select the wine you wish to purchase(0 to exit): ";
		if(!(cin >> choice))
		{
			cout << "\nInvalid input.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while (choice < 0 || choice > this->boozeList.size());

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return choice;
}

//You'll have to add all the totals together in main or something...hmmm
void trip::calculateTotals()
{
	float temp;

	temp = 0;

	for(unsigned int x = 0; x < this->boozeList.size(); x++)
	{
		temp += this->boozeList[x]->wine->getPrice()
			   * this->boozeList[x]->quantity;
	}

	this->subTotal = temp;
	this->tax = temp * .0875;
	this->total = this->subTotal + this->tax;
}

void trip::outputTotals()
{
	cout << right << setw(50) << "Subtotal:" << setw(10)
		 << this->subTotal << endl << setw(50) << "Tax:" << setw(10)
		 << this->tax << endl << setw(50) << "Total:" << setw(10)
		 << this->total << endl;
}

void trip::touring(vector<Winery*> mainList)
{
	float subtotal;
	int choice;
	int num;
	vector<int> placesToVisit;

	this->wineries = mainList;

	choice = this->tourSelect();
	while(choice != 0)
	{
		this->subTotal = 0;
		this->tax = 0;
		this->total = 0;
		subtotal = 0;
		if (choice == 1)
		{
			num = this->makeNumberTripSelect();
			placesToVisit = this->setNumberVisitList(num);
			for(unsigned int x = 0; x < placesToVisit.size(); x++)
			{

				this->setWinesPurchases(this->wineries, placesToVisit[x]);
				cout << endl;
				this->winePurchases(placesToVisit[x]);
				subtotal += this->subTotal;
				cout << endl;
				this->outputCompleteTotal(subtotal);
				cout << endl << endl;
				this->clearPurchases();
				this->subTotal = 0;
				this->tax = 0;
				this->total = 0;
			}
		}
		else
		{
			this->setVisitList();
			num = this->findShortestDist(0, true);
			while (num >= 0)
			{

				this->setWinesPurchases(this->wineries, num);
				cout << endl;
				this->winePurchases(num);
				subtotal += this->subTotal;
				cout << endl;
				this->outputCompleteTotal(subtotal);
				cout << endl << endl;
				this->clearPurchases();
				this->subTotal = 0;
				this->tax = 0;
				this->total = 0;

				this->wineries[num]->setVisited(true);
				num = this->findShortestDist(num, false);
			}
			cout << endl;
		}
		cout << "Total Distance Traveled: " << this->distanceTraveled <<
				 endl << endl;
		this->distanceTraveled = 0;

		choice = this->tourSelect();
	}



}

void trip::outputCompleteTotal(float subtotal)
{
	cout << right << setfill('-');
	cout << setw(60) << "-";
	cout << setfill(' ');
	cout << endl << setw(40) << "*Overall Total*" << endl
		 << setw(50) << "Subtotal:" << setw(10)
		 << subtotal << endl << setw(50) << "Tax:" << setw(10)
		 << subtotal * .0875 << endl << setw(50) << "Total:" << setw(10)
		 << subtotal + (subtotal * .0875) << endl;
}

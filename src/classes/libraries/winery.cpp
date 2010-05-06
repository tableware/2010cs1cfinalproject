#include "winery.h"

Winery::Winery() :
	number(0),
	name(""),
	distance(0.0),
	visited(true)
{

}

Winery::Winery(int number, string name, float distance) :
	number(number),
	name(name),
	distance(distance),
	visited(true)

{
}

Winery::~Winery()
{

}


void Winery::setName(string name)
{
	this->name = name;
}

string Winery::getName()
{
	return this->name;
}

void Winery::setNumber(int number)
{
	this->number = number;
}

int Winery::getNumber()
{
	return this->number;
}

void Winery::setVisited(bool visited)
{
	this->visited = visited;
}

bool Winery::getVisited()
{
	return this->visited;
}

void Winery::setDistance(float distance)
{
	this->distance = distance;
}

float Winery::getDistance()
{
	return this->distance;
}

void Winery::outputWineTable()
{
	unsigned int count;

	count = 0;

	cout << right << setw(3) << "#" << left << setw(35) << " Name of wine"
		 << right << setw(10) << "Price" << setw(8) << "Year" << endl;
	cout << setfill('-');
	cout << setw(56) << "-";
	cout << setfill(' ');
	cout << endl << fixed << setprecision(2);

	while (count < this->wineList.size())
	{
		cout << right << setw(3) << count + 1 << left << " " << setw(34)
			 << this->wineList[count]->getName() << right << setw(10)
			 << this->wineList[count]->getPrice() << setw(8)
			 << this->wineList[count]->getYear() << endl;
		count++;
	}

}

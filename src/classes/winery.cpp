#include "winery.h"

Winery::Winery() :
	numOfWines(0),
	number(0),
	name("")

{

}

Winery::Winery(int number, string name) :
	numOfWines(0),
	number(number),
	name(name)

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

void Winery::setSubTotal(float subTotal)
{
	this->subTotal = subTotal;
}

float Winery::getSubTotal()
{
	return this->subTotal;
}

void Winery::setVisited(bool visited)
{
	this->visited = visited;
}

bool Winery::getVisited()
{
	return this->visited;
}

void Winery::setNumOfWines(int numOfWines)
{
	this->numOfWines = numOfWines;
}
int Winery::getNumOfWines()
{
	return this->numOfWines;
}

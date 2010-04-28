#include "winery.h"

Winery::Winery() :
	number(0),
	name("")
{

}

Winery::Winery(int number, string name) :
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

void Winery::setSubTotal(int subTotal)
{
	this->subTotal = subTotal;
}

int Winery::getSubTotal()
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

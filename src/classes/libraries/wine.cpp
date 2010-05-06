#include "wine.h"

Wine::Wine() : name(""),
			   price(0.0),
			   year(0)
{

}

Wine::Wine(string name, float price, int year, int quantity) :
		name(name),
		price(price),
		year(year)
{

}

Wine::~Wine()
{

}

void Wine::setName(string name)
{
	this->name = name;
}

string Wine::getName()
{
	return name;
}

void Wine::setPrice(float price)
{
	this->price = price;
}

float Wine::getPrice()
{
	return this->price;
}

void Wine::setYear(int year)
{
	this->year = year;
}

int Wine::getYear()
{
	return this->year;
}

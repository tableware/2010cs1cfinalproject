#include "wineryDistance.h"

WineryDistance::WineryDistance() :
	number(0),
	distance(0.0)
{

}

WineryDistance::WineryDistance(int number, float distance) :
		number(number),
		distance(distance)
{

}

WineryDistance::~WineryDistance()
{

}

void WineryDistance::setNumber(int number)
{
	this->number = number;
}

int WineryDistance::getNumber()
{
	return this->number;
}

void WineryDistance::setDistance(float distance)
{
	this->distance = distance;
}

float WineryDistance::getDistance()
{
	return this->distance;
}

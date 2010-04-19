/*
 * wine.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 */

#ifndef WINE_H_
#define WINE_H_

#include "../header.h"

struct Wine
{
	string name;			//name of wine
	float price;
	string year;
	int quantity;			//used only for output/calculations - set to 0; change only in temp class stack
	Wine* next;
};

#endif /* WINE_H_ */

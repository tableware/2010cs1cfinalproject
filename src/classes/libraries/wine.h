/*
 * wine.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 */

#ifndef WINE_H_
#define WINE_H_

#include "../../header.h"


class Wine
{
	public:
		Wine();
		Wine(string name, float price, int year, int quantity);
		~Wine();

		void setName(string name);
		string getName();

		void setPrice(float price);
		float getPrice();

		void setYear(int year);
		int getYear();

		void setQuantity(int quantity);
		int getQuantity();

	private:
		string name;			//name of wine
		float price;
		int year;
		int quantity;			//used only for output/calculations - set to 0; change only in temp class stack
};

#endif /* WINE_H_ */

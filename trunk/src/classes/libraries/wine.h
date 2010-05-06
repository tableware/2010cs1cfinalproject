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
		/**
		 * Empty class constructor
		 */
		Wine();

		/**
		 * Initalizes the class with the specified values
		 */
		Wine(string name, float price, int year, int quantity);

		/**
		 * Class distructor
		 */
		~Wine();

		/**
		 * Sets the name of the wine
		 */
		void setName(string name);

		/**
		 * Returns the name of the wine
		 */
		string getName();

		/**
		 * Sets the price of the wine
		 */
		void setPrice(float price);

		/**
		 * Returns the price of the wine
		 */
		float getPrice();

		/**
		 * Sets the year that the wine was produced
		 */
		void setYear(int year);

		/**
		 * Returns the year that the wine was produced
		 */
		int getYear();

	private:
		/**
		 * Name of the wine
		 */
		string name;

		/**
		 * Price of the wine
		 */
		float price;

		/**
		 * Year of the wine
		 */
		int year;
};

#endif /* WINE_H_ */

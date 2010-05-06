/*
 * trip.h
 *
 *  Created on: Apr 29, 2010
 *      Author: darkstar1103
 */

#ifndef TRIP_H_
#define TRIP_H_

#include "../../header.h"

// do a forward declare
class Winery;

struct winePurchase;

class trip
{

	public:
		trip(); //default trip constructor
		~trip(); //trip deconstructor

		/************************************************************
		 * Gets the subtotal
		 ************************************************************/
		float getSubTotal();

		/************************************************************
		 * Gets the tax
		 ************************************************************/
		float getTax();

		/************************************************************
		 * Gets the total
		 ************************************************************/
		float getTotal();

		/************************************************************
		 * Gets the distance traveled
		 ************************************************************/
		float getDistanceTraveled();

		/************************************************************
		 * Sets the distance traveled
		 ************************************************************/
		void setDistanceTraveled(float distTraveled);

		/************************************************************
		 * Gets the shortest distance from base or from another winery
		 * This also calculates teh distance traveled when going there
		 ************************************************************/
		int findShortestDist(int loc, bool firstInstance);

		/************************************************************
		 * Outputs the wines in a checkout list for you to buy
		 ************************************************************/
		void outputTableWineCheckout(int place);

		/************************************************************
		 * links the wines from the main list to the booze list at
		 * specified location
		 ************************************************************/
		void setWinesPurchases(vector<Winery*> mainList, unsigned int loc);

		/************************************************************
		 * clears the booze list of wines bought
		 ************************************************************/
		void clearPurchases();

		/************************************************************
		 * outputs the winery table of places to visit
		 ************************************************************/
		void outputWineryTable();

		/************************************************************
		 * outputs the wineries you selected to vist
		 ************************************************************/
		void outputWineryTableMaker();

		/************************************************************
		 * makes all the wineries visited so you can select them again
		 ************************************************************/
		void resetVisited();

		/************************************************************
		 * makes all the wineries not visisted
		 ************************************************************/
		void makeAllUnvisited();

		/************************************************************
		 * Makes the list of wineries you want to visist
		 ************************************************************/
		void setVisitList();

		/************************************************************
		 * Gets the choice of the tour you want
		 ************************************************************/
		int tourSelect();

		/************************************************************
		 * Sees if there is more winereies to visit
		 ************************************************************/
		bool checkIfMore();

		/************************************************************
		 * Gets the number for how many winereies you want to visit
		 ************************************************************/
		unsigned int makeNumberTripSelect();

		/************************************************************
		 * Returnns in order the list of wineries to visit that's
		 * closest to eachother
		 ************************************************************/
		vector<int> setNumberVisitList(int choice);

		/************************************************************
		 * Checks the input
		 ************************************************************/
		unsigned int inputCheck();

		/************************************************************
		 * Gets the ammount of wines you want to buy
		 ************************************************************/
		int wineQuantitySelect();

		/************************************************************
		 * Buys the wine
		 ************************************************************/
		void winePurchases(int pos);

		/************************************************************
		 * Gets the number of the wine you want to buy
		 ************************************************************/
		unsigned int wineNumberSelect();

		/************************************************************
		 * Calculates the subtotal, tax, and total
		 ************************************************************/
		void calculateTotals();

		/************************************************************
		 * outputs the totals
		 ************************************************************/
		void outputTotals();

		/************************************************************
		 * outputs the total of every total at the winereies
		 ************************************************************/
		void outputCompleteTotal(float subtotal);

		/************************************************************
		 * The function that tours the winereis you select and buys
		 * what you want to buy
		 ************************************************************/
		void touring(vector<Winery*> mainList);

		vector<Winery*> wineries;				//vector for wineries
		vector<winePurchase*> boozeList;		//vector struct of boozes

	private:
		float subTotal;					//subtotal of purchases
		float tax;						//tax on the purchases
		float distanceTraveled;			//total distance traveled
		float total;					//subtotal plus tax
};

#endif /* TRIP_H_ */

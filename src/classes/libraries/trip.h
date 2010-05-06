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

		/*
		 * Gets
		 */
		float getSubTotal();
		float getTax();
		float getTotal();
		float getDistanceTraveled();

		//maybe a temporary function, depends on what needs to be done
		void setDistanceTraveled(float distTraveled);

		void process(vector<Winery*> mainList);

		int findShortestDist(int loc, bool firstInstance);

		void outputTableWineCheckout(int place);

		void setWinesPurchases(vector<Winery*> mainList, unsigned int loc);

		void clearPurchases();

		void outputWineryTable();

		void outputWineryTableMaker();

		void resetVisited();

		void makeAllUnvisited();

		void setVisitList();

		int tourSelect();

		bool checkIfMore();

		unsigned int makeNumberTripSelect();

		vector<int> setNumberVisitList(int choice);

		unsigned int inputCheck();

		int wineQuantitySelect();

		void winePurchases(int pos);

		unsigned int wineNumberSelect();

		void calculateTotals();

		void outputTotals();

		void outputCompleteTotal(float subtotal);

		void touring(vector<Winery*> mainList);

		vector<Winery*> wineries;
		vector<winePurchase*> boozeList;

	private:
		float subTotal;
		float tax;
		float distanceTraveled;
		float total;
};

#endif /* TRIP_H_ */

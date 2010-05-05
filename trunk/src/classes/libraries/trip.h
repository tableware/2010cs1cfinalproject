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
		trip();
		~trip();

		float getSubTotal();
		float getTax();
		float getTotal();

		void process(vector<Winery*> mainList);

		int findShortestDist(int loc);

		void outputTableWineCheckout(int place);

		void setWinesPurchases(vector<Winery*> mainList, unsigned int loc);

		void clearPurchases();

		void outputWineryTable();

		void outputWineryTableMaker();

		void resetVisited();

		void setVisitList();

		unsigned int inputCheck();

		vector<Winery*> wineries;
		vector<winePurchase*> boozeList;

	private:
		float subTotal;
		float tax;
		float distanceTraveled;
};

#endif /* TRIP_H_ */

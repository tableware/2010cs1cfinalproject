/*
 * winery.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 *
 * @Note: I have commented out all of the methods that have not been implamented yet
 * so that we do not try to run a method and get a segmentation fault.
 */

#ifndef WINERY_H_
#define WINERY_H_

#include "../header.h"

// Forward declarations so that compiler won't bitch at us
class Wine;
class WineryDistance;

class Winery
{
	public:
		Winery();	//default constructor
		Winery(int number, string name);	//parameter constructor
		~Winery();

		void setName(string name);
		string getName();

		void setNumber(int number);
		int getNumber();

		void setSubTotal(float subTotal);
		float getSubTotal();

		void setVisited(bool visited);
		bool getVisited();

		void setNumOfWines(int numOfWines);
		int getNumOfWines();

		vector<Wine*> wineList;
		vector<WineryDistance*> distanceList;
		static int numOfWineries;		//prolly should make this static

		/*******************************************************************
		 *
		 * FUNCTION operator =
		 * Copy constructor
		 * _________________________________________________________________
		 * Enables you to set Wineries equal to each other
		 * Creates new linked lists for distances and wines
		 *
		 * RETURNS this (lawl)
		 *
		 * Used for making a temp list of wineries
		 *******************************************************************/
	//	Winery& operator= (const Winery oldWinery);

	//	//These are always useful for testing functions
	//	int	GetNumOfWineries();
	//	float GetSubTotal();
	//	bool GetVisited();
	//
	//	//Dunno if we will need these, but couldn't hurt for now
	//	//We probably won't...
	//	void SetNumOfWineries(int num);
	//	//We will need this for main prolly
	//	void SetVisited(bool visit);
	//
	//	/********************************************************
	//	 * Function - OutputWinery
	//	 *
	//	 * This outputs info for one individual Winery
	//	 * 	outputs: name of Winery, number of it, then table for
	//	 * 	wine and price by going down linked list
	//	 *
	//	 * This couts to screen so you can see what to shop for
	//	 ********************************************************/
	//	void OutputWinery();
	//
	//	/********************************************************
	//	 * Function - OutputShopWinery
	//	 *
	//	 * This outputs info for one individual Winery
	//	 * 	outputs: name of Winery, number of it, then table for
	//	 * 	wine, price, and quantity bought by going down linked list
	//	 *
	//	 * At the bottom it shows the total (no tax), the tax amount,
	//	 * and the sub total for shopping there
	//	 *
	//	 * Used only for the temp Winery list
	//	 *
	//	 * couts to screen so you can see what you bought
	//	 ********************************************************/
	//	void OutputShopWinery();
	//
	//	/********************************************************
	//	 * Function - OFileWinery
	//	 *
	//	 * This outfiles info for one individual Winery
	//	 * 	outfiles: name of Winery, number of it, then table for
	//	 * 	wine, price, and quantity bought by going down linked list
	//	 *
	//	 * At the bottom it shows the total (no tax), the tax amount,
	//	 * and the sub total for shopping there
	//	 *
	//	 * Used only for the temp Winery list
	//	 ********************************************************/
	//	void OFileShopWinery();
	//
	//	/********************************************************
	//	 * Function - OutputShopDist
	//	 *
	//	 * This outputs distances for one individual Winery from others
	//	 * 	outputs: the number of the Winery and its distance from source
	//	 *
	//	 * couts to screen so you can see the distance
	//	 ********************************************************/
	//	void OutputWineryDist();
	//
	//	/********************************************************
	//	 * Function - AddWine
	//	 *
	//	 * This goes adds the main Winery list.
	//	 * Finds Winery specified
	//	 * Adds to the Winery wine list: the name of wine and price
	//	 * Sets quantity to 0
	//	 *
	//	 * Returns: the new head
	//	 ********************************************************/
	//	Winery* AddWine(Winery*& head);
	//
	//	/********************************************************
	//	 * Function - ChangePrice
	//	 *
	//	 * This goes adds the main Winery list.
	//	 * Finds wine specified (if in list)
	//	 * Changes the price to the new specified price
	//	 * Repeats through list until it hits NULL
	//	 *
	//	 * Returns: the new head
	//	 ********************************************************/
	//	Winery* ChangePrice(Winery*& head);
	//
	//	/*******************************************************************
	//	 *
	//	 * FUNCTION operator <<
	//	 * _________________________________________________________________
	//	 * Enables you output a Winery directly.
	//	 * RETURNS the output stream
	//	 *******************************************************************/
	//	friend ostream& operator <<(ostream &os, const Winery &obj);


	private:
		int numOfWines;
		int number;
		string name;
		bool visited;			//checks to see if you visited the location
		float subTotal;			//for outputting/calculations - set to 0; change only in temp class stack
};

#endif /* WINERY_H_ */

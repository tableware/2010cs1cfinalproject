/*
 * winery.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 */

#ifndef WINERY_H_
#define WINERY_H_

#include "../header.h"
#include "wineryDistance.h"

// hack
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//#include "wine.h"
//#include "wineryDistance.h"
// end hack

class Winery
{
public:
	Winery();	//default constructor
	Winery(string wName, int wNum);	//parameter constructor
	~Winery();

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
	Winery& Winery::operator = (const Winery oldWinery);

	//These are always useful for testing functions
	string GetName();
	int GetNumber();
	int	GetNumOfWineries();
	float GetSubTotal();
	bool GetVisited();

	//Dunno if we will need these, but couldn't hurt for now
	//We probably won't...
	void SetName(string wineryName);
	void SetNumber(int wineryNum);
	void SetNumOfWineries(int num);
	//We will need this for main prolly
	void SetVisited(bool visit);

	/********************************************************
	 * Function - OutputWinery
	 *
	 * This outputs info for one individual winery
	 * 	outputs: name of winery, number of it, then table for
	 * 	wine and price by going down linked list
	 *
	 * This couts to screen so you can see what to shop for
	 ********************************************************/
	void OutputWinery();

	/********************************************************
	 * Function - OutputShopWinery
	 *
	 * This outputs info for one individual winery
	 * 	outputs: name of winery, number of it, then table for
	 * 	wine, price, and quantity bought by going down linked list
	 *
	 * At the bottom it shows the total (no tax), the tax amount,
	 * and the sub total for shopping there
	 *
	 * Used only for the temp winery list
	 *
	 * couts to screen so you can see what you bought
	 ********************************************************/
	void OutputShopWinery();

	/********************************************************
	 * Function - OFileWinery
	 *
	 * This outfiles info for one individual winery
	 * 	outfiles: name of winery, number of it, then table for
	 * 	wine, price, and quantity bought by going down linked list
	 *
	 * At the bottom it shows the total (no tax), the tax amount,
	 * and the sub total for shopping there
	 *
	 * Used only for the temp winery list
	 ********************************************************/
	void OFileShopWinery();

	/********************************************************
	 * Function - OutputShopDist
	 *
	 * This outputs distances for one individual winery from others
	 * 	outputs: the number of the winery and its distance from source
	 *
	 * couts to screen so you can see the distance
	 ********************************************************/
	void OutputWineryDist();

	/********************************************************
	 * Function - AddWine
	 *
	 * This goes adds the main winery list.
	 * Finds winery specified
	 * Adds to the winery wine list: the name of wine and price
	 * Sets quantity to 0
	 *
	 * Returns: the new head
	 ********************************************************/
	Winery* AddWine(Winery*& head);

	/********************************************************
	 * Function - ChangePrice
	 *
	 * This goes adds the main winery list.
	 * Finds wine specified (if in list)
	 * Changes the price to the new specified price
	 * Repeats through list until it hits NULL
	 *
	 * Returns: the new head
	 ********************************************************/
	Winery* ChangePrice(Winery*& head);

	/*******************************************************************
	 *
	 * FUNCTION operator <<
	 * _________________________________________________________________
	 * Enables you output a winery directly.
	 * RETURNS the output stream
	 *******************************************************************/
	friend ostream& operator <<(ostream &os, const Winery &obj);

	//Wine* wineHead;	//set to null in constructor
	WineryDistance* distHead; //set to null in constructor
	static int numOfWineries;		//prolly should make this static

private:
	string name;
	int number;
	bool visited;			//checks to see if you visited the location
	float subTotal;			//for outputting/calculations - set to 0; change only in temp class stack
};

#endif /* WINERY_H_ */

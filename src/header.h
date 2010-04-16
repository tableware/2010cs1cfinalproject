/*
 * header.h
 *
 *  Created on: Apr 12, 2010
 *      Author: jgibbins1
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Structs
struct Wine
{
	string name;			//name of wine
	float price;
	string year;
	int quantity;			//used only for output/calculations - set to 0; change only in temp class stack
	Wine* next;
};

struct WineryDistance
{
	int number;
	float distance;
	WineryDistance* next;
};

//Winery linked list will be in main & another list for traveling to u make
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
	friend ostream& operator <<(ostream &os,const Winery &obj);

	Wine* wineHead;	//set to null in constructor
	WineryDistance* distHead; //set to null in constructor
	static int numOfWineries;		//prolly should make this static

private:
	string name;
	int number;
	bool visited;			//checks to see if you visited the location
	float subTotal;			//for outputting/calculations - set to 0; change only in temp class stack
};

//Global Functions

/********************************************************
 * Function - MakeList
 *
 * This inFiles the information and creates a stack of
 * of wineries;
 *
 * In the order of however it comes
 *
 * Returns: head
 ********************************************************/
Winery* MakeList();

/********************************************************
 * Function - AddWinery
 *
 * This goes adds the main winery list.
 * Adds: The new winery's name, number, updates num of wineries,
 * sets visited to false, and sets subtotal to 0
 *
 * This then proceeds down the list and adds in its distance
 * to the stacks of every winery
 *
 * Returns: the new head
 ********************************************************/
Winery* AddWinery(Winery*& head);

/********************************************************
 * Function - CalcClosestWinery
 *
 * This goes through the distance list of one winery, finds
 * the shortest distance, updates the total distance traveled,
 * and returns the closest one
 *
 * Returns: number of closest winery
 ********************************************************/
int CalcClosestWinery(Winery* ptr, float& totDist);

/********************************************************
 * Function - CalcTotal
 *
 * This goes through the  temp winery list and sums all
 * the subtotals
 *
 * Returns: the total
 ********************************************************/
float CalcTotal(Winery* tHead);

//Templates
template <class T>
void Push(T& head, T& newData)
{
	newData->next = head;
	head = newData;
}

//finds key and deletes it while maintaining linked list
//Used for deleting wineries, winery distances, and wines
template <class R>
void Pop(R& head, R& ptrKey)
{
	R temp;

	temp = head;

	if (head == ptrKey)
	{
		head = head->next;
	}
	else
	{
		while (temp->next != ptrKey && temp != NULL)
		{
			temp = temp->next;
		}

		temp->next = ptrKey->next;
	}

	if (temp != NULL)
	{
		delete ptrKey;
	}
	else
	{
		cout << "\nDidn't find anything to pop!\n\n";
	}
}

//finds the winery number through a pointer to the class or
//a pointer to the struct wineryDistance
// Returns - pointer (Null if it didn't find anything)
template <class S>
S FindWineryNum(S head, int key)
{
	S temp;
	bool found;

	temp = head;
	found = false;

	while(temp != NULL && found == false)
	{
		if (temp->number == key)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}
	return temp;
}

/********************************************************
 * Funtion - FindName
 *
 * This finds a wine/winery by its name.
 * Returns null if not found
 *
 * Used for shopping for a wine by checking if it's there,
 * popping wineries after done with them, seeing if winery
 * exists, and ect...
 ********************************************************/
template <class Q>
Q FindName(Q head, string key)
{
	Q temp;
	bool found;

	temp = head;
	found = false;

	while(temp != NULL && found == false)
	{
		if (temp->name == key)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}
	return temp;
}

#endif /* HEADER_H_ */

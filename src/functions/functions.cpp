/*
 * functions.cpp
 *
 *  Created on: Apr 12, 2010
 *      Author: jgibbins1
 */

#include "../header.h"

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
 * This goes adds the main Winery list.
 * Adds: The new Winery's name, number, updates num of wineries,
 * sets visited to false, and sets subtotal to 0
 *
 * This then proceeds down the list and adds in its distance
 * to the stacks of every Winery
 *
 * Returns: the new head
 ********************************************************/
Winery* AddWinery(Winery*& head);

/********************************************************
 * Function - CalcClosestWinery
 *
 * This goes through the distance list of one Winery, finds
 * the shortest distance, updates the total distance traveled,
 * and returns the closest one
 *
 * Returns: number of closest Winery
 ********************************************************/
int CalcClosestWinery(Winery* ptr, float& totDist);

/********************************************************
 * Function - CalcTotal
 *
 * This goes through the  temp Winery list and sums all
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
//Used for deleting wineries, Winery distances, and wines
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

//finds the Winery number through a pointer to the class or
//a pointer to the struct WineryDistance
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
 * This finds a wine/Winery by its name.
 * Returns null if not found
 *
 * Used for shopping for a wine by checking if it's there,
 * popping wineries after done with them, seeing if Winery
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

/*
 * functions.h
 *
 *  Created on: Apr 26, 2010
 *      Author: jgibbins1
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

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

int returnByteWinery(int val);

int returnByteWine(int val);

int returnByteWineryDistance(int val);

int returnByteArraySize(int val);

void createBinaryFile(vector<Winery*> list);

void writeWinery(vector<Winery*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[]);

void writeWineryDistance(vector<WineryDistance*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[]);

void writeWine(vector<Wine*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[]);

vector<Winery*> readBinaryFile();

void readWineryDistance( Winery*& wTemp, int numOfWineries, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount);

void readWine( Winery*& wTemp, int numOfWines, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount);

void readWines( Winery*& wTemp, int numOfWines, int& wineryCount,
				int& wineryDistanceCount, int& wineCount, int& stringCount);

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

//finds a number through a pointer to the vector of a class
// Returns - place where it is found in vector (the size if not found)
template <class S>
int FindNum(vector<S*> vectorWithNumber, int key)
{
	bool found;
	unsigned int search;

	found = false;
	search = 0;

	while(search < vectorWithNumber.size() && found == false)
	{
		if (vectorWithNumber[search]->getNumber() == key)
		{
			found = true;
		}
		else
		{
			search++;
		}
	}
	return search;
}

/********************************************************
 * Funtion - FindName
 *
 * This finds a wine/Winery by its name.
 * Returns the vector size if not found
 *
 * Used for shopping for a wine by checking if it's there,
 * popping wineries after done with them, seeing if Winery
 * exists, and ect...
 ********************************************************/
template <class Q>
int FindName(vector<Q*> vectorWithName, string key)
{
	bool found;
	unsigned int search;

	found = false;
	search = 0;

	while(search < vectorWithName.size() && found == false)
	{
		if (vectorWithName[search]->getName() == key)
		{
			found = true;
		}
		else
		{
			search++;
		}
	}
	return search;
}

#endif /* FUNCTIONS_H_ */

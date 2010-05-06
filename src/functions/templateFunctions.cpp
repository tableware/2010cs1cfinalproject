/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "templateFunctions.h"

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

/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#ifndef TEMPLATEFUNCTIONS_H_
#define TEMPLATEFUNCTIONS_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Finds a number through a pointer to the vector of a class
 *
 * Returns - place where it is found in vector (the size if not found)
 */
template <class S>
int FindNum(vector<S*> vectorWithNumber, int key);

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
int FindName(vector<Q*> vectorWithName, string key);

#endif

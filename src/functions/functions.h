/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "../header.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// -------------------------------- STRUCTS -------------------------------- //
/**
 * Holds the information that will be used when reading and writing
 * wineries to disk in a binary format.
 */
struct binaryWinery
{
	int number;
	unsigned int distances;
	unsigned int wines;
	char name[70];
};

/**
 * Holds the information that will be used when reading and writing
 * winery distances to disk in a binary format.
 */
struct binaryWineDistance
{
	int number;
	float distance;
};

/**
 * Holds the information that will be used when reading and writing wines to
 * disk in a binary format.
 */
struct binaryWine
{
	float price;
	int year;
	char name[70];
};

// ------------------------------- FUNCTIONS ------------------------------- //
/**
 * Reads in the winery information from the binary file specified into a vector
 * and returns that vector to the caller
 */
vector<Winery*> binaryFileRead(string filename);

/**
 * Writes the winery vector to the specified file for later retrieval
 */
void binaryFileWrite(string filename, vector<Winery*> wineries);


#endif /* FUNCTIONS_H_ */

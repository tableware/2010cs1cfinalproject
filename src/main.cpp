/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "header.h"

int main()
{
	string filename = "src/data/persistence.dat";
	mainDriver::getInstance().wineries = binaryFileRead(filename);
	// run the application
	mainDriver::getInstance().main();
	binaryFileWrite(filename, mainDriver::getInstance().wineries);
	return 0;
}

/*
 * main.cpp
 *
 *  Created on: Apr 12, 2010
 *      Author: jgibbins1
 */

#include "header.h"

int main()
{
	// create the application driver
	driver* applicationDriver = new driver;

	// display the main runloop of the driver
	applicationDriver->main();

	// delete the driver since we're done with it
	delete applicationDriver;

	return 0;
}

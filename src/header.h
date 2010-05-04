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
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <ios>

using namespace std;

// classes
#include "classes/libraries/wine.h"
#include "classes/libraries/wineryDistance.h"
#include "classes/libraries/winery.h"
#include "classes/libraries/trip.h"

#include "classes/drivers/driver.cpp"
#include "classes/drivers/mainDriver.h"
#include "classes/drivers/adminDriver.h"

using namespace wineryProject_drivers;

#include "functions/functions.h"

struct winePurchase
{
	Wine* wine;
	int quantity;
};

#endif /* HEADER_H_ */

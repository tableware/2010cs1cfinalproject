/*
 * adminDriver.h
 *
 *  Created on: Apr 29, 2010
 *      Author: darkstar1103
 */

#include "../header.h"

#ifndef ADMINDRIVER_H_
#define ADMINDRIVER_H_

class adminDriver
{
	public:
		adminDriver(vector<Winery*>& wineries);
		~adminDriver();

		void menu();
		void main();
		void quit();

		void loadInitialData();

	private:
		/**
		 * dictates if we should have an active runloop
		 */
		bool active;

		/**
		 * List of all of the wineries that we will be working with,
		 * as a note we must declare wineries like this otherwise there will
		 * be a massive fit thrown by the compiler, apparently it doesn't like
		 * it when you try to subclass vector
		 */
		vector<Winery*>* wineries;
};

#endif /* ADMINDRIVER_H_ */

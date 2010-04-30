/*
 * adminDriver.h
 *
 *  Created on: Apr 29, 2010
 *      Author: darkstar1103
 */

#include "../../header.h"

#ifndef ADMINDRIVER_H_
#define ADMINDRIVER_H_

namespace wineryProject_drivers
{
	class adminDriver
	{
		public:
			static adminDriver& getInstance();
			void main(vector<Winery*>& wineries);

		protected:
			void menu();
			void quit();

			void loadInitialData();
			void addWinery();

		private:
			adminDriver();
			~adminDriver();
			adminDriver(const adminDriver &);			// leave undefined
			adminDriver& operator=(const adminDriver&);	// leave undefined

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
}
#endif /* ADMINDRIVER_H_ */
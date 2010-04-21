/*
 * Contains all of the functions for the driver of the class
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include "header.h"

class driver
{
	public:
		driver();
		~driver();

		/**
		 * Holds the logic for the main run loop of the application
		 */
		void main();

		/**
		 * Displays the menu
		 */
		void menu();

		/**
		 * Lists the wineries that we know about
		 */
		void listWineries();

		/**
		 *	Holds all of the logic to plan a day trip
		 */
		void planDayTrip();

		/**
		 * Holds the logic to for touring wineries and purchasing wines
		 */
		void tourWineriesAndPurchaseWines();

		/**
		 * Performing file maintenace (admin only, this will require a login)
		 */
		void performFileMaintenace();

		/**
		 * Quits the application
		 */
		void quit();

	private:
		/**
		 * dictates if we should have an active runloop
		 */
		bool active;
};

#endif /* DRIVER_H_ */

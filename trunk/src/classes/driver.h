/*
 * Contains all of the functions for the driver of the class
 */

#include "../header.h"


#ifndef DRIVER_H_
#define DRIVER_H_

// do all of the forward declares for dependencies so that the compiler won't throw a fucking bitch fit
class Winery;

class driver
{
	public:
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

		static driver& getInstance();
	private:
		driver();
		~driver();
		driver(const driver &);             // left undefined intentionally
		driver& operator=(const driver &); // left undefined intentionally

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
		vector<Winery*> wineries;
};

#endif /* DRIVER_H_ */

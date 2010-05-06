/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "../../header.h"


#ifndef MAINDRIVER_H_
#define MAINDRIVER_H_

// do all of the forward declares for dependencies so that the compiler won't throw a fucking bitch fit
class Winery;

namespace wineryProject_drivers
{

	class mainDriver : driver<mainDriver>
	{
		public:
			/**
			 * Holds the logic for the main run loop of the application
			 */
			void main();

			/**
			 * Lists the wineries that we know about
			 */
			void listWineries();

			/**
			 * Holds the logic to for touring wineries and purchasing wines
			 */
			void tourWineriesAndPurchaseWines();

			/**
			 * Performing file maintenace (admin only, this will require a login)
			 */
			void performFileMaintenace();

			/**
			 * Gets the application wide instance of the class
			 */
			static mainDriver& getInstance();

			/**
			 * List of all of the wineries that we will be working with,
			 * as a note we must declare wineries like this otherwise there will
			 * be a massive fit thrown by the compiler, apparently it doesn't like
			 * it when you try to subclass vector
			 */
			vector<Winery*> wineries;

			/**
			 * Prints out heading for the User interface in the command prompt
			 * including the program title, revision number, etc.
			 */
			virtual void printHeader();
		private:

			/**
			 * Registers all of the menu actions with the driver class
			 */
			mainDriver();

			/**
			 * Handles the destruction of the class
			 */
			virtual ~mainDriver();

			/**
			 * Used to implement singleton pattern, left undefined intentionally
			 */
			mainDriver(const mainDriver &);

			/**
			 * Used to implement singleton pattern, left undefined intentionally
			 */
			mainDriver& operator=(const mainDriver &);


	};
}
#endif /* MAINDRIVER_H_ */

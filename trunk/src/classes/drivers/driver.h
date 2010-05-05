/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#ifndef DRIVER_H_
#define DRIVER_H_

// hack around to make the class work properly and not throw compiler errors
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ios>

using namespace std;

namespace wineryProject_drivers
{
	template <class type>
	class driver
	{
		public:
			/**
			 * Initializes the driver class
			 */
			driver();

			/**
			 * Deconstructs the class once needed
			 */
			virtual ~driver();

			/**
			 * Handles all of the processing associated with main run loop of
			 * the driver. Also handles taking the input from the user and
			 * executing the appropriate menu action.
			 */
			virtual void main();

		protected:
			/**
			 * Displays driver's menu based on the menu items that were
			 * registered with the driver.
			 */
			void menu();

			/**
			 * Registers a menu item for display and routing for the driver
			 */
			void _registerMenuItem(const char name[],                // name displayed on the menu
								   void (type::*processFunction)()); // function used for menu action

			/**
			 * Quits the execution of the driver on the next iteration of the
			 * run loop.
			 */
			void quit();

		private:

			// holds the information of a single menu item
			struct driverMenuItem
			{
				string name;					 // name of the action that will
												 //   be displayed on the menu
				void (type::*processFunction)(); // pointer to the function that
												 //   will handle menu action
			};

			// driver menu
			vector<driverMenuItem*> _driverMenu;

			// driver state, true will continue to execute, false will end
			//   driver execution
			bool active;

	};
}

#endif /* DRIVER_H_ */

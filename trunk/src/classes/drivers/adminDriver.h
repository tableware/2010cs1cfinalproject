/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "../../header.h"

#ifndef ADMINDRIVER_H_
#define ADMINDRIVER_H_

namespace wineryProject_drivers
{
	class adminDriver : driver<adminDriver>
	{
		public:
			/**
			 * Returns the global instance of the admin driver class
			 */
			static adminDriver& getInstance();

			/**
			 * Main run loop of the application, takes a list of wineries that
			 * will be updated during the use of the admin class.
			 */
			void main(vector<Winery*>& wineries);

		protected:
			/**
			 * Loads the initial data file into the wineries vector
			 */
			void loadInitialData();

			/**
			 * Adds a winery to the wineries vector, as well it will update
			 * all of the other wineries to properly reflect the distances.
			 */
			void addWinery();

			/**
			 * Adds a wine to the winery specified.
			 */
			void addWineToWinery();

			/**
			 * Changes the price of a wine specified
			 */
			void changePriceOfWine();

			/**
			 * Holds the logic to select a winery
			 */
			unsigned int _selectWinery();

			/**
			 * Prints out heading for the User interface in the command prompt
			 * including the program title, revision number, etc.
			 */
			virtual void printHeader();
		private:

			/**
			 * Registers all of the menu actions with the driver class
			 */
			adminDriver();

			/**
			 * Handles the destruction of the class
			 */
			virtual ~adminDriver();

			/**
			 * Used to implement singleton pattern, left undefined intentionally
			 */
			adminDriver(const adminDriver &);

			/**
			 * Used to implement singleton pattern, left undefined intentionally
			 */
			adminDriver& operator=(const adminDriver&);	// leave undefined

			/**
			 * Pointer to the list of wineries that we will be updating during
			 * the course of the admin driver execution
			 */
			vector<Winery*>* wineries;

			/**
			 * Holds the password to the admin driver
			 */
			string password;
	};
}
#endif /* ADMINDRIVER_H_ */

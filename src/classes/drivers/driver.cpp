/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "driver.h"

namespace wineryProject_drivers
{
	template <class type>
	driver<type>::driver()
	{

	}

	template <class type>
	driver<type>::~driver()
	{

	}

	template <class type>
	void driver<type>::menu()
	{
		// loop and output the menu
		for (unsigned int i = 0; i < this->_driverMenu.size(); ++i)
		{
			cout << i + 1 << ". " << this->_driverMenu[i]->name << "\n";
		}

		// add the quit option to the menu
		cout << this->_driverMenu.size() + 1 << ". Quit\n\n";
	}

	template <class type>
	void driver<type>::main()
	{
		unsigned int option; // the menu option we will execute

		// initialize the variables
		option = 0;
		this->active = true;

		// main run loop for the driver
		do
		{
			// display the menu
			this->menu();

			// input check loop
			do
			{
				cout << "Please make a selection: ";
				if(!(cin >> option))
				{
					cout << "Invalid input.";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while(option < 1 || option > this->_driverMenu.size() + 1);

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\n\n";

			// check to see if we need to quit
			if(option == this->_driverMenu.size() + 1)
			{
				this->quit();
			}else{

				// executes the appropriate processing function
				(type::getInstance().*(this->_driverMenu[option - 1]->processFunction))();
			}

			cout << "\n\n";

		} while(this->active);
	}

	template <class type>
	void driver<type>::_registerMenuItem(const char name[], void (type::*processFunction)())
	{
		// create a new menu item
		driverMenuItem* menuItem = new driverMenuItem;

		// copy the information
		menuItem->name = name;
		menuItem->processFunction = processFunction;

		// add it to the menu
		this->_driverMenu.push_back(menuItem);
	}

	template <class type>
	void driver<type>::quit()
	{
		// set the driver state to false so that we will stop processing
		//   on the next iteration of the run loop
		this->active = false;
	}
}

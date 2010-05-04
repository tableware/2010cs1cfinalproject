/*
 * driver.cpp
 *
 *  Created on: May 3, 2010
 *      Author: darkstar1103
 */

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
		for (unsigned int i = 0; i < this->_driverMenu.size(); ++i)
		{
			cout << i + 1 << ". " << this->_driverMenu[i]->name << "\n";
		}

		cout << this->_driverMenu.size() + 1 << ". Quit\n\n";
	}

	template <class type>
	void driver<type>::main()
	{
		this->active = true;
		unsigned int option = 0;
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

			// check for the quit option
			if(option == this->_driverMenu.size() + 1)
			{
				this->quit();
			}else{
				void (type::*temp)();

				temp = this->_driverMenu[option - 1]->processFunction;

				//((other)->*(memberFn))();

				(type::getInstance().*temp)();

			}

			cout << "\n\n";

		} while(this->active);
	}

	template <class type>
	void driver<type>::_registerMenuItem(const char name[], void (type::*processFunction)())
	{
		driverMenuItem* menuItem = new driverMenuItem;

		menuItem->name = name;
		menuItem->processFunction = processFunction;

		this->_driverMenu.push_back(menuItem);
	}

	template <class type>
	void driver<type>::quit()
	{
		this->active = false;
	}
}

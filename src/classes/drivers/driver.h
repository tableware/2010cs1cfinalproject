/*
 * driver.h
 *
 *  Created on: May 3, 2010
 *      Author: darkstar1103
 */



#ifndef DRIVER_H_
#define DRIVER_H_

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
			driver();
			~driver();
			virtual void main();

		protected:
			void menu();
			void _registerMenuItem(const char name[], void (type::*processFunction)());
			void quit();


		private:
			struct driverMenuItem
			{
				string name;
				void (type::*processFunction)();
			};

			vector<driverMenuItem*> _driverMenu;
			bool active;

	};
}

#endif /* DRIVER_H_ */

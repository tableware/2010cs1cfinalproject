/*
 * winery.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 *
 * @Note: I have commented out all of the methods that have not been implamented yet
 * so that we do not try to run a method and get a segmentation fault.
 */

#ifndef WINERY_H_
#define WINERY_H_

#include "../../header.h"

// Forward declarations so that compiler won't bitch at us
class Wine;
class WineryDistance;

class Winery
{
	public:
		Winery();	//default constructor
		Winery(int number, string name, float distance);	//parameter constructor
		~Winery();

		void setName(string name);
		string getName();

		void setNumber(int number);
		int getNumber();


		void setVisited(bool visited);
		bool getVisited();

		void setDistance(float distance);
		float getDistance();

		void outputWineTable();

		vector<Wine*> wineList;
		vector<WineryDistance*> distanceList;

	private:
		int number;
		string name;
		float distance;
		bool visited;			//checks to see if you visited the location
};

#endif /* WINERY_H_ */

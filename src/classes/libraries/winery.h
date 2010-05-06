/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#ifndef WINERY_H_
#define WINERY_H_

#include "../../header.h"

// Forward declarations so that compiler will *love* us
class Wine;
class WineryDistance;

class Winery
{
	public:
		/**
		 * Default constructor to initalize the class
		 */
		Winery();

		/**
		 * Initalization constructor
		 */
		Winery(int number,      // Winery number
			   string name,     // Winery name
			   float distance); // Distance form Canyon Villa

		/**
		 * Class destructor
		 */
		~Winery();

		/**
		 * Sets the name of the winery
		 */
		void setName(string name);

		/**
		 * Returns the name of the winery
		 */
		string getName();

		/**
		 * Sets the number of the winery
		 */
		void setNumber(int number);

		/**
		 * Returns the number of the winery
		 */
		int getNumber();

		/**
		 * Sets if we have visited the winery or not during the tour
		 */
		void setVisited(bool visited);

		/**
		 * Returns if we have visited this winery already during the tour
		 */
		bool getVisited();

		/**
		 * Sets the distance of the winery from the Canyon Villa
		 */
		void setDistance(float distance);

		/**
		 * Returns the distance that the winery is from the Canyon Villa
		 */
		float getDistance();

		/**
		 * Outputs all of the information about this winery's wines to the
		 * screen in a table format
		 */
		void outputWineTable();

		/**
		 * List of the wines that are available at this winery
		 */
		vector<Wine*> wineList;

		/**
		 * List of the distances that other wineries are from this one
		 */
		vector<WineryDistance*> distanceList;

	private:
		/**
		 * Number of winery
		 */
		int number;

		/**
		 * Name of winery
		 */
		string name;

		/**
		 * Distance the winery is from the Canyon villa
		 */
		float distance;

		/**
		 * checks to see if you visited the location
		 */
		bool visited;
};

#endif /* WINERY_H_ */

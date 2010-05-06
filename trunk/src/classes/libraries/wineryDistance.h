/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#ifndef WINERYDISTANCE_H_
#define WINERYDISTANCE_H_

class WineryDistance
{
	public:
		/**
		 * Default constructor
		 */
		WineryDistance();

		/**
		 * Initialization constructor
		 */
		WineryDistance(int number, float distance);

		/**
		 * Destructor
		 */
		~WineryDistance();

		/**
		 * Sets the winery number that the distance is referring to
		 */
		void setNumber(int number);

		/**
		 * Returns the winery number that the distance is referring to
		 */
		int getNumber();

		/**
		 * Sets the distance that we are from the specified winery id
		 */
		void setDistance(float distance);

		/**
		 * Returns the winery distance
		 */
		float getDistance();

	private:
		/**
		 * Winery number
		 */
		int number;

		/**
		 * Winery distance
		 */
		float distance;
};


#endif /* WINERYDISTANCE_H_ */

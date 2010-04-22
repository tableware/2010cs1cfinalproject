/*
 * wineryDistance.h
 *
 *  Created on: Apr 18, 2010
 *      Author: absynth
 */

#ifndef WINERYDISTANCE_H_
#define WINERYDISTANCE_H_

class WineryDistance
{
	public:
		WineryDistance();
		WineryDistance(int number, float distance);
		~WineryDistance();

		void setNumber(int number);
		int getNumber();

		void setDistance(float distance);
		float getDistance();

	private:
		int number;
		float distance;
};


#endif /* WINERYDISTANCE_H_ */

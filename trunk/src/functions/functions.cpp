/***********************************************************
* AUTHOR: 		Aaron Cruz, Nobel Gibbin, Anthony Stramer
* Project 2:	Wine Tour Project
* CLASS:        CS1C (#13635)
* SECTION:      Projects
* Due Date:     5/6/10
************************************************************/

#include "functions.h"

vector<Winery*> binaryFileRead(string filename)
{
	ifstream binaryFile(filename.c_str(), ios::binary); // filestream  used for loading

	binaryWinery currentWinery;             // used to load a winery from the data file
	binaryWineDistance currentWineDistance; // used to load a winery distance from the data file
	binaryWine currentWine;                 // used to load a wine from the data file

	vector<Winery*> wineries;           // stores all of the loaded information
	Winery* tempWinery;                 // stores a new winery loaded from disk
	Wine* tempWine;                     // stores a new wine loaded from disk
	WineryDistance* tempWineryDistance; // stores a new winery distance loaded from disk

	unsigned int size; // stores the total number of wineries

	// see if the file is open, if not let's just gracefully fail
	if(binaryFile.is_open())
	{
		// let's see how many winery's we have to load in
		binaryFile.read((char*)&size, sizeof(size));

		// grab all of the wineries
		for(unsigned int i = 0; i < size; ++i)
		{
			// read the infomration
			binaryFile.read((char*)&currentWinery, sizeof(currentWinery));

			// load in all of the general winery information
			tempWinery = new Winery;
			tempWinery->setNumber(currentWinery.number);
			tempWinery->setName(currentWinery.name);
			tempWinery->setDistance(currentWinery.distance);

			// load in all of the information about wines
			for(unsigned int wine = 0; wine < currentWinery.wines; ++wine)
			{
				// write the information for the current wine
				binaryFile.read((char*)&currentWine, sizeof(currentWine));

				// transfer all of the wine information
				tempWine = new Wine;
				tempWine->setName(currentWine.name);
				tempWine->setPrice(currentWine.price);
				tempWine->setYear(currentWine.year);

				// add it to the winery
				tempWinery->wineList.push_back(tempWine);
				tempWine = NULL;
			}

			// load in all of the distances
			for(unsigned int distance = 0; distance < currentWinery.distances; ++distance)
			{
				// read the information for the current wineDistance;
				binaryFile.read((char*)&currentWineDistance, sizeof(currentWineDistance));

				// transfer the information over
				tempWineryDistance = new WineryDistance;
				tempWineryDistance->setNumber(currentWineDistance.number);
				tempWineryDistance->setDistance(currentWineDistance.distance);

				// add it to the winery
				tempWinery->distanceList.push_back(tempWineryDistance);
				tempWineryDistance = NULL;
			}

			// add to the main vector
			wineries.push_back(tempWinery);
			tempWinery = NULL;
		}
	}

	binaryFile.close();

	return wineries;
}

void binaryFileWrite(string filename, vector<Winery*> wineries)
{
	ofstream binaryFile(filename.c_str(), ios::binary); // output filestream

	binaryWinery currentWinery;             // used for writing winery data to binary
	binaryWineDistance currentWineDistance; // used for writing wineryDistance data to binary
	binaryWine currentWine;                 // used for writing wine data to binary

	unsigned int size = wineries.size(); // total number of wineries to output

	// write down how many wineries we have
	binaryFile.write((char*)&size, sizeof(size));

	// loop through all of the wineries that we need to output
	for(unsigned int winery = 0; winery < wineries.size(); ++winery)
	{
		// load the information into the holder
		currentWinery.number    = wineries[winery]->getNumber();
		currentWinery.distances = wineries[winery]->distanceList.size();
		currentWinery.wines     = wineries[winery]->wineList.size();
		currentWinery.distance  = wineries[winery]->getDistance();

		strncpy(currentWinery.name, wineries[winery]->getName().c_str(), strlen(wineries[winery]->getName().c_str()));
		currentWinery.name[wineries[winery]->getName().size()] = 0;


		// write the information for the current winery
		binaryFile.write((char*)&currentWinery, sizeof(currentWinery));

		// loop through all of the wines
		for(unsigned int wine = 0; wine < currentWinery.wines; ++wine)
		{
			// load the information into the holder
			strncpy(currentWine.name, wineries[winery]->wineList[wine]->getName().c_str(), strlen(wineries[winery]->wineList[wine]->getName().c_str()));
			currentWine.name[wineries[winery]->wineList[wine]->getName().size()] = 0;

			currentWine.price = wineries[winery]->wineList[wine]->getPrice();
			currentWine.year  = wineries[winery]->wineList[wine]->getYear();

			// write the information for the current wine
			binaryFile.write((char*)&currentWine, sizeof(currentWine));
		}

		// loop through all of the wine distances
		for(unsigned int distance = 0; distance < currentWinery.distances; ++distance)
		{
			// load the infomration into the holder
			currentWineDistance.number   = wineries[winery]->distanceList[distance]->getNumber();
			currentWineDistance.distance = wineries[winery]->distanceList[distance]->getDistance();

			// write the information for the current wineDistance;
			binaryFile.write((char*)&currentWineDistance, sizeof(currentWineDistance));
		}
	}

	binaryFile.close();
}

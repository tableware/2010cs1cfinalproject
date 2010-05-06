/*
 * functions.cpp
 *
 *  Created on: Apr 12, 2010
 *      Author: jgibbins1
 */

#include "../header.h"

vector<Winery*> binaryFileRead(string filename)
{
	ifstream binaryFile(filename.c_str(), ios::binary);

	binaryWinery currentWinery;
	binaryWineDistance currentWineDistance;
	binaryWine currentWine;

	vector<Winery*> wineries;
	Winery* tempWinery;
	Wine* tempWine;
	WineryDistance* tempWineryDistance;

	unsigned int size;

	if(binaryFile.is_open())
	{
		binaryFile.read((char*)&size, sizeof(size));

		for(unsigned int i = 0; i < size; ++i)
		{
			// read the infomration
			binaryFile.read((char*)&currentWinery, sizeof(currentWinery));

			tempWinery = new Winery;
			tempWinery->setNumber(currentWinery.number);
			tempWinery->setName(currentWinery.name);

			//cout << "[winery: " << currentWinery.number << "] " << currentWinery.name << endl;
			for(unsigned int wine = 0; wine < currentWinery.wines; ++wine)
			{
				// write the information for the current wine
				binaryFile.read((char*)&currentWine, sizeof(currentWine));

				//cout << "  [Wine]\n";
				//cout << "  + " << currentWine.name << endl;
				//cout << "  + " << currentWine.price << endl;
				//cout << "  + " << currentWine.year << endl;

				tempWine = new Wine;
				tempWine->setName(currentWine.name);
				tempWine->setPrice(currentWine.price);
				tempWine->setYear(currentWine.year);

				tempWinery->wineList.push_back(tempWine);
				tempWine = NULL;
			}

			for(unsigned int distance = 0; distance < currentWinery.distances; ++distance)
			{
				// write the information for the current wineDistance;
				binaryFile.read((char*)&currentWineDistance, sizeof(currentWineDistance));

				//cout << "  [Distance]\n";
				//cout << "  + " << currentWineDistance.number << endl;
				//cout << "  + " << currentWineDistance.distance << endl;
				tempWineryDistance = new WineryDistance;
				tempWineryDistance->setNumber(currentWineDistance.number);
				tempWineryDistance->setDistance(currentWineDistance.distance);

				tempWinery->distanceList.push_back(tempWineryDistance);
				tempWineryDistance = NULL;
			}

			wineries.push_back(tempWinery);
			tempWinery = NULL;
		}
	}

	binaryFile.close();

	return wineries;
}

void binaryFileWrite(string filename, vector<Winery*> wineries)
{
	ofstream binaryFile(filename.c_str(), ios::binary);
	binaryWinery currentWinery;
	binaryWineDistance currentWineDistance;
	binaryWine currentWine;
	unsigned int size = wineries.size();

	// write down how many wineries we have
	binaryFile.write((char*)&size, sizeof(size));

	for(unsigned int winery = 0; winery < wineries.size(); ++winery)
	{
		// load the information
		currentWinery.number    = wineries[winery]->getNumber();
		strncpy(currentWinery.name, wineries[winery]->getName().c_str(), strlen(wineries[winery]->getName().c_str()));
		currentWinery.distances = wineries[winery]->distanceList.size();
		currentWinery.wines     = wineries[winery]->wineList.size();

		// write the information for the current winery
		binaryFile.write((char*)&currentWinery, sizeof(currentWinery));

		for(unsigned int wine = 0; wine < currentWinery.wines; ++wine)
		{
			strncpy(currentWine.name, wineries[winery]->wineList[wine]->getName().c_str(), strlen(wineries[winery]->wineList[wine]->getName().c_str()));
			currentWine.price = wineries[winery]->wineList[wine]->getPrice();
			currentWine.year  = wineries[winery]->wineList[wine]->getYear();

			// write the information for the current wine
			binaryFile.write((char*)&currentWine, sizeof(currentWine));
		}

		for(unsigned int distance = 0; distance < currentWinery.distances; ++distance)
		{
			currentWineDistance.number   = wineries[winery]->distanceList[distance]->getNumber();
			currentWineDistance.distance = wineries[winery]->distanceList[distance]->getDistance();

			// write the information for the current wineDistance;
			binaryFile.write((char*)&currentWineDistance, sizeof(currentWineDistance));
		}
	}

	binaryFile.close();
}
/*void binaryFileRead(string filename, vector<Winery*> wineries)
{
	fstream binaryFile;

	int wineryNumber;
	string wineryName;
	unsigned int wineryNameSize;

	unsigned int distances;
	int distanceWineryNumber;
	float distanceDistance;

	unsigned int wines;
	char* wineName;
	float winePrice;
	int wineYear;

	binaryFile.open(filename.c_str(), ios::in | ios::binary);


	char letter;
	// loop through all of the wineries
	while(binaryFile.peek())
	{
		binaryFile.read((char*)&wineryNumber, sizeof(wineryNumber));
		binaryFile.read((char*)&wineryNameSize, sizeof(wineryNameSize));

		for(unsigned int nameSize = letter; nameSize > 0; --nameSize)
		{
			binaryFile.read((char*)&letter, sizeof(letter));
			cout << letter;
		}

		cout << wineryNumber << "|" << wineryName << "|" << wineryNameSize << endl;

		break;
//		// number of distances that we will write
//		binaryFile.read((char*)&distances, sizeof(distances));
//		cout << "[dist]" << distances << endl;
//
//		for(unsigned int wineryDistance = 0;
//			wineryDistance < distances;
//			++wineryDistance)
//		{
//			binaryFile.read((char*)&distanceWineryNumber, sizeof(distanceWineryNumber));
//			binaryFile.read((char*)&distanceDistance, sizeof(distanceDistance));
//			cout << distanceWineryNumber << " " << distanceDistance << endl;
//
//		}
//
//
//		binaryFile.write((char*)&wines, sizeof(wines));
//		cout << "[wines]" << wines << endl;
//
//		// number of wines
//		for(unsigned int wine = 0; wine < wines; ++wine)
//		{
//			//wineName = new char[wineries[winery]->wineList[wine]->getName().length()];
//			strcpy(wineName, wineries[winery]->wineList[wine]->getName().c_str());
//			winePrice = wineries[winery]->wineList[wine]->getPrice();
//			wineYear = wineries[winery]->wineList[wine]->getYear();
//
//			cout << sizeof(wineName) << wineName << " " << winePrice << " " << wineYear << endl;
//		}
	}

	// write out the number of wineries


	binaryFile.close();
}*/

/*void binaryFileWrite(string filename, vector<Winery*> wineries)
{
	fstream binaryFile;

	int wineryNumber;
	char* wineryName;
	unsigned int wineryNameSize;

	unsigned int distances;
	int distanceWineryNumber;
	float distanceDistance;

	unsigned int wines;
	char* wineName;
	float winePrice;
	int wineYear;

	//unsigned int numberOfWineries;
	//numberOfWineries = wineries.size();


	*
	 * int numOfWines;
		int number;
		string name;
		bool visited;

	binaryFile.open(filename.c_str(), ios::out | ios::binary);

	//cout << wineries.size() << endl;

	// loop through all of the wineries
	for(unsigned int winery = 0; winery < wineries.size(); ++winery)
	{
		wineryNumber   = wineries[winery]->getNumber();

		wineryName = new char[wineries[winery]->getName().length()];
		strcpy(wineryName, wineries[winery]->getName().c_str());
		wineryNameSize = wineries[winery]->getName().length();

		cout << wineryNumber << "|" << wineryName << "|" << wineryNameSize << endl;

		binaryFile.write((char*)&wineryNumber, sizeof(wineryNumber));
		binaryFile.write((char*)&wineryNameSize, sizeof(wineryNameSize));
		for(unsigned int i = wineryNameSize; i > 0; --i)
		{
			binaryFile.write((char*)&wineries[winery]->getName().c_str()[i], sizeof(wineries[winery]->getName().c_str()[i]));
		}

		// number of distances that we will write
		distances = wineries[winery]->distanceList.size();

		binaryFile.write((char*)&distances, sizeof(distances));
		cout << "[dist]" << distances << endl;

		for(unsigned int wineryDistance = 0;
		    wineryDistance < distances;
		    ++wineryDistance)
		{
			distanceWineryNumber = wineries[winery]->distanceList[wineryDistance]->getNumber();
			distanceDistance = wineries[winery]->distanceList[wineryDistance]->getDistance();

			cout << distanceWineryNumber << " " << distanceDistance << endl;
			binaryFile.write((char*)&distanceWineryNumber, sizeof(distanceWineryNumber));
			binaryFile.write((char*)&distanceDistance, sizeof(distanceDistance));

		}

		wines = wineries[winery]->wineList.size();

		cout << "[wines]" << wines << endl;
		binaryFile.write((char*)&wines, sizeof(wines));

		// number of wines
		for(unsigned int wine = 0; wine < wines; ++wine)
		{
			wineName = new char[wineries[winery]->wineList[wine]->getName().length()];
			strcpy(wineName, wineries[winery]->wineList[wine]->getName().c_str());
			winePrice = wineries[winery]->wineList[wine]->getPrice();
			wineYear = wineries[winery]->wineList[wine]->getYear();

			cout << sizeof(wineName) << wineName << " " << winePrice << " " << wineYear << endl;
		}
	}

	// write out the number of wineries


	binaryFile.close();
}*/



int returnByteWinery(int val)
{
	return sizeof(Winery) * val;
}

int returnByteWine(int val)
{
	return sizeof(Wine) * val;
}

int returnByteWineryDistance(int val)
{
	return sizeof(WineryDistance) * val;
}

int returnByteArraySize(int val)
{
	char a;
	return sizeof(a) * 50 * val;
}

void createBinaryFile(vector<Winery*> list)
{
	int wineryCount;
	int wineryDistanceCount;
	int wineCount;
	int stringCount;
	//char fileName[35];
	//string fileName;
	vector<Winery*> :: iterator temp;
	fstream dataFile;

	dataFile.open("src/data/data.dat", ios::out|ios::binary);

	wineryCount = 0;
	wineryDistanceCount = 0;
	wineCount = 0;
	stringCount = 0;

	//cout << "Enter location to store file (ex: data.dat): ";
	//cin.getline(fileName, '\n');
	//fileName = "src/data/data.dat";

	cout << "\nCreating binary file...\n";

	for(temp = list.begin( ); temp < list.end( ); temp++)
	{
		writeWinery(temp, wineryCount, wineryDistanceCount, wineCount,
					stringCount, "src/data/data.dat");
	}

	cout << "File created successfully!\n\n";

	dataFile.close();
}

void writeWinery(vector<Winery*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[])
{
	int tempNum;
	char *tempCharArray;
	char realCharArray[50];
	vector<WineryDistance*> :: iterator distLoc;
	vector<Wine*> :: iterator wineLoc;

	fstream wineFile(fName, ios::in | ios::out | ios::binary);
	int numOfWines = (*position)->getNumOfWines();
	float subtotal = (*position)->getSubTotal();
	int number = (*position)->getNumber();
	bool visited = (*position)->getVisited();
	string name = (*position)->getName();
	tempNum = name.length();

	tempCharArray = new char[name.size()+1];
	tempCharArray[name.size()] = 0;
	memcpy(tempCharArray,name.c_str(),name.size());
	strcpy(realCharArray, tempCharArray);


	wineFile.seekp(returnByteWinery(wineryCount)
				   + returnByteWineryDistance(wineryDistanceCount)
				   + returnByteWine(wineCount)
				   + returnByteArraySize(stringCount));

	wineFile.write((char*)&realCharArray,sizeof(realCharArray));
	wineFile.write((char*)&number,sizeof(number));
	wineFile.write((char*)&subtotal,sizeof(subtotal));
	wineFile.write((char*)&visited,sizeof(visited));
	wineFile.write((char*)&numOfWines,sizeof(numOfWines));

	stringCount++;
	wineryCount++;

	for(distLoc = (*position)->distanceList.begin(); distLoc < (*position)->distanceList.end( ); distLoc++)
	{
		writeWineryDistance(distLoc, wineryCount, wineryDistanceCount, wineCount,
					stringCount, fName);
	}

	for(wineLoc = (*position)->wineList.begin(); wineLoc < (*position)->wineList.end( ); wineLoc++)
	{
		writeWine(wineLoc, wineryCount, wineryDistanceCount, wineCount,
				  stringCount, fName);
	}

	wineFile.close();


}

void writeWineryDistance(vector<WineryDistance*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[])
{
	int number;
	float distance;

	number = (*position)->getNumber();
	distance = (*position)->getDistance();

	fstream wineFile(fName, ios::in | ios::out | ios::binary);

	wineFile.seekp(returnByteWinery(wineryCount)
				   + returnByteWineryDistance(wineryDistanceCount)
				   + returnByteWine(wineCount)
				   + returnByteArraySize(stringCount));

	wineFile.write((char*)&number,sizeof(number));
	wineFile.write((char*)&distance,sizeof(distance));

	wineryDistanceCount++;

	wineFile.close();
}

void writeWine(vector<Wine*> :: iterator position, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount,
				 const char fName[])
{
	string name;
	float price;
	int year;
	int quantity;
	char *tempCharArray;
	char realCharArray[50];

	name = (*position)->getName();
	price = (*position)->getPrice();
	year = (*position)->getYear();
	quantity = (*position)->getQuantity();

	tempCharArray = new char[name.size()+1];
	tempCharArray[name.size()] = 0;
	memcpy(tempCharArray,name.c_str(),name.size());
	strcpy(realCharArray, tempCharArray);

	fstream wineFile(fName, ios::in | ios::out | ios::binary);

	wineFile.seekp(returnByteWinery(wineryCount)
				   + returnByteWineryDistance(wineryDistanceCount)
				   + returnByteWine(wineCount)
				   + returnByteArraySize(stringCount));

	wineFile.write((char*)&realCharArray,sizeof(realCharArray));
	wineFile.write((char*)&price,sizeof(price));
	wineFile.write((char*)&year,sizeof(year));
	wineFile.write((char*)&quantity,sizeof(quantity));

	wineCount++;
	stringCount++;

	wineFile.close();
}




vector<Winery*> readBinaryFile()
{
	int wineryCount;
	int wineryDistanceCount;
	int wineCount;
	int stringCount;
	int counter;
	vector<Winery*> tempWineryList;
	Winery* wTemp;
	fstream dataFile;
	char tempCharArray[50];

	float subTotal;
	bool visited;
	int number;
	int numOfWines;
	string name;

	wineryCount = 0;
	wineryDistanceCount = 0;
	wineCount = 0;
	stringCount = 0;
	counter = 0;


	cout << "\nReading from binary file...\n";

	fstream wineFile("src/data/data.dat", ios::in | ios::out | ios::binary);

	while (counter < Winery::numOfWineries)
	{
		wTemp = new Winery;

		wineFile.seekg(returnByteWinery(wineryCount)
					   + returnByteWineryDistance(wineryDistanceCount)
					   + returnByteWine(wineCount)
					   + returnByteArraySize(stringCount));

		wineFile.read((char*)&tempCharArray,sizeof(tempCharArray));
		wineFile.read((char*)&number,sizeof(number));
		wineFile.read((char*)&subTotal,sizeof(subTotal));
		wineFile.read((char*)&visited,sizeof(visited));
		wineFile.read((char*)&numOfWines,sizeof(numOfWines));

		name = tempCharArray;

		wTemp->setName(name);
		wTemp->setNumber(number);
		wTemp->setSubTotal(subTotal);
		wTemp->setVisited(visited);
		wTemp->setNumOfWines(numOfWines);

		stringCount++;
		wineryCount++;

		readWineryDistance(wTemp, Winery::numOfWineries, wineryCount,
						   wineryDistanceCount, wineCount, stringCount);

		readWines(wTemp, numOfWines, wineryCount, wineryDistanceCount,
				  wineCount, stringCount);

		tempWineryList.push_back(wTemp);

		counter++;
	}

	cout << "File read successfully!\n\n";

	wineFile.close();

	return tempWineryList;
}

void readWineryDistance( Winery*& wTemp, int numOfWineries, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount)
{
	int number;
	float distance;
	int count;
	WineryDistance* dTemp;

	count = 0;

	fstream wineFile("src/data/data.dat", ios::in | ios::out | ios::binary);

	while (count < numOfWineries)
	{
		dTemp = new WineryDistance;

		wineFile.seekg(returnByteWinery(wineryCount)
					   + returnByteWineryDistance(wineryDistanceCount)
					   + returnByteWine(wineCount)
					   + returnByteArraySize(stringCount));

		wineFile.read((char*)&number,sizeof(number));
		wineFile.read((char*)&distance,sizeof(distance));

		dTemp->setNumber(number);
		dTemp->setDistance(distance);

		wTemp->distanceList.push_back(dTemp);

		wineryDistanceCount++;

		count++;

	}
	wineFile.close();

}


void readWines( Winery*& wTemp, int numOfWines, int& wineryCount,
				 int& wineryDistanceCount, int& wineCount, int& stringCount)
{
	string name;
	float price;
	int year;
	int quantity;
	int count;
	char tempCharArray[50];
	Wine* wineTemp;

	count = 0;

	fstream wineFile("src/data/data.dat", ios::in | ios::out | ios::binary);

	while (count < numOfWines)
	{
		wineTemp = new Wine;

		wineFile.seekg(returnByteWinery(wineryCount)
					   + returnByteWineryDistance(wineryDistanceCount)
					   + returnByteWine(wineCount)
					   + returnByteArraySize(stringCount));

		wineFile.read((char*)&tempCharArray,sizeof(tempCharArray));
		wineFile.read((char*)&price,sizeof(price));
		wineFile.read((char*)&year,sizeof(year));
		wineFile.read((char*)&quantity,sizeof(quantity));

		name = tempCharArray;

		wineTemp->setName(name);
		wineTemp->setPrice(price);
		wineTemp->setYear(year);
		wineTemp->setQuantity(quantity);

		wTemp->wineList.push_back(wineTemp);

		stringCount++;
		wineCount++;

		count++;

	}
	wineFile.close();
}

/*
 * functions.cpp
 *
 *  Created on: Apr 12, 2010
 *      Author: jgibbins1
 */

#include "../header.h"

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

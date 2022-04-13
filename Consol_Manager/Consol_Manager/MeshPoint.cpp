#pragma once
#include "MeshPoint.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>



PointGps* angleDictionary(int inAngele, double _latDeltaIn, double _longDeltaIn)

{
	int inAngelChange = 0;
	int latPlusMinus = 0, longPlusMinus = 0;
	
	std::cout << inAngele << "  kont " << std::endl;

	if (inAngele >= 0 && inAngele < 90)
	{
		inAngelChange = inAngele;
		latPlusMinus = 1,
		longPlusMinus = 1;
	}
	else if (inAngele >= 90 && inAngele < 180)
	{
		inAngelChange = 180-inAngele;
		latPlusMinus = -1,
		longPlusMinus = 1;

	}
	else if (inAngele >= 180 && inAngele < 270)
	{
		inAngelChange = inAngele - 180;
		latPlusMinus = -1,
		longPlusMinus = -1;


	}
	else if (inAngele >= 270 && inAngele <= 360)
	{
		inAngelChange = 360-inAngele;
		latPlusMinus = 1,
		longPlusMinus = -1;

	}
	
	double OutAngle=0;
	int positionTab = 0;
	int tab[19] = { 90,82,74,66,59,52,46,41,36,31,27,23,19,16,12,9,6,3,0 };

	for (int i = 0; i < 20; i++)
	{
		if (tab[i] < inAngelChange)
		{
			positionTab = i - 1;
			break;
		}
	}
	int angelTab = (int)tab[positionTab];

	if (angelTab == inAngelChange)
	{
		OutAngle = (double)(positionTab * 5);
	}
	else
	{
		double distanceAngelTab = (double)tab[positionTab] - tab[positionTab + 1];
		double distanceAngel = (double)tab[positionTab] - inAngelChange;
		OutAngle = (positionTab * 5) + ((5 / distanceAngelTab) * distanceAngel);
	}



	double _latDeltaOut;
	double _longDeltaOut;

	
	int  _alfaGradualAngular = (int)OutAngle;

	
	if (_alfaGradualAngular == 0)
	{
		_latDeltaOut= 0;
		_longDeltaOut = _longDeltaIn;
	}
	else if (_alfaGradualAngular == 90)
	{
		_latDeltaOut = _latDeltaIn;
		_longDeltaOut = 0;
	}
	else
	{
		double tangAlfa = tan((double)((_alfaGradualAngular * 3.14159265) / 180.0));
		_latDeltaOut = ((_latDeltaIn * _longDeltaIn) / (sqrt((_longDeltaIn * _longDeltaIn) + ((_latDeltaIn * _latDeltaIn) / (tangAlfa * tangAlfa)))));
		_longDeltaOut = ((_latDeltaIn * _longDeltaIn) / (sqrt((_latDeltaIn * _latDeltaIn) + ((_longDeltaIn * _longDeltaIn) * (tangAlfa * tangAlfa)))));
	}




	_latDeltaOut /= (double)latPlusMinus;
	_longDeltaOut /= (double)longPlusMinus;

	
	PointGps* pointDirection = new PointGps(_latDeltaOut, _longDeltaOut);
	return pointDirection;
}




void findMaxMin(std::vector <PointGps*>& _vector_pt)
{

	int sizeVect = _vector_pt.size();
	double maxLatPGps = _vector_pt[0]->latPGps;
	double minLatPGps = _vector_pt[0]->latPGps;

	double maxLongPGps = _vector_pt[0]->longPGps;
	double minLongPGps = _vector_pt[0]->longPGps;

	double tempLat, tempLong;

	for (int i = 0; i < sizeVect; i++)
	{
		tempLat = _vector_pt[i]->latPGps;
		tempLong = _vector_pt[i]->longPGps;

		if (tempLat < minLatPGps) { minLatPGps = tempLat; }
		if (tempLat > maxLatPGps) { maxLatPGps = tempLat; }
		if (tempLong > maxLongPGps) { maxLongPGps = tempLong; }
		if (tempLong < minLongPGps) { minLongPGps = tempLong; }
	}

	/*
	std::cout << "             max" << std::endl;
	std::cout << maxLatPGps << "max    lat   min" << minLatPGps << std::endl;
	std::cout << maxLongPGps << "max  long   min" << minLongPGps << std::endl;
	std::cout << "   -------" << std::endl;
	*/

	_vector_pt.clear();

	PointGps* pq0Min = new PointGps(minLatPGps, minLongPGps);
	PointGps* pq1Max = new PointGps(maxLatPGps, maxLongPGps);

	_vector_pt.push_back(pq0Min);
	_vector_pt.push_back(pq1Max);

}







MeshPoint::MeshPoint(int _square) 
	:PointGps()
{
	
	square = _square;

	nameField = "field-1";
	PointGps* pppl = new PointGps(1, 2);  //where sh0uld be destructor??
	vector_pt.push_back(pppl);

}

MeshPoint::~MeshPoint()
{


}

void MeshPoint::PrintVector()
{
	int sizeVector = vector_pt.size();

	for (int i = 0; i < sizeVector; i++)
	{
		std::cout << vector_pt[i]->latPGps << "      ";
		std::cout << vector_pt[i]->longPGps << std::endl;
	}

}

void MeshPoint::LoadPoint()
{
	vector_pt.clear();


	PointGps* pq1 = new PointGps(53.00, 17.000);
	PointGps* pq2 = new PointGps(53.18462, 17.69525);
	PointGps* pq3 = new PointGps(53.26357, 17.31330);
	PointGps* pq4 = new PointGps(53.30925, 17.124457);
	PointGps* pq5 = new PointGps(53.4308, 17.77893);
	PointGps* pq6 = new PointGps(53.12007, 17.4723);
	PointGps* pq7 = new PointGps(53.3134, 17.68452);
	PointGps* pq8 = new PointGps(53.6788, 17.137331);
	PointGps* pq9 = new PointGps(53.2216, 17.72744);
	PointGps* pq10 = new PointGps(53.12264, 17.71242);
	PointGps* pq11 = new PointGps(53.181529, 17.92658);


	vector_pt.clear();
	vector_pt.push_back(pq1);
	vector_pt.push_back(pq2);
	vector_pt.push_back(pq3);
	vector_pt.push_back(pq4);
	vector_pt.push_back(pq5);
	vector_pt.push_back(pq5);
	vector_pt.push_back(pq7);
	vector_pt.push_back(pq8);
	vector_pt.push_back(pq9);
	vector_pt.push_back(pq10);
	vector_pt.push_back(pq11);

}

void MeshPoint::FillPoint(int _alfaGradualAngular)
{
	double  latDelta = 0.0000901;  //a
	double longDelta = 0.00014907;   //b

	auto ttt = vector_pt;
	

	

	


	findMaxMin(vector_pt);


	std::cout << vector_pt[0]->latPGps << "  min    " << vector_pt[0]->longPGps << std::endl;
	std::cout << vector_pt[1]->latPGps << " max    " << vector_pt[1]->longPGps << std::endl;
	/////////////////////////////////////////////////////

	PointGps* pointDirection = angleDictionary(_alfaGradualAngular, latDelta, longDelta);
	std::cout << pointDirection->latPGps << " :lat   long: " << pointDirection->longPGps << std::endl;
	double longDelta10m = pointDirection->longPGps;
	double latDelta10m = pointDirection->latPGps;


	double latDeltaTemp = vector_pt[0]->latPGps;
	double longDeltaTemp = vector_pt[0]->longPGps;

	for (int i = 1; i < 10; i++)
	{
		longDeltaTemp = longDeltaTemp + longDelta10m;
		latDeltaTemp = latDeltaTemp + latDelta10m;

		PointGps* pintTemp = new PointGps(latDeltaTemp, longDeltaTemp);
		vector_pt.push_back(pintTemp);
	}



	for (int j = 0; j < 40; j++)
	{
		_alfaGradualAngular = _alfaGradualAngular + 2;

		PointGps* pointDirection2 = angleDictionary(_alfaGradualAngular, latDelta, longDelta);
		double longDelta10m2 = pointDirection2->longPGps;
		double latDelta10m2 = pointDirection2->latPGps;




		for (int i = 1; i < 5; i++)
		{
			longDeltaTemp = longDeltaTemp + longDelta10m2;
			latDeltaTemp = latDeltaTemp + latDelta10m2;

			PointGps* pintTemp2 = new PointGps(latDeltaTemp, longDeltaTemp);
			vector_pt.push_back(pintTemp2);
		}



	}









}


void MeshPoint::SaveToFile()
{
	int maxSizeFile = 1000;
	int vecSize = vector_pt.size();
	int lineNumberFile = 0;




	std::string adress0 = "C:\\Dane\\5_Programowanie\\Program_manage\\OUT\\ff\\0_test.waypoints";
	std::string fileName = "_test.waypoints";
	int fileNumber = 0;
	std::string adress = "C:\\Dane\\5_Programowanie\\Program_manage\\OUT\\ff\\";

	std::fstream plik;
	plik.open(adress0,  std::ios::out);   //| std::ios::app std::ios::out|| std::ios::app
	plik << "QGC WPL 110" << std::endl;

	for (int kkk = 0; kkk < vecSize; kkk++)
	{



		if (lineNumberFile >= maxSizeFile)
		{
			plik.close();
			fileNumber++;
			lineNumberFile = 0;

			std::string fil_numerS = std::to_string(fileNumber);
			std::string adressT = adress + fil_numerS + fileName;
			std::cout << adress << std::endl;
			plik.open(adressT, std::ios::out);

			plik << "QGC WPL 110" << std::endl;
		}


		double longTemp = (((double)(vector_pt[kkk]->longPGps)));
		double latTemp = (((double)(vector_pt[kkk]->latPGps)));



		plik << lineNumberFile << " 	0	3	16	0.00000000	0.00000000	0.00000000	0.00000000	 ";
		plik << std::setprecision(12) << latTemp;
		plik << " ";
		plik << std::setprecision(12) << longTemp;
		plik << "	30.000000	1" << std::endl;
		///plik << std::endl;
		lineNumberFile++;
	}

	plik.close();

}



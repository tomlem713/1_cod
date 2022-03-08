#pragma once
#include "MeshPoint.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>






MeshPoint::MeshPoint()
:PointGps()
{
	nameField = "field-1";
	PointGps* pppl = new PointGps(11.1111111, 2.2222222222);  //where sh0uld be destructor??
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
		std::cout << std::setprecision(15) << vector_pt[i]->latPGps << "      ";
		std::cout << std::setprecision(15) << vector_pt[i]->longPGps << std::endl;
	}

}

void MeshPoint::LoadPoint()
{
	
	PointGps* pq1 = new PointGps(52.545904, 17.545531);
	PointGps* pq2 = new PointGps(52.54405780, 17.53857850);
	PointGps* pq3 = new PointGps(52.54326830, 17.54239800);
	PointGps* pq4 = new PointGps(52.54281150, 17.53308530);
	PointGps* pq5 = new PointGps(52.54633480, 17.53774170);
	PointGps* pq6 = new PointGps(52.54710470, 17.54505870);
	PointGps* pq7 = new PointGps(52.54621740, 17.53868580);
	PointGps* pq8 = new PointGps(52.54658280, 17.53179790);
	PointGps* pq9 = new PointGps(52.54568240, 17.53825660);
	PointGps* pq10= new PointGps(52.54467760, 17.53840680);
	PointGps* pq11 = new PointGps(52.54375110, 17.53926520);

		/*
1	52.545904,	17.545531
2	52.54405780,	17.53857850
3	52.54326830,	17.54239800
4	52.54281150,	17.53308530
5	52.54633480	,17.53774170
6	52.54710470 ,	17.54505870
7	52.54621740	 , 17.53868580
8	52.54658280	 , 17.53179790
9	52.54568240	, 17.53825660
10	52.54467760 ,	17.53840680
11	52.54375110	 , 17.53926520

		*/
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
	
	int alfaGradualAngular;
	alfaGradualAngular = _alfaGradualAngular;

	float a = 0.0014811;
	float b = 0.0009;

	std::cout << std::setprecision(15) << alfaGradualAngular  << std::endl;

	float Pi_m = 3.14159265;
	float alfaGrad = ((alfaGradualAngular * Pi_m) / 180);
	float tangAlfa = tan(alfaGrad);



	float x = ((a * b) / (sqrt(b * b + ((a * a) / (tangAlfa * tangAlfa)))));
	float y = ((a * b) / (sqrt(a * a + ((b * b) / (tangAlfa * tangAlfa)))));

	std::cout << std::setprecision(15)  << x <<"   -x  " << std::endl;
	std::cout << std::setprecision(15) <<  y << "   -y  " << std::endl;

	/// <summary>

	int sizeVect = vector_pt.size();
	float maxLatPGps = vector_pt[0]->latPGps; 
	float minLatPGps = vector_pt[0]->latPGps;

	float maxLongPGps = vector_pt[0]->longPGps; 
	float minLongPGps = vector_pt[0]->longPGps;

	float tempLat, tempLong;

	for (int i = 0; i < sizeVect; i++)
	{

		tempLat = vector_pt[i]->latPGps;
		tempLong = vector_pt[i]->longPGps;

		if (tempLat < minLatPGps)
		{
			minLatPGps = tempLat;
		}

		if (tempLat > maxLatPGps)
		{
			maxLatPGps = tempLat;
		}

		if (tempLong > maxLongPGps)
		{
			maxLongPGps = tempLong;
		}
		if (tempLong < minLongPGps)
		{
			minLongPGps = tempLong;
		}
	}


	std::cout  << "             max" << std::endl;
	std::cout << std::setprecision(15) << maxLatPGps << "max    lat   min" << minLatPGps << std::endl;
	std::cout << std::setprecision(15) << maxLongPGps << "max  long   min" << minLongPGps << std:: endl;
	std::cout << "   -------" << std::endl;


//wype³naie  do poprawy !!


	float minLongPGpsT = minLongPGps;
	
	while (minLatPGps < maxLatPGps)
	{
		
		minLongPGps = minLongPGpsT;
		
		while (minLongPGps < maxLongPGps)
		{
			minLongPGps=minLongPGps + x;

			PointGps* pintTemp = new PointGps(minLatPGps, minLongPGps);
			vector_pt.push_back(pintTemp);
		}
		
		minLatPGps = minLatPGps + y;

		


	}



}


void MeshPoint::SaveToFile()
{
	int maxSizeFile = 1000;
	int vecSize = vector_pt.size();
	int lineNumberFile = 0;

	std::string adress0 = "C:\\Dane\\5_Programowanie\\Program_manage\\OUT\\0_test.waypoints";

	std::string fileName = "_test.waypoints";
	int fileNumber= 0;
	std::string adress = "C:\\Dane\\5_Programowanie\\Program_manage\\OUT\\";
	
	std::fstream plik;
	plik.open(adress0, std::ios::out);   //| std::ios::app
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
					
			plik << lineNumberFile << " 	0	3	16	0.00000000	0.00000000	0.00000000	0.00000000	 ";
			plik << std::setprecision(15)<<vector_pt[kkk]->latPGps; // ustawienie dok³adnosci na wyjsciu
			plik << "  ";
			plik << std::setprecision(15)<<vector_pt[kkk]->longPGps;
			plik << "	30.000000	1" << std::endl;
			lineNumberFile++;
	}

	plik.close();
}




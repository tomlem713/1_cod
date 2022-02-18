#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include "testGPS.h"

using namespace std;


std :: string longMax, longMin, latMax, latMin;
int  longMax_i, longMin_i, latMax_i, latMin_i;
int deltaLong, deltaLat;



////////////////
int main()
{
int qDividing=10;
int maxSizeFile=500;
std ::string fileName="_test.waypoints";

int lineMumberFile=0;
int fil_numer=1;
std :: string adress= "C:\\Dane\\5_Programowanie\\Program_manage\\1_cod\\Fil_Out\\1_test.waypoints";


longMax = "22.9614258";
longMin = "13.7768555";

latMax="55.1788677";
latMin="50.5553250";



longMax_i=gps_toInt(longMax);
longMin_i=gps_toInt(longMin);
latMax_i=gps_toInt(latMax);
latMin_i=gps_toInt(latMin);



int deltaLong= longMax_i-longMin_i;
int deltaLat=latMax_i-latMin_i;

int piece_deltaLong=deltaLong/qDividing;
int piece_deltaLat=deltaLat/qDividing;




fstream plik;
plik.open(adress, ios::out | ios::app);
plik <<"QGC WPL 110"<<endl;



for ( int kkk=0; kkk<qDividing;  kkk++)

{

    for ( int lll=0; lll<qDividing;  lll++)
    {

       if (lineMumberFile>=maxSizeFile)
       {
         plik.close();
         fil_numer++;
         lineMumberFile=0;
         adress=iterateFileName(adress,fil_numer ,fileName );
         cout <<adress<<endl;
         plik.open(adress, ios::out | ios::app);
         plik <<"QGC WPL 110"<<endl;
       }



     int ggLong=longMin_i+kkk*piece_deltaLong;
     int ggLat=latMin_i+lll*piece_deltaLat;


        plik << lineMumberFile<<" 	0	3	16	0.00000000	0.00000000	0.00000000	0.00000000	 ";
        plik << int_toGPS(ggLat )<<"  ";
        plik << int_toGPS(ggLong )<<"	30.000000	1"<<endl;

    lineMumberFile++;

    }
}

plik.close();


cout <<"----------------"<<endl;




}


#include <iostream>
#include<vector>
using namespace std;


#include "meshPoint.h"

meshPoint::meshPoint()
:LUW()
{
    pointGPS pp(0, 0);
    vector_pt.push_back(pp);

    //ctor
}

meshPoint::~meshPoint()
{
    //dtor
}


void meshPoint::printVector ( )
{

    int sizeVect=vector_pt.size();

    for (int i=0; i<sizeVect; i++ )
    {
        cout << vector_pt[i].getLatPGps()<<"   ";
        cout << vector_pt[i].getLongPGps()<<endl;

    }
}


vector <pointGPS> meshPoint::findMax ( )
{

    int sizeVect=vector_pt.size();
    int maxLatPGps=0, minLatPGps=0;
    int maxLongPGps=0, minLongPGps=0;

    int tempLat, tempLong;

    for (int i=0; i<sizeVect; i++ )
    {

        tempLat=vector_pt[i].getLatPGps();
        tempLong=vector_pt[i].getLongPGps();

       if (tempLat<minLatPGps )
       {
           minLatPGps=tempLat;
       }

       if (tempLat>maxLatPGps)
        {
            maxLatPGps=tempLat;
        }

        if (tempLong>maxLongPGps)
        {
            maxLongPGps=tempLong;
        }
         if (tempLong<minLongPGps)
        {
            minLongPGps=tempLong;
        }
    }


    cout<<"             max"<<endl;
    cout<<maxLatPGps<<"max    lat   min"<<minLatPGps<<endl;
    cout<<maxLongPGps<<"max  long   min"<<minLongPGps<<endl;
    cout<<"   -------"<<endl;

vector <pointGPS> vector_maxff ;

pointGPS maxx(maxLatPGps, maxLongPGps);
pointGPS minn(minLatPGps, minLongPGps  );

vector_maxff.push_back(maxx);
vector_maxff.push_back(minn);



return vector_maxff;
}


void meshPoint::loadPoint()
{

    pointGPS pq1( -18462,69525);
pointGPS pq2( -26357,	-31330);
pointGPS pq3( -30925,	-124457);
pointGPS pq4( 4308,	-77893);
pointGPS pq5( 12007,	-4723);
pointGPS pq6(3134,	-68452);
pointGPS pq7( 6788,	-137331);
pointGPS pq8( -2216,	-72744);
pointGPS pq9( -12264	,-71242);
pointGPS pq10(-21529,	-62658);

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


}





void meshPoint::loadFromVectorMax(vector <pointGPS> &vec_temp )
{

pointGPS pqM0(vec_temp[0].getLatPGps(),vec_temp[0].getLongPGps() );
pointGPS pqM1(vec_temp[1].getLatPGps(),vec_temp[1].getLongPGps() );

vector_pt.push_back(pqM0);
vector_pt.push_back(pqM1);

}

void meshPoint::gridMesh()
{



}






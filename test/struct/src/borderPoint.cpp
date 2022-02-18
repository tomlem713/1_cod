#include "borderPoint.h"
#include <vector>
#include <iostream>


borderPoint::borderPoint(string _nameField, string _latReference , string _longReference, int _ratioToInt, int  _square)
//:pointGPS( 22, 33  )

{
    nameField =_nameField;
    latReference=_latReference;
    longReference=_longReference;
    ratioToInt=_ratioToInt;
    square=_square;

    pointGPS nn;
    vector_pt.push_back(nn);

}

borderPoint::~borderPoint()
{
    //dtor
}


void borderPoint::print()const
{
    pointGPS::printPointGPS();

    cout<<nameField <<endl;

    cout<<latReference<< " lat" <<endl;
    cout<< longReference<<" long"<<endl;
    cout<<ratioToInt<<" ratioToInt"<<endl;
    cout<<square<<" square"<<endl;
}


void borderPoint::printVector (const borderPoint& rhs  )const
{

    int sizeVect=rhs.vector_pt.size();

    for (int i=0; i<sizeVect; i++ )
    {
        cout << rhs.vector_pt[i].getLatPGps()<<"   ";
        cout << rhs.vector_pt[i].getLongPGps()<<endl;

    }
}


void borderPoint::findMax (const borderPoint& rhs  )const
{

    int sizeVect=rhs.vector_pt.size();
    int maxLatPGps=0, minLatPGps=0;
    int maxLongPGps=0, minLongPGps=0;

    int tempLat, tempLong;

    for (int i=0; i<sizeVect; i++ )
    {

        tempLat=rhs.vector_pt[i].getLatPGps();
        tempLong=rhs.vector_pt[i].getLongPGps();

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


borderPoint MaxMin;

MaxMin=rhs;
MaxMin.vector_pt.clear();
pointGPS Pmax(maxLatPGps,maxLongPGps );
pointGPS Pmin(minLatPGps,minLongPGps );

MaxMin.vector_pt.push_back(Pmax);
MaxMin.vector_pt.push_back(Pmin);


}




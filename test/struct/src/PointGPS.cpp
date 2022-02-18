#include "pointGPS.h"

#include <iostream>
using namespace std;


pointGPS::pointGPS(int _latPGps, int _longPGps  )
{
    latPGps=_latPGps;
    longPGps=_longPGps;
};

pointGPS::~pointGPS()
{
    //dtor
}


int pointGPS::getLatPGps()const
{
    return latPGps;
}


int pointGPS::getLongPGps()const
{
  return longPGps;
}




void pointGPS::setLatPGps(int _latPGps)
{
    latPGps=_latPGps;
}

void pointGPS::setLongPGps(int _longPGps)
{
    longPGps=_longPGps;
}


void pointGPS::printPointGPS()const
{
    cout <<latPGps<<" latPGps "<<endl;
    cout<<longPGps<<" longPGps "<<endl;

}

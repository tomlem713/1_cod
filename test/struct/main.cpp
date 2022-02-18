#include <iostream>
#include <vector>

#include "pointGPS.h"
#include "borderPoint.h"



using namespace std;

void loadData(const borderPoint&_border );


int main()
{
/// point
pointGPS pp1;
pointGPS pp2(22,33);
pointGPS pp3;

//cout<< pp3.getLatPGps()<<"   "<<pp3.getLongPGps()<<endl;
pp3.setLatPGps(133);
pp3.setLongPGps(111);
//cout<< pp3.getLatPGps()<<"   "<<pp3.getLongPGps()<<endl;

///mesh Point

borderPoint border;

pointGPS pq0( 0,0);//
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

//// mock  - pobierania z pliku

border.vector_pt.push_back(pq1);
border.vector_pt.push_back(pq2);
border.vector_pt.push_back(pq3);
border.vector_pt.push_back(pq4);
border.vector_pt.push_back(pq5);
border.vector_pt.push_back(pq5);
border.vector_pt.push_back(pq7);
border.vector_pt.push_back(pq8);
border.vector_pt.push_back(pq9);
border.vector_pt.push_back(pq10);



border.print();
border.printVector(border);


borderPoint MaxMinP;






  return 0;
}





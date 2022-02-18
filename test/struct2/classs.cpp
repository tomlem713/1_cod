#include <iostream>
#include <vector>
#include "classs.h"

using namespace std;


ptGPS::ptGPS(int _latPGps, int _longPGps  )
{
    latPGps=_latPGps;
    longPGps=_longPGps;
};


void ptGPS::loadPT( )
{
    cin>>latPGps;
    cin>>longPGps;
}


int ptGPS::getLatPGps()const
{
    return latPGps;
}
int ptGPS::getLongPGps()const
{
   return longPGps;
}

void ptGPS::print()
{
    cout <<latPGps<<" lat punktu "<<endl;
    cout << longPGps<< "  long punktu"<<endl;

}

void ptGPS::setPtGPS(int latPg, int longPg)
{
    latPGps=latPg;
    longPGps=longPg;

}



Field::Field (string _nameField, string _latReference , string _longReference,int _sizeArry, int _capacityArry, int  _square, int _ratioToInt )
:ptGPS( 22, 33  )
{
    nameField =_nameField;
    latReference=_latReference;
    longReference=_longReference;
    ratioToInt=_ratioToInt;
    square=_square;
    sizeArry=_sizeArry;
    capacityArry=_capacityArry;

}

void Field::print()
{
    ptGPS::print();
    cout<<nameField <<endl;

    cout<<latReference<< " lat" <<endl;
    cout<< longReference<<" long"<<endl;
    cout<<ratioToInt<<endl;

}


void Field::loadField_gg()
{


ptGPS pq0( 0,0);
ptGPS pq1( -18462,-69525);
ptGPS pq2( -26357,	-31330);
ptGPS pq3( -30925,	-124457);
ptGPS pq4( 4308,	-77893);
ptGPS pq5( 12007,	-4723);
ptGPS pq6(3134,	-68452);
ptGPS pq7( 6788,	-137331);
ptGPS pq8( -2216,	-72744);
ptGPS pq9( -12264	,-71242);
ptGPS pq10(-21529,	-62658);


arryPoint[0]=pq0;
arryPoint[1]=pq1;
arryPoint[2]=pq2;
arryPoint[3]=pq3;
arryPoint[4]=pq4;
arryPoint[5]=pq5;
arryPoint[6]=pq6;
arryPoint[7]=pq7;
arryPoint[8]=pq8;
arryPoint[9]=pq9;
arryPoint[10]=pq10;

cout <<"fff----------"<<endl;
cout <<arryPoint[5].getLatPGps()          <<"   ";
cout <<arryPoint[5].getLongPGps()  <<"   "<<endl;

setSizeArry(10);


};


void Field::setSizeArry(int _sizeArry)
{
   sizeArry=_sizeArry;

}


int Field::getSizeArry()const
{
    return sizeArry;
}




void Field::printArry( )
{

cout <<"fff"<<endl;
cout<<sizeArry<<endl;
getSizeArry();

for (int i=0; i<sizeArry; i++)
{
cout <<arryPoint[i].getLatPGps()          <<"   ";
cout <<arryPoint[i].getLongPGps()  <<" ;: "<< i<<endl;
};


}



/*

void Field::findMax()
{

cout <<vector_pt[1].latPGps<<"    --"<<endl;






}


/*
void findMax (auto   _ptr)
{

cout<<"---------------"  <<endl;
cout <<_ptr.vector_pt[1].latPGps<<"   ";
cout <<_ptr.vector_pt[1].longPGps<<endl;

}
*/



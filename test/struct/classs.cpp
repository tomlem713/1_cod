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



Field::Field (string _nameField, string _latReference , string _longReference, int _ratioToInt, int  _square)
:ptGPS( 22, 33  )
{
    nameField =_nameField;
    latReference=_latReference;
    longReference=_longReference;
    ratioToInt=_ratioToInt;
    square=_square;


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


vector_pt.push_back(pq0);
vector_pt.push_back(pq1);
vector_pt.push_back(pq2);
vector_pt.push_back(pq3);
vector_pt.push_back(pq4);
vector_pt.push_back(pq5);
vector_pt.push_back(pq6);
vector_pt.push_back(pq7);
vector_pt.push_back(pq8);
vector_pt.push_back(pq9);
vector_pt.push_back(pq10);

auto fptrVect=&vector_pt;

};

/*
void Field::printVector( )
{


cout<<"  - size vector"<<endl;

vector_pt[0].print();


/*
for (int i=0; i<Field.sizeVector;i++)
{
cout <<vector_pt[i].latPGps<<"   ";
cout <<vector_pt[i].longPGps<<endl;
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



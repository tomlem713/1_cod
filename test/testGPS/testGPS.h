#include <iostream>
#include <string.h>
#include <fstream>
#include <string>



#ifndef testGPS.h
#define testGPS.h
using namespace std;



int gps_toInt( std ::  string _coordinate );
std :: string  int_toGPS( int _coor );
std :: string iterateFileName (std:: string adresFile, int nameIterator , std::string fileName );

#endif



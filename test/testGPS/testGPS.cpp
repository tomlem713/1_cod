#include <iostream>
#include <string.h>
#include <fstream>
#include <string>



#include "testGPS.h"
using namespace std;


int dodajLiczby( int a, int b )
{
    return( a + b );
}


//////////////////////////////////////////////////////
int gps_toInt( std ::  string _coordinate )
{
string cc2;
int coordinate_i;
int testLength=_coordinate.length();
cc2.append(_coordinate, 0, 2);
cc2.append(_coordinate, 3, testLength);

//cout <<cc2<<endl;

sscanf(cc2.c_str(), "%d" , &coordinate_i );



/*
double num_double = std::stod(_coordinate);
num_double=num_double*10000000;
int coordinate_i=(int) num_double;
*/

return coordinate_i;
}

//////////////////////////////////////////////////////
std :: string  int_toGPS( int _coor )
{
/*

double num_double2=(double)_coor;
//num_double2=num_double2*0,0000001;

//cout << num_double2<<endl;


std :: string cc3=to_string((num_double2*0.0000001));
cout << cc3<<"  --cc"<<endl;

*/



 std :: string coor_str= std::to_string(_coor );
 std :: string cc3;
 int testLength2=coor_str.length();

 cc3.append(coor_str, 0, 2);
 cc3.append(".");
 cc3.append(coor_str, 2, testLength2);

//cout << cc3<<endl;

return cc3;
}

//////////////////////////////////////////////////////
std :: string iterateFileName (std:: string adresFile, int nameIterator , std::string fileName )
{
    int sizeAdresFile= adresFile.size();
    int sizeAdresTitle=adresFile.find_last_of( " \\ "  );
    std :: string nameIterator_str= std:: to_string (nameIterator );


    adresFile=adresFile.erase(sizeAdresTitle+1, sizeAdresFile );
    adresFile=adresFile+nameIterator_str+fileName;

return adresFile;
}



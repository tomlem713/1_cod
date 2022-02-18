#include <iostream>
#include <vector>
#include "classs.h"

using namespace std;



int main()
{
/*
ptGPS pt1(88,88);
pt1.print();

pt1.setPtGPS(111,212);
pt1.print();

pt1.getLatPGps();
pt1.getLongPGps();
*/




Field fi11("pole2","52.5459040","17.5455310");



auto ptr=fi11;

//fi11.print();
ptr.loadField_gg();
cout<<"--------"<<endl;


fi11.printArry();









//ptr.findMax();




  return 0;
}

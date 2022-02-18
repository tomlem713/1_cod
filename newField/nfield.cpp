#include <iostream>
#include <fstream>
#include "nfield.h"
using namespace std;


void openFile ( std::string _fileAdress, std:: string _fileName )
{


std::string adress=_fileAdress+_fileName;

cout <<adress<<"   adress  "<<endl;



fstream file1;

file1.open(adress, ios::out | ios::app);



if(file1.good()==false)
    {
    cout <<"nie udalo sie otworzyc pliku";
    exit(0);
    }

auto * aaa=&file1;


return;
}


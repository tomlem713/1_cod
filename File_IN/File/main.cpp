#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


using namespace std;

std :: string tekstFromFile;
std :: string tekstFromFileAll;
std :: string adresFile="C:\\Dane\\5_Programowanie\\Program_manage\\IN\\Poznan_tets foto_1_LICHI.csv";


/*
void readFile()
{

cout<<"dane z pliku         :"<<endl;

int nr_linii=1;

while (getline(plik, linia))
{
    tekstFromFile=linia;
    cout<<tekstFromFile<<endl;
    nr_linii++;

}

}

*/


int main()
{


string linia;


ifstream plik;
plik.open(adresFile, ios::in);

if (plik.good()==false)
{
    cout<<"plik nie istnieje"<<endl;
    exit(0);
}

//readFile();

cout<<"dane z pliku         :"<<endl;

int nr_linii=1;

while (getline(plik, linia))
{
    tekstFromFile=linia;
    tekstFromFileAll=tekstFromFileAll+linia;
    nr_linii++;

}

cout<<tekstFromFileAll<<endl;


plik.close();



    return 0;
}

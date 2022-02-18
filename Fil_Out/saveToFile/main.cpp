#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

std::string imie, nazwisko;
int nr_tel;


int main()
{

imie ="_____";
nazwisko="hgfddhg";
nr_tel=557;

fstream plik;

/*
plik.open("C:\\Dane\\5_Programowanie\\Program_manage\\IN\\1.txt", ios::out | ios::app  );

plik<<imie<<endl;
plik<<nazwisko<<endl;
plik<<nr_tel<<endl;

plik.close();
*/

/////////-------------

plik.open("C:\\Dane\\5_Programowanie\\Program_manage\\1_cod\\Fil_Out\\1.txt", ios::out);

if (plik.good()==false)
{
    cout<<"plik nie istnieje"<<endl;
    exit(0);
}






plik<<"dane z pliku         :"<<endl;
plik<<imie<<endl;
plik<<nazwisko<<endl;
plik<<nr_tel<<endl;


plik.close();





}

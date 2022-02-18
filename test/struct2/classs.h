#include <iostream>
#include <vector>

using namespace std;



class ptGPS
{
private:
int latPGps;
int longPGps;

public:
ptGPS(int=2,int=3);
void loadPT();
void setPtGPS(int, int);
int getLatPGps()const;
int getLongPGps()const;


void print();
//~ptGPS();
};




class Field: public ptGPS
{
private:
string nameField;
string latReference , longReference ;
int ratioToInt;

public:
    int sizeArry;
    int capacityArry=20;
    ptGPS arryPoint[20];


int square;  // jesli wartośc wyjad poza zakres int to wchodza n nastepny kwadrat lub dalej o wymiarach int





Field(string ="pole1" , string ="5.5459040" , string ="6.5455310", int =0, int=20, int =0,  int =10000000 ) ;


void setSizeArry(int);
int getSizeArry()const;

void print();
void loadField();   /// ładowanie anych z pliku -- dorobie
void loadField_gg();  /// zgotowymi danymi z tesu

void findMax();


void printArry();


};


/// zaobaczy sie czy beda potrzebe
class line :private ptGPS{};
class chain :private line{};






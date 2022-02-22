#include <iostream>
#include<vector>
using namespace std;


#include <pointGPS.h>
#include "meshPoint.h"
#include "LUW.h"




int main()
{

meshPoint mass;
meshPoint grid;

//cout << mass.vector_pt[0].getLatPGps()<<endl;
mass.loadPoint();
mass.printVector();


vector <pointGPS> vector_max ;
vector_max=mass.findMax();

grid.loadFromVectorMax(vector_max);




    return 0;
}

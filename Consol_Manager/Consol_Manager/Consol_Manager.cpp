#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <new>

#include "PointGps.h"
#include "MeshPoint.h"




/*
lat  1    52.5444   North Pólnoc  Y
long 2     17.555   East wschód   X
*/

int main()
{
    std::cout << "Hello World!\n";

    PointGps pppqw(111.1, 222.22);

    std::cout << std::setprecision(15) << pppqw.latPGps <<"  lat"  << std::endl;
    std::cout << std::setprecision(15) << pppqw.longPGps <<" long" << std::endl;


     MeshPoint bord;

    std::cout << bord.nameField << "\n";
   
    bord.LoadPoint();
    bord.PrintVector();
    std::cout << "  ---------" << std::endl;

    int alfaGradualAngular = 45;

    bord.FillPoint(alfaGradualAngular);  // przekazanie konto do metody
    
                                         
                                         // bord.PrintVector();
    std::cout << bord.vector_pt.size() << std::endl;
    //bord.SaveToFile();

    //delete bord; 
    return 0;
}


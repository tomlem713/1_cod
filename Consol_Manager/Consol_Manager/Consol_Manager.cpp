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
    MeshPoint bord;
    std::cout << bord.nameField << "\n";
   
    bord.LoadPoint();
   // bord.PrintVector();
    std::cout << "  ---------" << std::endl;

    int alfaGradualAngular = 10;  //45c totalny balagan

    bord.FillPoint(alfaGradualAngular); 
    
           // ustawianie kolejności granicy tak aby punkty były pokolei
          //przesuwanie geanicy o 1 m do środka                               
                                        
    //std::cout << bord.vector_pt.size() << std::endl;
  /// bord.SaveToFile();

   //delete bord; 
    return 0;
}


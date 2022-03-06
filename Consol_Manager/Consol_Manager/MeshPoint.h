#pragma once
#include "PointGps.h"
#include <string>
#include <vector>


class MeshPoint :
    public PointGps
{
public:
    MeshPoint();
    virtual ~MeshPoint();
    void PrintVector();
    void LoadPoint();
    void FillPoint(int alfaGradualAngular);
    void SaveToFile();


    std::vector <PointGps*> vector_pt;  // vesctor wskaŸników na obiekt!!

//private:
    std::string nameField;


};


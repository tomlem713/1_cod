#ifndef BORDERPOINT_H
#define BORDERPOINT__H

#include <PointGPS.h>

#include <iostream>
#include <vector>
using namespace std;

class borderPoint : public pointGPS
{
    public:
        borderPoint(string ="pole1" , string ="5.5459040" , string ="6.5455310", int =10000000, int =0);
        virtual ~borderPoint();

        void print()const;
        void printVector(const borderPoint& rhs  )const;

        void findMax(const borderPoint& rhs  )const;



        vector <pointGPS> vector_pt ; // zmienic puzniej na private

    protected:

    private:
        string nameField;
        std::string latReference , longReference ;
        int ratioToInt;
        int square;

};

#endif // BORDERPOINT_H

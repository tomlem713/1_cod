#ifndef MESHPOINT_H
#define MESHPOINT_H

#include <PointGPS.h>
#include <LUW.h>

class meshPoint: public pointGPS , public LUW
{
    public:
        meshPoint();
        virtual ~meshPoint();

        void print()const;
        void printVector();
        void loadPoint(); // from file
        void loadFromVectorMax(vector <pointGPS> &vec_temp );
        vector <pointGPS> findMax();

        void gridMesh();


        vector <pointGPS> vector_pt ;

    protected:

    private:
};

#endif // MESHPOINT_H

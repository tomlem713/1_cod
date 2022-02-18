#ifndef POINTGPS_H
#define POINTGPS_H


class pointGPS
{
    public:
        pointGPS(int=0, int=0);


        virtual ~pointGPS();

        int getLatPGps()const;
        int getLongPGps()const;
        void printPointGPS()const;

        void setLatPGps(int);
        void setLongPGps(int);



    private:

    int latPGps;
    int longPGps;

};

#endif // POINTGPS_H

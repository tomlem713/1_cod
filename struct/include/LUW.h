#ifndef LUW_H
#define LUW_H


class LUW
{
    public:
        LUW(string ="pole1" , string ="5.5459040" , string ="6.5455310", int =10000000, int =0);
        virtual ~LUW();

        void print()const;

    protected:

    private:
        string nameField;
        std::string latReference , longReference ;
        int ratioToInt;
        int square;

};

#endif // LUW_H

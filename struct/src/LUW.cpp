#include <iostream>
using namespace std;


#include "LUW.h"

LUW::LUW(string _nameField, string _latReference , string _longReference, int _ratioToInt, int  _square)
{
    nameField =_nameField;
    latReference=_latReference;
    longReference=_longReference;
    ratioToInt=_ratioToInt;
    square=_square;
}

LUW::~LUW()
{
    //dtor
}

void LUW::print()const
{
    cout<<nameField <<endl;
    cout<<latReference<< " lat" <<endl;
    cout<< longReference<<" long"<<endl;
    cout<<ratioToInt<<" ratioToInt"<<endl;
    cout<<square<<" square"<<endl;
}

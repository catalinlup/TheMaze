#include "Mobile.h"

Mobile::Mobile()
{
    //ctor
}

Mobile::~Mobile()
{
    //dtor
}

void Mobile::moveX(int dx){
    _x+=dx;
}
void Mobile::moveY(int dy){
    _y+=dy;
}
void Mobile::shrinkH(float ftcH){
    _h=ftcH*float(_h);
}
void Mobile::shrinkW(float ftcW){
    _w=ftcW*float(_w);
}

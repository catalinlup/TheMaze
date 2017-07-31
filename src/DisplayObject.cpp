#include "DisplayObject.h"
#include <iostream>

DisplayObject::DisplayObject(Texture*text,int*x,int*y,int*width,int*height)
{
    _text=text;
    _x=x;
    _y=y;
    _width=width;
    _height=height;
     std::cout<<*_width<<" "<<*_height<<" "<<*_x<<" "<<*_y<<std::endl;
}

void DisplayObject::display(SDL_Renderer*ren){
     std::cout<<*_width<<" "<<*_height<<" "<<*_x<<" "<<*_y<<std::endl;
    _text->displayTexture(*_width,*_height,*_x,*_y,ren);


}

DisplayObject DisplayObject::operator=(DisplayObject& other){
    DisplayObject New(other._text,other._x,other._y,other._width,other._height);
    _text=other._text;
    _x=other._x;
    _y=other._y;
    _width=other._width;
    _height=other._height;
    return New;

}

DisplayObject::~DisplayObject()
{
    _text=nullptr;
    _x=nullptr;
    _y=nullptr;
    _width=nullptr;
    _height=nullptr;

}

#ifndef DISPLAYOBJECT_H
#define DISPLAYOBJECT_H
#include"Texture.h"
#include<SDL.h>


class DisplayObject
{
    public:
        DisplayObject(Texture*text,int*x,int*y,int*width,int*height);
        void display(SDL_Renderer*ren);
        ~DisplayObject();
        DisplayObject operator=(DisplayObject& other);
        int*_x;
        int*_y;
        int*_width;
        int*_height;
    private:
       Texture *_text;

};

#endif // DISPLAYOBJECT_H

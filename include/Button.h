#ifndef BUTTON_H
#define BUTTON_H
#include"Text.h"
#include <SDL.h>

class Button
{
    public:
        Button();
        void create(string text,string fontpath,int Size,SDL_Renderer*ren,int *x,int*y,int width,int height,int r,int g,int b);
        void display(SDL_Renderer*ren);
        bool pressed(SDL_Event&ev);

        ~Button();
    private:
        Text _text;
        int* _x;
        int* _y;
        int _width;
        int _height;
        int _size=20;
        SDL_Rect _dst;
        SDL_Color _col;
};

#endif // BUTTON_H

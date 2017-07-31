#ifndef TEXT_H
#define TEXT_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
using namespace std;

class Text
{
    public:
        Text();
        void createText(string text,string fontpath,SDL_Color color,int Size,SDL_Renderer*ren);
        SDL_Texture* _texture;
        ~Text();
    private:
        string _text;
        string _fontpath;
        TTF_Font* _font=nullptr;

        SDL_Color _color;
        int _size;
};

#endif // TEXT_H

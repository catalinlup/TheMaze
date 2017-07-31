#include "Text.h"

Text::Text()
{
    //ctor
}

void Text::createText(string text,string fontpath,SDL_Color color,int Size,SDL_Renderer*ren){

    _text=text;
    _fontpath=fontpath;
    _color=color;
    _size=Size;
    _font=TTF_OpenFont(_fontpath.c_str(),_size);
    if(_font==nullptr){
        cerr<<"Failed to load font at location "<<_fontpath+" "<<TTF_GetError()<<endl;
    }
    SDL_Surface*surf=nullptr;

    surf=TTF_RenderText_Solid(_font,_text.c_str(),color);
    if(surf==nullptr){
        cerr<<"Failed to create text "<<text+" "<<TTF_GetError()<<endl;
    }

    _texture=SDL_CreateTextureFromSurface(ren,surf);

    if(_texture==0){
        cerr<<"Failed to create texture "<<text+" "<<SDL_GetError()<<endl;

    }

    SDL_FreeSurface(surf);

}

Text::~Text()
{
    //dtor
}

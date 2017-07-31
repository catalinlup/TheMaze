#include "Button.h"

Button::Button()
{
    //ctor
}

void Button::create(string text,string fontpath,int Size,SDL_Renderer*ren,int *x,int*y,int width,int height,int r,int g,int b){
    _col.r=r;
    _col.g=g;
    _col.b=b;

    _text.createText(text,fontpath,_col,_size,ren);
    _x=x;
    _y=y;
    _width=width;
    _height=height;


}



void Button::display(SDL_Renderer*ren){
    _dst.x=*_x;
    _dst.y=*_y;
    _dst.w=_width;
    _dst.h=_height;
    //cout<<_text._texture<<endl;
    SDL_RenderCopy(ren,_text._texture,NULL,&_dst);

}

bool Button::pressed(SDL_Event &ev){
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    if(mx>=*_x&&my>=*_y&&mx<=*_x+_width&&my<=*_y+_height){
        if(ev.type==SDL_MOUSEBUTTONDOWN){
            return true;
        }
    }
    return false;

}



Button::~Button()
{
    //dtor
}

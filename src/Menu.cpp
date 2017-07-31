#include "Menu.h"

#include<iostream>

Menu::Menu(SDL_Renderer*ren,int &SCREEN_WIDTH,int &SCREEN_HEIGHT)
{
    //ctor

    camX=new int(0);
    camY=new int(0);

    _screenWidth=SCREEN_WIDTH;
    _screenHeight=SCREEN_HEIGHT;
    _middleWidth=_screenWidth/2;
    _middleHeight=_screenHeight/2;
    _rh=float(_screenHeight)/RefHeight;
    _rw=float(_screenWidth)/RefWidth;

    _textSize=_textSize*(_screenWidth*_screenHeight)/(RefWidth*RefHeight);

    _backgroundText.loadTexture("res/background/menu_background.png",1920,1080,0,0,ren);
    add(&_backgroundText,&_bx,&_by,&_screenWidth,&_screenHeight);

    _gameX=_middleWidth-0.2*float(_middleWidth)-200*_rw;
    _gameY=_middleHeight+0.3*float(_middleHeight);
    _game.create("Play","res/fonts/font_menu.otf",_textSize,ren,&_gameX,&_gameY,200*_rw,100*_rh,255,0,0);
    addButt(&_game);

    _mapcrX=_middleWidth+0.2*float(_middleWidth);
    _mapcrY=_middleHeight+0.3*float(_middleHeight);
    _mapcr.create("Map Maker","res/fonts/font_menu.otf",_textSize,ren,&_mapcrX,&_mapcrY,350*_rw,100*_rh,255,0,0);
    addButt(&_mapcr);

}

bool Menu::gamePressed(SDL_Event& ev){
    if(_game.pressed(ev))
        return true;
    return false;
}

bool Menu::mapcrPressed(SDL_Event& ev){
    if(_mapcr.pressed(ev))
        return true;
    return false;
}



Menu::~Menu()
{
    //dtor
}



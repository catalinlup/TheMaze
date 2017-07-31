#ifndef DISPLAY_H
#define DISPLAY_H
#include<string>
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "Screen.h"
#include "Menu.h"
#include "Game.h"
#include "MapMaker.h"
#include "GameSelection.h"




enum SCREEN_STATE{
    MenuScreen,
    GameScreen,
    MapMakerScreen,
    GameSelectionScreen

};

class Display
{
    public:
        Display(std::string);//Initializare
        ~Display(){
            SDL_DestroyWindow(_window);
            SDL_Quit();
            IMG_Quit();
        }
        void render(SDL_Event &ev);//Afisare imagini
        int getWidth();//Getter
        int getHeight();//'-'
        std::string getTitle();//'-'

    private:
        int _width=NULL;//latime ecran
        int _height=NULL;//inaltime ecran
        std::string _title="Error-unselected";//titlu
        SDL_Window*_window=nullptr;
        SDL_Renderer*_renderer=nullptr;
        SDL_DisplayMode _disp;
        Screen*_curScreen;
        SCREEN_STATE _screenState;
        Texture test;
        //Screen tst;
        Menu* _menu;
        Game* _game;
        MapMaker* _mapMaker;
        GameSelection*_gameSelection;
};

#endif // DISPLAY_H

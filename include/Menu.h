#ifndef MENU_H
#define MENU_H

#include <Screen.h>
#include "Texture.h"
#include "Button.h"
#include <SDL.h>
#include <string>
using namespace std;
class Menu : public Screen
{
    public:
        Menu(SDL_Renderer*ren,int &SCREEN_WIDTH,int &SCREEN_HEIGHT);
        ~Menu();
        bool gamePressed(SDL_Event& ev);
        bool mapcrPressed(SDL_Event&ev);
        void createMap(){ }
        void renderGrid(){ }
        void runMap(SDL_Event&ev){ }
        void save(string filepath){ }

    private:





        int _screenWidth;
        int _screenHeight;
        int _middleWidth;
        int _middleHeight;
        int _textSize=20;
        float _rh;
    float _rw;

        int _bx=0;
        int _by=0;
        Texture _backgroundText;


        int _gameX=0;
        int _gameY=0;
        Button _game;

        int _mapcrX=0;
        int _mapcrY=0;
        Button _mapcr;





};

#endif // MENU_H

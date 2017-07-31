#ifndef GAMESELECTION_H
#define GAMESELECTION_H


#include <Screen.h>
#include <SDL.h>
#include <string>
#include <vector>
#include "Texture.h"
#include "Map.h"
#include <fstream>


using namespace std;



class GameSelection:public Screen
{
    public:
        GameSelection(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight);
        ~GameSelection();

        bool gamePressed(SDL_Event&ev);
        bool mapcrPressed(SDL_Event&ev){return false;}
        void createMap(){ }
        void renderGrid(){ }
        void runMap(SDL_Event&ev);
        void save(string filepath){ }
    private:

        bool pressed=false;

        SDL_Renderer*_ren;

        vector<string> MapsToLoad;
        void LoadMaps();
        void SelectMap();
        int _curMap=0;

        Map _map;

        Button* _curFile;
        void DisplayCurFile(string fileName);
        int _curFileX;
        int _curFileY;



        int _screenWidth;
        int _screenHeight;
        int _middleWidth;
        int _middleHeight;
        float _rw;
        float _rh;

        Texture _background;
        int _bx=0,_by=0;
        Button* _startGame;
        int _startGameX;
        int _startGameY;
        Button *_charecterCreation;
        int _charecterCreationX;
        int _charecterCreationY;

};

#endif // GAMESELECTION_H

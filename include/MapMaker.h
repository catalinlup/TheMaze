#ifndef MAPMAKER_H
#define MAPMAKER_H




#include <Screen.h>
#include <SDL.h>
#include <fstream>
#include <string>
#include<sstream>
#include<cmath>
#include "Map.h"
#include "Button.h"

using namespace std;








class MapMaker : public Screen
{
    public:
        MapMaker(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight);
        ~MapMaker();

        void createMap();
        void runMap(SDL_Event&ev);
        void renderGrid();
        void save(string filepath);

        bool gamePressed(SDL_Event&ev){return false;}
        bool mapcrPressed(SDL_Event&ev){return false;}


    protected:


        void ManageFileName();

        SDL_Renderer*_ren;

        ofstream _out;
        ifstream _data;
        string _dataFile="res/blocks/BlocksData.dt";
        string _loadMapFile="maps/MapsData.dt";
        vector<string>types;
        int cur_type=0;
        vector<string> loadList;
        int cur_load=0;
        bool GridRender=true;
        Map _map;
        int _screenWidth;
        int _screenHeight;
        const int _RefWidth=1920;
        const int _RefHeight=1080;
        int _gameScreenW=900;
        int _gameScreenH=900;
        int _gameScreenStX;
        int _gameScreenStY;
        float _rw;
        float _rh;
        int _camX=0;
        int _camY=0;
        int _tileW;
        int _tileH;
        int _numBlocksOnScreen=30;
        COORDONATE Square[300][300];
        COORDONATE SquareOf(int x,int y);
        void update_size();
        char convert(string type);
        int convert_back(char code);
        void loadMap();

        bool _fillMode=false;
        COORDONATE *_f1=nullptr;
        COORDONATE *_f2=nullptr;



        Button* _curBlock=nullptr;
        void DisplayCurBlock(string block);
        int _curBlockX=0;
        int _curBlockY=0;

        Button* _curFile=nullptr;
        void DisplayCurFile(string file);
        int _curFileX=0;
        int _curFileY=0;

};

#endif // MAPMAKER_H

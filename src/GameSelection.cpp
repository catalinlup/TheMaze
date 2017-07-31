#include "GameSelection.h"

GameSelection::GameSelection(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight)
{
    camX=new int(0);
    camY=new int(0);
    _ren=ren;
    _screenHeight=ScreenHeight;
    _screenWidth=ScreenWidth;
    _rh=float(RefHeight)/ScreenHeight;
    _rw=float(RefWidth)/ScreenWidth;
    LoadMaps();
    _curFile=new Button();

    _background.loadTexture("res/background/game_selection.png",1920,1080,0,0,_ren);
    add(&_background,&_bx,&_by,&_screenWidth,&_screenHeight);

    _curFileX=_screenWidth/2;
    _curFileY=_screenHeight/2;

    DisplayCurFile(MapsToLoad[_curMap]);
    addButt(_curFile);
     _middleWidth=_screenWidth/2;
     _middleHeight=_screenHeight/2;
    _startGameX=_middleWidth-0.2*float(_middleWidth)-200*_rw;
    _startGameY=_middleHeight+0.3*float(_middleHeight);
    _startGame=new Button();
    _startGame->create("Start Game","res/fonts/font_menu.otf",20,_ren,&_startGameX,&_startGameY,200*_rw,100*_rh,255,0,0);
    addButt(_startGame);

    _charecterCreation=new Button();
    _charecterCreationX=_middleWidth+0.2*float(_middleWidth);
    _charecterCreationY=_middleHeight+0.3*float(_middleHeight);
    _charecterCreation->create("Charecter Creation","res/fonts/font_menu.otf",20,_ren,&_charecterCreationX,&_charecterCreationY,300*_rw,100*_rh,255,0,0);
    addButt(_charecterCreation);


}

void GameSelection::LoadMaps(){
    ifstream in("maps/MapsData.dt");
    string line;
    while(getline(in,line)){
        MapsToLoad.push_back(line);
    }
    in.close();

}

void GameSelection::SelectMap(){
    ifstream in("maps/"+MapsToLoad[_curMap]);
    ofstream out("cur_level/cur_level.dt");
    for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            char temp;
            in>>temp;
            out<<temp;
        }
        out<<"\n";
    }
    in.close();
    out.close();


}

bool GameSelection::gamePressed(SDL_Event&ev){
    if(_startGame->pressed(ev))
        return true;
    return false;



}

void GameSelection::runMap(SDL_Event&ev){
    if(ev.type==SDL_KEYDOWN)
        pressed=true;
    if(pressed&&ev.type==SDL_KEYUP){
        if(ev.key.keysym.sym==SDLK_d){
            if(_curMap<MapsToLoad.size()-1){
                _curMap++;
                DisplayCurFile(MapsToLoad[_curMap]);
            }
        }
        else if(ev.key.keysym.sym==SDLK_a){
            if(_curMap>0){
                _curMap--;
                DisplayCurFile(MapsToLoad[_curMap]);
            }
        }
        else if(ev.key.keysym.sym==SDLK_s){
            DisplayCurFile("Selected "+MapsToLoad[_curMap]);
            SelectMap();

        }
        pressed=false;
    }
}

GameSelection::~GameSelection()
{
    //dtor
}

void GameSelection::DisplayCurFile(string fileName){
    string new_name;
    for(int i=0;fileName[i]!='.';i++){
        new_name.push_back(fileName[i]);
    }
    fileName=new_name;
    _curFileX=_screenWidth/2-((30.0*fileName.size())*_rw)/2;
    _curFile->create(fileName,"res/fonts/FFF_Tusj.ttf",30,_ren,&_curFileX,&_curFileY,(30.0*fileName.size())*_rw,60.0*_rh,255,0,0);
}

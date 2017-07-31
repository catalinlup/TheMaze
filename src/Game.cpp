#include "Game.h"


char Game::convert(string type){
    int index(0);
    for(int i=0;i<types.size();i++){
        if(types[i]==type){
            index=i;
            break;
        }
    }

    return index+'a';

}

int Game::convert_back(char code){
    int index(0);
    index=int(code-'a');

    return index;
}

Game::Game(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight)
{
    game=true;
    camX=new int(0);
    camY=new int(0);
    game=true;
    _ren=ren;
    _screenHeight=ScreenHeight;
    _screenWidth=ScreenWidth;
    _ScrScreenWidth=ScreenWidth;
    _ScrScreenHeight=ScreenHeight;
    _rw=float(_screenWidth)/RefWidth;
    _rh=float(_screenHeight)/RefHeight;
    update_size();
    LoadTypes();
    LoadCurMap();

    test=new Animation("res/animations/ManIdle/","man_idle_",0,0,101,77,_ren,61,0);
    addAnimation(test,&tx,&ty,&_tileW,&_tileH,&its,&show);


}

COORDONATE Game::SquareOf(int x,int y){
    COORDONATE rasp;
    int j=(x-_screenWidth/2+_screenHeight/2)/_tileW;
    int i=y/_tileH;
    rasp.x=j;
    rasp.y=i;
    return rasp;
}

void Game::update_size(){
    _tileH=_screenHeight/_numBlocksOnScreen;
    _tileW=_screenHeight/_numBlocksOnScreen;


    for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            Square[i][j].x=j*_tileW+_screenWidth/2-_screenHeight/2;
            Square[i][j].y=i*_tileH;

        }
    }



}

void Game::LoadTypes(){
    ifstream in("res/blocks/BlocksData.dt");
    string line;
    while(getline(in,line)){
        types.push_back(line);


    }

    in.close();
}


void Game::LoadCurMap(){
    ifstream in("cur_level/cur_level.dt");
    DeleteAll();
    for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            char temp;
            in>>temp;
            _map._Map[i][j]=temp;
            int ind=convert_back(temp);
            if(ind>=0){
                string tp=types[ind];
                Block* bl=new Block(tp,"png",_ren);
                add(bl->getTexture(),&Square[i][j].x,&Square[i][j].y,&_tileW,&_tileH);
            }

        }

    }
    in.close();


}

void Game::runMap(SDL_Event&ev){
    test->run(10);


}

Game::~Game()
{
    //dtor
}

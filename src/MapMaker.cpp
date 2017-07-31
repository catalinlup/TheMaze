#include "MapMaker.h"


char MapMaker::convert(string type){
    int index(0);
    for(int i=0;i<types.size();i++){
        if(types[i]==type){
            index=i;
            break;
        }
    }

    return index+'a';

}

int MapMaker::convert_back(char code){
    int index(0);
    index=int(code-'a');

    return index;
}



MapMaker::MapMaker(SDL_Renderer*ren,int ScreenWidth,int ScreenHeight)
{
    //ctor
    camX=new int(0);
    camY=new int(0);
    game=true;
    _ScrScreenHeight=ScreenHeight;
    _ScrScreenWidth=ScreenWidth;
    _ren=ren;
    _screenWidth=ScreenWidth;
    _screenHeight=ScreenHeight;
    _rw=float(_screenWidth)/RefHeight;
    _rh=float(_screenHeight)/RefHeight;
    _gameScreenH*=_rh;
    _gameScreenW*=_rw;
    update_size();



    //Add Tiles to editor

    _data.open(_dataFile);

    string line;
    while(getline(_data,line)){
        types.push_back(line);

    }
    _data.close();


    //end

    //Init Block Display
    _curBlockX=_screenWidth/2-_screenHeight/2;
    _curBlockY=0;
    _curBlock=new Button();
    DisplayCurBlock(types[cur_type]);
    addButt(_curBlock);
    //end

    //Init Maps Load List
    _data.open(_loadMapFile);
    string mpline;
    while(getline(_data,mpline)){
        loadList.push_back(mpline);
    }

    ManageFileName();
    cur_load=loadList.size()-1;
    //end

    //Init File Display
        _curFileX=_screenWidth/2+_screenHeight/2;
        _curFileY=0;
        _curFile=new Button();
        DisplayCurFile(loadList[cur_load]);
        addButt(_curFile);
    //end

}

void MapMaker::update_size(){
    _tileH=_screenHeight/_numBlocksOnScreen;
    _tileW=_screenHeight/_numBlocksOnScreen;

    cout<<_tileH<<" "<<_tileW;


    for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            Square[i][j].x=j*_tileW+_screenWidth/2-_screenHeight/2;
            Square[i][j].y=i*_tileH;
        }
    }



}

COORDONATE MapMaker::SquareOf(int x,int y){
    COORDONATE rasp;
    int j=(x-_screenWidth/2+_screenHeight/2)/_tileW;
    int i=y/_tileH;
    rasp.x=j;
    rasp.y=i;
    return rasp;
}

void MapMaker::renderGrid(){
    if(GridRender){
    SDL_SetRenderDrawColor(_ren,0,0,255,0);
    for(int i=0;i<=_numBlocksOnScreen;i++){
        SDL_RenderDrawLine(_ren,Square[0][i].x,Square[0][i].y,Square[_numBlocksOnScreen][i].x,Square[_numBlocksOnScreen][i].y);
    }
    for(int i=0;i<=_numBlocksOnScreen;i++){
        SDL_RenderDrawLine(_ren,Square[i][0].x,Square[i][0].y,Square[i][_numBlocksOnScreen].x,Square[i][_numBlocksOnScreen].y);

    }
    }


    SDL_SetRenderDrawColor(_ren,0,0,0,0);

}

void MapMaker::loadMap(){
    ifstream in("maps/"+loadList[cur_load]);
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
            cout<<Square[i][j].x<<" "<<Square[i][j].y<<"-"<<endl;
            add(bl->getTexture(),&Square[i][j].x,&Square[i][j].y,&_tileW,&_tileH);
            }
        }
    }
    in.close();

}

void MapMaker::createMap(){


    for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            _map._Map[i][j]='_';
        }
    }
}



void MapMaker::runMap(SDL_Event&ev){
    int mx;
    int my;
    SDL_GetMouseState(&mx,&my);
    COORDONATE rasp=SquareOf(mx+*camX,my+*camY);
    //cout<<rasp.x<<" "<<rasp.y<<endl;


    if(_fillMode==false){
    Block*bl=new Block(types[cur_type],"png",_ren);
    if(ev.type==SDL_MOUSEBUTTONDOWN){
        //cout<<Square[rasp.y][rasp.x].x<<" "<<Square[rasp.y][rasp.x].y<<" "<<mx<<" "<<my<<endl;
        add(bl->getTexture(),&Square[rasp.y][rasp.x].x,&Square[rasp.y][rasp.x].y,&_tileW,&_tileH);
        //cout<<"Apasat"<<endl;
        _map._Map[rasp.y][rasp.x]=convert(types[cur_type]);
        SDL_Delay(250);
    }



    if(ev.type==SDL_KEYDOWN){
        if(ev.key.keysym.sym==SDLK_p){
            *camX=0;
            *camY=0;
            if(_numBlocksOnScreen<=80){
            _numBlocksOnScreen+=10;
            update_size();
            SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_o){
            *camX=0;
            *camY=0;
            if(_numBlocksOnScreen>=40){
            _numBlocksOnScreen-=10;
            update_size();
            SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_DELETE){
            prop sters=undoTexture();
            int*x,*y;
            x=sters.x;
            y=sters.y;
            COORDONATE del=SquareOf(*x,*y);
            _map._Map[del.y][del.x]='_';
            SDL_Delay(250);
        }
        else if(ev.key.keysym.sym==SDLK_k){
            if(cur_type>0){
                cur_type--;
                DisplayCurBlock(types[cur_type]);
                SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_l){
            if(cur_type<types.size()-1){
                cur_type++;
                DisplayCurBlock(types[cur_type]);
                SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_h){
            if(cur_load>0){
                cur_load--;
                DisplayCurFile(loadList[cur_load]);
                SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_j){
            if(cur_load<loadList.size()-1){
                cur_load++;
                DisplayCurFile(loadList[cur_load]);
                SDL_Delay(250);
            }
        }
        else if(ev.key.keysym.sym==SDLK_i){
            loadMap();
            SDL_Delay(250);
        }
        else if(ev.key.keysym.sym==SDLK_f){
            _fillMode=true;
            DisplayCurBlock("fill_mode_"+types[cur_type]);
            SDL_Delay(250);
        }
        else if(ev.key.keysym.sym==SDLK_g){
            if(GridRender==true)
                GridRender=false;
            else
                GridRender=true;
            SDL_Delay(250);
        }

    }


    if(*camX<=Square[_map._Mapsize-1][_map._Mapsize-1].x-_screenHeight){
        if(mx-_screenWidth/2+_screenHeight/2>=_screenHeight-_tileW){
            *camX+=_tileW;
            SDL_Delay(250);
        }
    }
    if(*camX>0){
        if(mx-_screenWidth/2+_screenHeight/2<=_tileW){
        *camX-=_tileW;
        SDL_Delay(250);
        }

    }
    if(my>=_screenHeight-_tileH){
        *camY+=_tileH;
        SDL_Delay(250);
    }
    if(*camY>0){
        if(my<=_tileH){
            *camY-=_tileH;
            SDL_Delay(250);
        }
    }
    }
    else{
        update_size();
        if(ev.type==SDL_MOUSEBUTTONDOWN&&_f1==nullptr){
            _f1=new COORDONATE();
            _f1->x=rasp.x;
            _f1->y=rasp.y;
            SDL_Delay(250);
        }
        else if(ev.type==SDL_MOUSEBUTTONDOWN&&_f2==nullptr){
            _f2=new COORDONATE();
            _f2->x=rasp.x;
            _f2->y=rasp.y;
            for(int X=_f1->x;X<=_f2->x;X++){
                for(int Y=_f1->y;Y<=_f2->y;Y++){
                    //cout<<X<<" "<<Y<<" "<<_f1->x<<" "<<_f1->y<<" "<<_f2->x<<" "<<_f2->y<<endl;
                    Block*bl=new Block(types[cur_type],"png",_ren);
                    add(bl->getTexture(),&Square[Y][X].x,&Square[Y][X].y,&_tileW,&_tileH);
                    _map._Map[Y][X]=convert(types[cur_type]);
                }
            }
            delete _f1;
            delete _f2;
            _f1=nullptr;
            _f2=nullptr;
            _fillMode=false;
            DisplayCurBlock(types[cur_type]);
            SDL_Delay(250);
        }else if(ev.type==SDL_KEYDOWN&&ev.key.keysym.sym==SDLK_f){
             delete _f1;
            delete _f2;
            _f1=nullptr;
            _f2=nullptr;
            _fillMode=false;
            DisplayCurBlock(types[cur_type]);
            SDL_Delay(250);
        }

    }


}

void MapMaker::ManageFileName(){
    ifstream in("maps/MapNameToCreate.dt");
    string ind;
    int index(0);
    in>>ind;
    for(int i=0;i<ind.size();i++){
        index=index*10+(ind[i]-'0');
    }
    index++;
    in.close();
    string name="Level"+ind+".tmmap";
    loadList.push_back(name);

}

void MapMaker::save(string filepath){

    if(cur_load==loadList.size()-1){
     ifstream in("maps/MapNameToCreate.dt");
    string ind;
    int index(0);
    in>>ind;
    for(int i=0;i<ind.size();i++){
        index=index*10+(ind[i]-'0');
    }
    index++;
    in.close();
    ofstream out("maps/MapNameToCreate.dt");
    out<<index;
    out.close();
    string name="Level"+ind+".tmmap";
    ofstream dout("maps/MapsData.dt",ios_base::app);
    dout<<"\n"<<name;
    }

    _out.open("maps/"+loadList[cur_load]);

      for(int i=0;i<_map._Mapsize;i++){
        for(int j=0;j<_map._Mapsize;j++){
            _out<<_map._Map[i][j];
        }
        _out<<"\n";
    }

    DisplayCurFile("Saved as "+loadList[cur_load]);

    _out.close();

}

void MapMaker::DisplayCurBlock(string block){

    _curBlock->create(block,"res/fonts/FFF_Tusj.ttf",20,_ren,&_curBlockX,&_curBlockY,(20*block.size())*_rh,50*_rh,0,255,0);

}

void MapMaker::DisplayCurFile(string file){
    _curFileX=_screenWidth/2+_screenHeight/2-(20*file.size())*_rh;
    _curFile->create(file,"res/fonts/FFF_Tusj.ttf",20,_ren,&_curFileX,&_curFileY,(20*file.size())*_rh,50*_rh,255,0,0);
}

MapMaker::~MapMaker()
{
    //dtor


}

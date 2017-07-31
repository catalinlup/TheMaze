#include "Map.h"

Map::Map()
{
    //ctor
    _Map=new char*[_Mapsize];
    for(int i=0;i<_Mapsize;i++){
        _Map[i]=new char[_Mapsize];
    }
    _Mapbl=new Block**[_Mapsize];
    for(int i=0;i<_Mapsize;i++){
        _Mapbl[i]=new Block*[_Mapsize];
    }

}



Map::~Map()
{
    //dtor
}

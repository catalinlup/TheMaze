#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include "Block.h"
#include <string>
#include <vector>
using namespace std;

class Map
{
    public:
        Map();
        ~Map();
        char **_Map;
        Block ***_Mapbl;
        int _Mapsize=100;
    private:


};

#endif // MAP_H

#ifndef PLAYER_H
#define PLAYER_H

#include "Mobile.h"
#include <SDL.h>
#include <iostream>
using namespace std;

enum class AttackType{
    TYPE1
};


class Player : public Mobile
{
    public:
        Player(int _width,int _height,SDL_Renderer*ren);
        ~Player();
        void attack(Mobile* enemy);
        void processControl(SDL_Event&ev);
        int getSpeed();

    private:
        SDL_Renderer*_ren;
        string _name="";
        void LoadData(string _filepath);
        float getFinalDamage(Mobile* enemy);
        AttackType _curAttack;
        bool pressed=false;

        Animation*_WalkingAnim=nullptr;
        bool _WalkingAnimActive=false;
        int _WalkingAnimationIter=10;

        bool _Wisp=false;
        bool _Sisp=false;
        bool _Aisp=false;
        bool _Disp=false;

        int speed=1;



};

#endif // PLAYER_H

#include "Player.h"

Player::Player(int _width,int _height,SDL_Renderer*ren)
{
    //ctor
    setX(600);
    setY(500);
    setW(_width);
    setH(_height);
    _ren=ren;
    _WalkingAnim=new Animation("res/animations/ManIdle/","man_idle_",0,0,101,77,_ren,61,0);
    addAnimation(_WalkingAnim,&_WalkingAnimActive,&_WalkingAnimationIter);

}

Player::~Player()
{
    //dtor
}

void Player::attack(Mobile* enemy){
    enemy->_skillSet._life-=getFinalDamage(enemy);


}

float Player::getFinalDamage(Mobile* enemy){
    return 0;
}

void Player::processControl(SDL_Event&ev){
    if(ev.type==SDL_KEYDOWN){
        if(ev.key.keysym.sym==SDLK_w){

            _Wisp=true;
        }
        if(ev.key.keysym.sym==SDLK_s){

            _Sisp=true;
        }
        if(ev.key.keysym.sym==SDLK_a){

            _Aisp=true;
        }
        if(ev.key.keysym.sym==SDLK_d){

            _Disp=true;
        }
        _WalkingAnimActive=true;
    }

    if(ev.type==SDL_KEYUP){
        if(ev.key.keysym.sym==SDLK_w){
            _Wisp=false;
        }
        if(ev.key.keysym.sym==SDLK_s){
            _Sisp=false;
        }
        if(ev.key.keysym.sym==SDLK_a){

            _Aisp=false;
        }
        if(ev.key.keysym.sym==SDLK_d){
            _Disp=false;
        }
        _WalkingAnimActive=true;
    }

    if(_Wisp){
        moveY(-speed);
    }
    if(_Sisp){
        moveY(speed);
    }
    if(_Aisp){
        moveX(-speed);
    }
    if(_Disp){
        moveX(speed);
    }


}

int Player::getSpeed(){
    return speed;
}


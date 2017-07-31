#ifndef MOBILE_H
#define MOBILE_H

#include "Entity.h"

struct Skills{
    float _life=0;
    float _damage=0;
    float _defense=0;
    float _magicResistance=0;
    float _mana=0;
    float _stamina=0;
    float _strength=0;

};


class Mobile : public Entity
{
    public:
        Mobile();
        ~Mobile();
        void moveX(int dx);
        void moveY(int dy);
        void shrinkW(float ftcW);
        void shrinkH(float ftcH);
        Skills _skillSet;
        void attack(Mobile* enemy);
        void processControl(SDL_Event&ev){ };
    protected:
        bool _dead=false;



};

#endif // MOBILE_H

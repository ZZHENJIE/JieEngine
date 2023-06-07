#ifndef PLAYER_H
#define PLAYER_H

#include "../Animal.h"

class Player : public Animal{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Player";
        }

        Player(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point Position,SDL_Surface * WindowSurface);

        Player(const char * FileUrl,SDL_Point Position,SDL_Surface * WindowSurface);
    
        void Jump();

        void MoveRight();

        void MoveLeft();

        void Update();

        void Collide(Component * component,SDL_Rect CollideRect,short CollidePosition);
};

#endif
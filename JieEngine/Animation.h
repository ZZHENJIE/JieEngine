#ifndef ANIMATION_H
#define ANIMATION_H

#include "JieEngine.h"

class Animation : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Animation";
        }
        /*
            动画构造函数 参数为 动画图片 图片分割数量 播放速度(数值越大越慢) 显示位置 WindowSurface
        */
        Animation(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point * ShowPosition,SDL_Surface * WindowSurface){
            this->Image = SDL_LoadBMP(FileUrl);
            this->ImageInciseNumber = ImageInciseNumber;
            this->PlaySpeed = PlaySpeed;
            this->WindowSurface = WindowSurface;
            this->ShowPosition = ShowPosition;
            this->Size.x = this->Image->w/ImageInciseNumber;
            this->Size.y = this->Image->h;
            this->PositionArray = new SDL_Point[ImageInciseNumber];
            for(short i = 0; i < ImageInciseNumber; i ++){
                this->PositionArray[i].x = i * this->Size.x;
                this->PositionArray[i].y = 0;
            }
        }
        /*
            静态图片构造函数 参数为 动画图片 显示位置 WindowSurface
        */
        Animation(const char * FileUrl,SDL_Point * ShowPosition,SDL_Surface * WindowSurface){
            this->IsAnimation = false;
            this->Image = SDL_LoadBMP(FileUrl);
            this->WindowSurface = WindowSurface;
            this->ShowPosition = ShowPosition;
            this->PositionArray = new SDL_Point[1];
            this->PositionArray[0].x = 0;
            this->PositionArray[0].y = 0;
            this->Size.x = this->Image->w;
            this->Size.y = this->Image->h;
        }
        /*
            获取组件Size
        */
        SDL_Point GetComponentSize(){
            return Size;
        }
        /*
            每帧更新函数
        */
        void Update(){
            SDL_Rect TempImageSurfacePosition = {PositionArray[AnimationCount].x,PositionArray[AnimationCount].y,Size.x,Size.y};
            SDL_Rect TempWindowSurfacePosition = {ShowPosition->x,ShowPosition->y,Size.x,Size.y};
            SDL_BlitSurface(Image,&TempImageSurfacePosition,WindowSurface,&TempWindowSurfacePosition);

            if(IsPlay && IsAnimation){
                if(AnimationPlaySpeedCount % PlaySpeed == 0){
                    if(AnimationCount == ImageInciseNumber - 1){
                        AnimationCount = 0;
                    }else{
                        AnimationCount++;
                    }
                    AnimationPlaySpeedCount = 0;
                }
                AnimationPlaySpeedCount ++;
            }
        }
        /*
            播放动画
        */
        void Play(){
            this->IsPlay = true;
        }
        /*
            暂停动画
        */
        void Stop(){
            this->IsPlay = false;
        }

    private:
        short ImageInciseNumber = 0;
        short PlaySpeed = 0;
        short AnimationCount = 0;
        short AnimationPlaySpeedCount = 0;
        bool IsPlay = true;
        SDL_Surface * Image;
        SDL_Point * PositionArray;
        SDL_Point Size;
        SDL_Point * ShowPosition;
        bool IsAnimation = true;
};

#endif
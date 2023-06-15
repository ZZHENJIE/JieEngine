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
            this->Image = Decrypt::DecryptImage(FileUrl);
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
            this->Image = Decrypt::DecryptImage(FileUrl);
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
            return this->Size;
        }
        /*
            每帧更新函数
        */
        void Update(){
            if(this->IsShow){
                SDL_Rect TempImageSurfacePosition = {this->PositionArray[AnimationCount].x,this->PositionArray[AnimationCount].y,this->Size.x,this->Size.y};
                SDL_Rect TempWindowSurfacePosition = {this->ShowPosition->x,this->ShowPosition->y,this->Size.x,this->Size.y};
                SDL_BlitSurface(Image,&TempImageSurfacePosition,WindowSurface,&TempWindowSurfacePosition);
            }

            if(this->IsPlay && this->IsAnimation){
                if(this->AnimationPlaySpeedCount % this->PlaySpeed == 0){
                    if(this->AnimationCount == this->ImageInciseNumber - 1){
                        this->AnimationCount = 0;
                    }else{
                        this->AnimationCount++;
                    }
                    this->AnimationPlaySpeedCount = 0;
                }
                this->AnimationPlaySpeedCount ++;
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
        /*
            显示动画
        */
        void Show(){
            this->IsShow = true;
        }
        /*
            隐藏动画
        */
        void Hide(){
            this->IsShow = false;
        }
        /*
            释放资源函数
        */
        void Free(){
            SDL_FreeSurface(this->Image);
            delete[] PositionArray;
        }
    private:
        short ImageInciseNumber = 0;
        short PlaySpeed = 0;
        short AnimationCount = 0;
        short AnimationPlaySpeedCount = 0;
        bool IsPlay = true;
        bool IsAnimation = true;
        bool IsShow = true;
        SDL_Surface * Image;
        SDL_Point * PositionArray;
        SDL_Point Size;
        SDL_Point * ShowPosition;
};

#endif
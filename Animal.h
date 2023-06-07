#ifndef ANIMAL_H
#define ANIMAL_H

#include "Component.h"

class Animal : public Component{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Animal";
        }
        /*
            设置数据函数 参数为 动画素材路径 动画分割数量 播放速度(数值越大越慢) 显示位置 WindowSurface
        */
        void SetData(const char * FileUrl,short ImageInciseNumber,short PlaySpeed,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,ImageInciseNumber,PlaySpeed,&this->Position,WindowSurface);
            this->Size = ObjectAnimation->GetComponentSize();
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            设置数据函数 参数为 图片素材路径 显示位置 WindowSurface
        */
        void SetData(const char * FileUrl,SDL_Point Position,SDL_Surface * WindowSurface){
            this->ObjectAnimation = new Animation(FileUrl,&this->Position,WindowSurface);
            this->Size = ObjectAnimation->GetComponentSize();
            this->Position = Position;
            this->WindowSurface = WindowSurface;
        }
        /*
            设置动物移动速度
        */
        void SetMoveSpeed(short Speed){
            this->MoveSpeed = Speed;
        }
        /*
            默认向左移动函数
        */
        virtual void MoveLeft(){};
        /*
            默认向右移动函数
        */
        virtual void MoveRight(){};
        /*
            默认跳跃函数
        */
        virtual void Jump(){};
        /*
            默认发生碰撞处理函数 CollidePosition 0为左上角 1为右上角 2为左下角 3为右下角
        */
        virtual void Collide(Component * component,SDL_Rect CollideRect,short CollidePosition) = 0;
        /*
            每帧更新函数 记得加 this->ObjectAnimation->Update(); 哦
        */
        virtual void Update() = 0;
        /*
            默认碰撞检测函数
        */
        void Detect(Component * component){
            SDL_Rect ThisRect = {Position.x,Position.y,Size.x,Size.y};
            SDL_Rect ComponentRect = {component->Position.x,component->Position.y,component->Size.x,component->Size.y};
            SDL_Rect CollideRect;

            if(SDL_IntersectRect(&ThisRect,&ComponentRect,&CollideRect) == SDL_TRUE){
                SDL_Point DetectPoint = this->Position;
                if(SDL_PointInRect(&DetectPoint,&ComponentRect) == SDL_TRUE){
                    if(CollideRect.w > CollideRect.h){
                        this->Position.y = CollideRect.y + CollideRect.h;
                    }else{
                        this->Position.x = CollideRect.x + CollideRect.w + 1;
                    }
                    this->Collide(component,CollideRect,0);
                }
                DetectPoint.x += this->Size.x;
                if(SDL_PointInRect(&DetectPoint,&ComponentRect) == SDL_TRUE){
                    if(CollideRect.w > CollideRect.h){
                        this->Position.y = CollideRect.y + CollideRect.h;
                    }else{
                        this->Position.x = CollideRect.x - this->Size.x;
                    }
                    this->Collide(component,CollideRect,1);
                }
                DetectPoint.y += this->Size.y;
                if(SDL_PointInRect(&DetectPoint,&ComponentRect) == SDL_TRUE){
                    if(CollideRect.w > CollideRect.h){
                        this->Position.y = CollideRect.y - this->Size.y;
                    }else{
                        this->Position.x = CollideRect.x - this->Size.x;
                    }
                    this->Collide(component,CollideRect,3);
                }
                DetectPoint.x -= this->Size.x;
                if(SDL_PointInRect(&DetectPoint,&ComponentRect) == SDL_TRUE){
                    if(CollideRect.w > CollideRect.h){
                        this->Position.y = CollideRect.y - this->Size.y;
                    }else{
                        this->Position.x = CollideRect.x - CollideRect.w + 1;
                    }
                    this->Collide(component,CollideRect,2);
                }
            }
        }
    protected:
        short MoveSpeed = 2;
};

#endif
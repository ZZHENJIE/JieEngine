#ifndef WINDOW_H
#define WINDOW_H

#include "JieEngine.h"
#include "Map.h"

class Window : public JieEngine{
    public:
        /*
            获取类名
        */
        virtual const char * GetClass(){
            return "Window";
        }
        /*
            构造函数 参数为 窗口标题 窗口图标 窗口宽度 窗口高度
        */
        Window(const char * WindowTitle,const char * WindowIcon,unsigned int Window_W,unsigned int Window_H){
            SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
            this->MWindow = SDL_CreateWindow(WindowTitle,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Window_W,Window_H,SDL_WINDOW_SHOWN);
            SDL_SetWindowIcon(this->MWindow,SDL_LoadBMP(WindowIcon));
            this->WindowSurface = SDL_GetWindowSurface(this->MWindow);
            
        }
        /*
            窗口事件监听函数
        */
        void ListenEvent(){
            while(true){
                if(SDL_GetTicks() - Begin < (1000/FPS))
                {
                    SDL_Delay((1000/FPS) - SDL_GetTicks() + Begin);
                }

                if(SDL_PollEvent(&this->Event)){
                    if(Event.type == SDL_QUIT){
                        this->CloseWindow();
                        return;
                    }else{
                        CurrentMap->WindowEvent(Event);
                    }
                }

                CurrentMap->Update();

                SDL_UpdateWindowSurface(this->MWindow);

                Begin = SDL_GetTicks();
            }
        }
        /*
            设置FPS函数
        */
        void SetFPS(int FPS){
            this->FPS = FPS;
        }
        /*
            获取WindowSurface
        */
        SDL_Surface * GetWindowSurface(){
            return this->WindowSurface;
        }
        /*
            设置当前关卡实例
        */
        void SetMap(Map * CurrentMap){
            this->CurrentMap = CurrentMap;
        }
        /*
            关闭窗口函数
        */
        void CloseWindow(){
            SDL_DestroyWindow(this->MWindow);
            SDL_Quit();
        }
    private:
        SDL_Window * MWindow;
        SDL_Event Event;
        Map * CurrentMap;
        uint32_t FPS = 75;
        uint32_t Begin = 0;
};

#endif
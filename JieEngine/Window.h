#ifndef WINDOW_H_F
#define WINDOW_H_F

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
            构造函数 参数为 窗口标题 窗口图标
        */
        Window(const char * WindowTitle,const char * WindowIcon){
            SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVERYTHING);
            Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
            IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
            this->MWindow = SDL_CreateWindow(WindowTitle,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_W,WINDOW_H,SDL_WINDOW_SHOWN);
            if(WindowIcon != nullptr){
                SDL_SetWindowIcon(this->MWindow,IMG_Load(WindowIcon));
            }
            Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
            this->WindowSurface = SDL_GetWindowSurface(this->MWindow);
        }
        /*
            窗口事件监听函数
        */
        void ListenEvent(){
            while(true){
                if(SDL_GetTicks() - this->Begin < (1000/this->FPS))
                {
                    SDL_Delay((1000/this->FPS) - SDL_GetTicks() + this->Begin);
                }

                if(SDL_PollEvent(&this->Event)){
                    if(Event.type == SDL_QUIT){
                        this->CloseWindow();
                        return;
                    }else{
                        CurrentMap->WindowEvent(this->Event);
                    }
                }

                this->CurrentMap->Update();

                SDL_UpdateWindowSurface(this->MWindow);

                this->Begin = SDL_GetTicks();
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
            IMG_Quit();
            Mix_Quit();
            SDL_Quit();
        }
        /*
            释放资源函数
        */
        void Free(){
            this->CurrentMap->Free();
            SDL_DestroyWindow(this->MWindow);
        };
    private:
        SDL_Window * MWindow;
        SDL_Event Event;
        Map * CurrentMap;
        uint32_t FPS = 75;
        uint32_t Begin = 0;
};

#endif
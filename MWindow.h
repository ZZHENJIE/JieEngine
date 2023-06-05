#ifndef MWINDOW_H
#define MWINDOW_H

#include <SDL2/SDL.h>

enum WindowEvent{
    WindowExit,
    KeyPad_A,
    KeyPad_D,
    KeyPad_W,
    KeyPad_S,
};

class MWindow{
    private:
        SDL_Window * Window;
        SDL_Event Event;
    public:
        MWindow(const char * WindowTitle,unsigned int W,unsigned int H){
            this->Window = SDL_CreateWindow(WindowTitle,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,SDL_WINDOW_SHOWN);
        }
        ~MWindow(){
            SDL_DestroyWindow(this->Window);
        }
        SDL_Window * GetWindow(){
            return Window;
        }
        SDL_Surface * GetWindowSurface(){
            return SDL_GetWindowSurface(this->Window);
        }
        WindowEvent ListenEvent(){
            while(true){
                if(SDL_PollEvent(&Event)){
                    if(Event.type == SDL_QUIT){
                        return WindowExit;
                    }else{
                        switch(Event.key.keysym.sym){
                            case SDLK_a:{
                                return KeyPad_A;
                            }
                            case SDLK_d:{
                                return KeyPad_D;
                            }
                            case SDLK_w:{
                                return KeyPad_W;
                            }
                            case SDLK_s:{
                                return KeyPad_S;
                            }
                        }
                    }
                }
                SDL_UpdateWindowSurface(this->Window);
            }
        }
};

#endif
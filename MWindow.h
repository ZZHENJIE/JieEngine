#ifndef MWINDOW_H
#define MWINDOW_H

#include "Animal.h"
#include "Still.h"

class MWindow{
    private:
        SDL_Window * Window = nullptr;
        SDL_Event Event;
        uint32_t FPS = 60;
        uint32_t Begin = 0;
        Animal ** AnimalArray = nullptr;
        Still ** StillArray = nullptr;
        short AnimalNumber = 0;
        short StillNumber = 0;
        short NowAnimalNumber = 0;
        short NowStillNumber = 0;
    public:
        MWindow(const char * WindowTitle,unsigned int W,unsigned int H){
            this->Window = SDL_CreateWindow(WindowTitle,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,SDL_WINDOW_SHOWN);
        }
        ~MWindow(){
            SDL_DestroyWindow(this->Window);
            delete[] AnimalArray;
            delete[] StillArray;
        }
        void SetAnimalStillNumber(short AnimalNumber,short StillNumber){
            if(AnimalNumber != 0){
                AnimalArray = new Animal * [AnimalNumber];
            }
            if(AnimalNumber != 0){
                StillArray = new Still * [StillNumber];
            }
            this->AnimalNumber = AnimalNumber;
            this->StillNumber = StillNumber;
        }
        void AddAnima(Animal * animal){
            if(NowAnimalNumber <= AnimalNumber){
                AnimalArray[NowAnimalNumber] = animal;
                NowAnimalNumber ++;
            }else{
                SDL_Log("超出最大Animal类储存大小,报错函数MWindow->AddAnima()");
                exit(0);
            }
        }
        void AddStill(Still * still){
            if(NowStillNumber <= StillNumber){
                StillArray[NowStillNumber] = still;
                NowStillNumber ++;
            }else{
                SDL_Log("超出最大Still类储存大小,报错函数MWindow->AddStill()");
                exit(0);
            }
        }
        void SetFPS(int FPS){
            this->FPS = FPS;
        }
        SDL_Window * GetWindow(){
            return Window;
        }
        SDL_Surface * GetWindowSurface(){
            return SDL_GetWindowSurface(this->Window);
        }
        SDL_EventType ListenEvent(){
            while(true){
                if(SDL_GetTicks() - Begin < (1000/FPS))
                {
                    SDL_Delay((1000/FPS) - SDL_GetTicks() + Begin);
                }
                if(AnimalNumber != 0){
                    for(short i = 0; i < AnimalNumber; i++){
                        AnimalArray[i]->Update();
                        if(StillNumber != 0){
                            for(short j = 0; j < StillNumber; j++){
                                StillArray[j]->Update();
                                AnimalArray[i]->Detect(*StillArray[j]);
                            }
                        }
                    }
                }
                if(SDL_PollEvent(&Event)){
                    if(Event.type == SDL_QUIT){
                        return SDL_QUIT;
                    }else{
                        switch(Event.key.keysym.sym){
                            case SDLK_w:{
                                for(short i = 0; i < AnimalNumber; i++){
                                    if(strcmp(AnimalArray[i]->GetClass(),"Player") == 0){
                                        AnimalArray[i]->Up();
                                    }
                                }
                                break;
                            }
                            case SDLK_s:{
                                for(short i = 0; i < AnimalNumber; i++){
                                    if(strcmp(AnimalArray[i]->GetClass(),"Player") == 0){
                                        AnimalArray[i]->Down();
                                    }
                                }
                                break;
                            }
                            case SDLK_a:{
                                for(short i = 0; i < AnimalNumber; i++){
                                    if(strcmp(AnimalArray[i]->GetClass(),"Player") == 0){
                                        AnimalArray[i]->Left();
                                    }
                                }
                                break;
                            }
                            case SDLK_d:{
                                for(short i = 0; i < AnimalNumber; i++){
                                    if(strcmp(AnimalArray[i]->GetClass(),"Player") == 0){
                                        AnimalArray[i]->Right();
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                SDL_UpdateWindowSurface(this->Window);
                Begin = SDL_GetTicks();
            }
        }
};

#endif
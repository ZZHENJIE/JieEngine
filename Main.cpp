#include "MWindow.h"

#define WINDOW_W 500
#define WINDOW_H 500

int main(int argc, char * argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    MWindow * Window = new MWindow("JieEngine",WINDOW_W,WINDOW_H);

    while(true){
        switch(Window->ListenEvent()){
            case WindowEvent::WindowExit:{
                return 0;
                break;
            }
            case WindowEvent::KeyPad_W:{
                break;
            }
            case WindowEvent::KeyPad_S:{
                break;
            }
            case WindowEvent::KeyPad_A:{
                break;
            }
            case WindowEvent::KeyPad_D:{
                break;
            }
        }
    }
}
#include "Window.h"
#include "./TestGame/OneMapBackground.h"
#include "./TestGame/OneMapStruct.h"

int main(int argc, char * argv[]){

    Window * MWindow = new Window("JieEngine测试",".\\Resource\\Logo.bmp",WINDOW_W,WINDOW_H);

    MapBackground * OneMapbackground = new OneMapBackground(MWindow->GetWindowSurface());

    MapStruct * OneMapstruct = new OneMapStruct(MWindow->GetWindowSurface());

    Map * One = new Map(OneMapbackground,OneMapstruct,MWindow->GetWindowSurface());

    MWindow->SetMap(One);

    MWindow->ListenEvent();

    return 0;
}
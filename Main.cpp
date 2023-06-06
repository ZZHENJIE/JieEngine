#include "Window.h"
#include "./TestGame/OneMapBackground.h"
#include "./TestGame/OneMapStruct.h"

int main(int argc, char * argv[]){

    Window * MWindow = new Window("JieEngine测试",NULL,600,500);

    MapBackground * OneMapbackground = new OneMapBackground(".\\Resource\\Background.bmp",MWindow->GetWindowSurface());

    MapStruct * OneMapstruct = new OneMapStruct(MWindow->GetWindowSurface());

    Map * One = new Map(OneMapbackground,OneMapstruct,MWindow->GetWindowSurface());

    MWindow->SetMap(One);

    MWindow->ListenEvent();

    return 0;
}
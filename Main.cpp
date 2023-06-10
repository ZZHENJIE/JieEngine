#include "include/Window.h"
#include "include/Map.h"
#include "MainMapBackground.h"
#include "MainMapStruct.h"

int main(int argc, char *argv[])
{   
    Window * MWindow = new Window("JieEngine",nullptr);
    
    MainMapBackground * MainMapbackground = new MainMapBackground(MWindow->GetWindowSurface());

    MainMapStruct * MainMapstruct = new MainMapStruct(MWindow->GetWindowSurface());

    Map * MainMap = new Map(MainMapbackground,MainMapstruct,MWindow->GetWindowSurface());

    MWindow->SetMap(MainMap);

    MWindow->ListenEvent();

    return 0;
}
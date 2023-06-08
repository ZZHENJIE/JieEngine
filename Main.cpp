#include "JieEngine/Window.h"
#include "MainMapBackground.h"
#include "MainMapStruct.h"
#include "JieEngine/Map.h"

int main(int argc, char *argv[])
{   
    Window * MWindow = new Window("JieEngine",nullptr);
    
    MainMapBackground * MainMapbackground = new MainMapBackground(MWindow->GetWindowSurface());

    MainMapStruct * MainMapstruct = new MainMapStruct(MWindow->GetWindowSurface());

    Map * MainMap = new Map(MainMapbackground,MainMapstruct,MWindow->GetWindowSurface());

    MWindow->SetMap(MainMap);

    MWindow->ListenEvent();

    MWindow->Free();

    return 0;
}
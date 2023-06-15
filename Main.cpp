#include "JieEngine/Window.h"
#include "MainMapStruct.h"

int main(int argc, char *argv[])
{   
    Window * MWindow = new Window("JieEngine",nullptr);
    
    MWindow->SetMap(new MainMapStruct(MWindow->GetWindowSurface()));

    MWindow->ListenEvent();

    return 0;
}
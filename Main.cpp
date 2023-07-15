#include "Game.h"
#include "../Example/OneMap.hpp"

int main(int argc,char * argv[])
{
    auto MWindow = std::make_shared<Game>("JieEngine",500,600);

    auto One = std::make_shared<OneMap>();

    MWindow.get()->SetGameMap(One.get());

    return 0;
}
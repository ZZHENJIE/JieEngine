#include "Game.h"
#include "../Example/OneMap.hpp"

int main(int argc,char * const argv[])
{
    auto MWindow = std::make_shared<Game>("Test",500,500);

    auto One = std::make_shared<OneMap>();

    MWindow.get()->SetGameMap(One.get());

    return 0;
}
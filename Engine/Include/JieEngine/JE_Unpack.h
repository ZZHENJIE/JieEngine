#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEUnpackData;

class JEUnpackData final{
    public:
        JEUnpackData(string FileUrl);
        SDL_Surface * Image(string FileName);
        Mix_Chunk * Mixer(string FileName);
        TTF_Font * Font(string FileName,int FontSize);
        string ErrorMessage;
    private:
        map<string,JEFileData> _Data;
};

};
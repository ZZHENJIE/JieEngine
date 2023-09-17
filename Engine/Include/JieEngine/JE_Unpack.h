#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEUnpackData;

JEUnpackData * JEUnpack(string FileUrl);

class JEUnpackData final{
    public:
        SDL_Surface * Image(string FileName);
        Mix_Chunk * Mixer(string FileName);
        TTF_Font * Font(string FileName,int FontSize);
        string ErrorMessage;
    private:
        friend JEUnpackData * JEUnpack(string FileUrl);
        unordered_map<string,JEFileData> _Data;
};

};
#pragma once

#include "Component.h"

using namespace std;

namespace JieEngine{

    class UnpackData;

    struct FileData final{
        char * Data;
        int Size;
    };

    UnpackData Unpack(string FileUrl);

    class UnpackData final{
        public:
            SDL_Surface * Image(string FileName);
            Mix_Chunk * Mixer(string FileName);
            TTF_Font * Font(string FileName,int FontSize);
            string ErrorMessage;
        private:
            friend UnpackData Unpack(string FileUrl);
            unordered_map<string,FileData> _Data;
    };
};
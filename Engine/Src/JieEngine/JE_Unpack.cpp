#include "JieEngine/JE_Unpack.h"

using namespace JieEngine;

SDL_Surface * JEUnpackData::Image(string FileName){
    if(this->_Data.find(FileName) != this->_Data.end()){
        return IMG_Load_RW(SDL_RWFromMem(this->_Data.at(FileName).Data, this->_Data.at(FileName).Size),1);
    }
    return nullptr;
}

Mix_Chunk * JEUnpackData::Mixer(string FileName){
    if(this->_Data.find(FileName) != this->_Data.end()){
        return Mix_LoadWAV_RW(SDL_RWFromMem(this->_Data.at(FileName).Data, this->_Data.at(FileName).Size),1);
    }
    return nullptr;
}

TTF_Font * JEUnpackData::Font(string FileName,int FontSize){
    if(this->_Data.find(FileName) != this->_Data.end()){
        return TTF_OpenFontRW(SDL_RWFromMem(this->_Data.at(FileName).Data, this->_Data.at(FileName).Size),1,FontSize);
    }
    return nullptr;
}
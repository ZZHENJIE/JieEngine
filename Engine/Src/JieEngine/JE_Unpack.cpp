#include "JieEngine/JE_Unpack.h"

using namespace JieEngine;

JEUnpackData::JEUnpackData(string FileUrl){
    ifstream File;
    File.open(FileUrl, ios::binary);
    char Buffer[512];
    long Count = 0;
    if (!File) {
        this->ErrorMessage = "Unable to open file: " + FileUrl;
    }else{
        while (File.read(Buffer,1)){
            string Num;
            string Name;
            while(true){
                Num += Buffer;
                if(Num.find_first_of("|",0) > 0 && Num.find_first_of("|",0) < 1024){
                    break;
                }
                File.read(Buffer,1);
            }
            Num.pop_back();
            Count = stoi(Num);
            while(true){
                File.read(Buffer,1);
                Name += Buffer;
                if(Name.find_first_of("|",0) > 0 && Name.find_first_of("|",0) < 1024){
                    break;
                }
            }
            Name.pop_back();
            this->_Data[Name].Data = new char[Count];
            this->_Data[Name].Size = Count;
            for(long i = 0; i < Count; i++){
                File.read(Buffer,1);
                strcpy(&this->_Data[Name].Data[i],Buffer);
            }
        }
    }
    File.close();
}

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
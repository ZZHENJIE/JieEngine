#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEUnpackData;

class JEUnpackData final{
    public:
        JEUnpackData(string FileUrl){
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
        SDL_Surface * Image(string FileName);
        Mix_Chunk * Mixer(string FileName);
        TTF_Font * Font(string FileName,int FontSize);
        string ErrorMessage;
    private:
        unordered_map<string,JEFileData> _Data;
};

};
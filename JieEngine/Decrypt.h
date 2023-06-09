#ifndef DECRYPT_H
#define DECRYPT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string.h>

class Decrypt{
    public:
        static SDL_Surface * DecryptImage(const char * FileUrl){

            SDL_RWops * io = SDL_RWFromFile(FileUrl, "rb");

            if (io != NULL) {
                int Size = io->size(io);
                char * Temp = new char[Size];
                char * Data = new char[Size - 10];
                
                if (SDL_RWread(io, Temp, Size, 1) > 0) {
                    for(int i = 10; i < Size; i++){
                        Data[i - 10] = Temp[i];
                    }
                    return IMG_Load_RW(SDL_RWFromMem(Data, Size - 10),1);
                }
            }
            
            return nullptr;
        }

        static Mix_Chunk * DecryptMixer(const char * FileUrl){

            SDL_RWops * io = SDL_RWFromFile(FileUrl, "rb");

            if (io != NULL) {
                int Size = io->size(io);
                char * Temp = new char[Size];
                char * Data = new char[Size - 10];
                
                if (SDL_RWread(io, Temp, Size, 1) > 0) {
                    for(int i = 10; i < Size; i++){
                        Data[i - 10] = Temp[i];
                    }
                    return Mix_LoadWAV_RW(SDL_RWFromMem(Data, Size - 10),1);
                }
            }
            
            return nullptr;
        }
};

#endif
#ifndef DECRYPT_H
#define DECRYPT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <string.h>

class Decrypt{
    public:
        static SDL_Surface * DecryptImage(const char * FileUrl);

        static Mix_Chunk * DecryptMixer(const char * FileUrl);
};

#endif
#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

JEContainer<JEUnInt> JieEngine::MixerChannel = JEContainer<JEUnInt>(-1);

JELog JieEngine::JECreateAudio(const char * SoundName,JEAudio & Data,JEUnInt Volume){
    Mix_Chunk * Chunk = Resource.ResourceFile->Mixer(SoundName);
    if(Chunk != nullptr){
        Data.Sound = Chunk;
    }else{
        return RESOURCE_LOAD_ERROR;
    }
    Data.Volume = Volume;
    Data.Channel = MixerChannel.Add(1);
    MixerChannel[Data.Channel] = Data.Channel;
    Mix_Volume(Data.Channel,Data.Volume);
    return SUCCEED;
}

void JieEngine::JEDestroyAudio(JEAudio & Data){
    Mix_FreeChunk(Data.Sound);
    MixerChannel.Remove(Data.Channel);
}
#include "JieEngine/JE_System.h"
#include "JieEngine/JE_Component.h"
#include "JieEngine/JE_Unpack.h"
#include "JieEngine/JE_Box2DFunction.h"

using namespace JieEngine;

JEContainer<JEUnInt> JieEngine::MixerChannel = JEContainer<JEUnInt>(-1);

JELog JieEngine::JECreateAudio(unordered_map<string,string> ChunkResource,JEAudio & Data,JEUnInt Volume){
    for(auto Iterate : ChunkResource){
        Mix_Chunk * Chunk = Resource.ResourceFile->Mixer(Iterate.second);
        if(Chunk != nullptr){
            Data.Sound[Iterate.first] = Chunk;
        }else{
            return RESOURCE_LOAD_ERROR;
        }
    }
    Data.Volume = Volume;
    Data.Channel = MixerChannel.Add(1);
    MixerChannel[Data.Channel] = Data.Channel;
    Mix_Volume(Data.Channel,Data.Volume);
    return SUCCEED;
}
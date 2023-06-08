#ifndef MIXER_H
#define MIXER_H

#include <SDL2/SDL_mixer.h>

class Mixer{
    public:
        /*
            获取类名 后期更好对 对象进行一个判断 JieEngine 每个类都有这个函数
        */
        virtual const char * GetClass(){
            return "Mixer";
        }
        /*
            设置声音大小
        */
        void SetVolume(short Volume){
            this->Volume = Volume;
            Mix_Volume(this->Channel,this->Volume);
        }
        /*
            构造函数 参数 文件路经 声道
        */
        Mixer(const char * FileUrl,unsigned short Channel){
            this->Sound = Mix_LoadWAV(FileUrl);
            this->Channel = Channel;
        }
        /*
            播放音效 参数 播放次数 默认播放一遍
        */
        void Play(int Loop = 1){
            Mix_PlayChannel(this->Channel,this->Sound,Loop - 1);
        }
        /*
            暂停播放音效
        */
        void Pause(){
            Mix_Pause(this->Channel);
        }
        /*
            恢复播放音效
        */
        void Resume(){
            Mix_Resume(this->Channel);
        }
        /*
            释放音频
        */
        void Free(){
            Mix_FreeChunk(this->Sound);
        }
    private:
        Mix_Chunk * Sound;
        short Channel;
        short Volume = 50;
};

#endif
#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JEWorld;
class JEEntity;

extern JEGlobalResourceComponent Resource;

class JEMap{
public:
    JEMap();
    ~JEMap();
    friend JEWorld;
private:
    virtual void Update() = 0;
    virtual void Event(SDL_Event Event) = 0;
    virtual void _MapUpdate() final;
    virtual void _MapEvent(SDL_Event Event) final;
protected:
    vector<shared_ptr<JEEntity>> EntityManage;
};

};
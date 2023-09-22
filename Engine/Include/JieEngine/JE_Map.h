#pragma once

#include "JE_Struct.h"
#include "JE_Entity.h"

namespace JieEngine{

using namespace std;

class JEWorld;

class JEMap{
public:
    JEMap();
    ~JEMap();
    template <typename T>
    void AddEntity(shared_ptr<T> Entity){
        this->EntityManage.push_back(Entity);
        this->EntityManage.at(this->EntityManage.size() - 1)->_Lock = false;
    }
    template <typename T>
    void AddEntity(){
        this->EntityManage.push_back(make_shared<T>());
        this->EntityManage.at(this->EntityManage.size() - 1)->_Lock = false;
    }
    virtual void RemoveEntity(JEUnInt EntityID) final;
private:

    friend JEWorld;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Event(SDL_Event Event) = 0;
    virtual void _MapUpdate() final;
    virtual void _MapEvent(SDL_Event Event) final;
    vector<shared_ptr<JEEntity>> EntityManage;
};

};
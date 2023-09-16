#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

class JESystem final{

public:

    JESystem();

    void Update();

    void AddFunction(void(*Function)(JEUnInt EntityID));

    void RemoveFunction(void(*Function)(JEUnInt EntityID));

private:

    vector<void(*)(JEUnInt EntityID)> _FunctionList;

};

}
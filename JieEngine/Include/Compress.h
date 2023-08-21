#pragma once

#include "Component.h"

using namespace std;

namespace JieEngine{

    struct CompressData final{
        string Message;
        bool Succeed;
    };

    struct CompressFileInfo final{
        string Url;
        string Name;
    };
    
    CompressData Compress(vector<CompressFileInfo> SrcFile,string OutFile);
};
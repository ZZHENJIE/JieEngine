#pragma once

#include "JE_Struct.h"

namespace JieEngine{

using namespace std;

JECompressData JECompress(vector<JECompressFileInfo> SrcFile,string OutFile);

};
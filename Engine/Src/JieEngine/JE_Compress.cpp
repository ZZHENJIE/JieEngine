#include "JieEngine/JE_Compress.h"

using namespace JieEngine;

JECompressData JieEngine::JECompress(vector<JECompressFileInfo> SrcFile,string OutFile){
    ofstream EncryptFile;
    EncryptFile.open(OutFile, ios::binary);
    if(!EncryptFile){
        return{
            "Unable to open file: " + OutFile,false
        };
    }
    char Buffer[1024];
    long Sum = 0;
    int Count = 0;
    for(auto FileName : SrcFile){
        ifstream File;
        strcpy(Buffer,"");
        Sum = 0;
        Count = 0;
        File.open(FileName.Url, ios::binary);
        if (!File) {
            return{
                "Unable to open file: " + FileName.Url,false
            };
        }else{
            while (!File.eof()){
                File.read(Buffer, 1024);
                Sum += File.gcount();
            }
            File.close();
            File.open(FileName.Url, ios::binary);
            string JieEngine = to_string(Sum) + "|" + FileName.Name + "|";
            EncryptFile.write(JieEngine.c_str(), JieEngine.size());
            while (!File.eof()){
                File.read(Buffer, 1024);
                Count = File.gcount();
                EncryptFile.write(Buffer,Count);
            }
        }
        File.close();
    }
    EncryptFile.close();
    return{
        "Succeed!",true
    };
}
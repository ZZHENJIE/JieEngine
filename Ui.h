#ifndef UI_H
#define UI_H

#include "JieEngine.h"

class Ui : public JieEngine{
    public:
        virtual const char * GetClass(){
            return "UI";
        }
};

#endif
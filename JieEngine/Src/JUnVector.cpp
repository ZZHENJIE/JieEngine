#include "JUnVector.h"

using namespace JieEngine;

JUnVector::JUnVector(){
    this->_Size = 0;
    this->_Capacity = 1;
    this->_Array = new JUnInt[this->_Capacity];
    for(int i = 0; i < this->_Capacity; i++){
        this->_Array[i] = -1;
    }
}

JUnVector::~JUnVector(){
    delete [] this->_Array;
}

JUnInt JUnVector::At(int Index){
    return this->_Array[Index];
}

JUnInt JUnVector::Size(){
    return this->_Size;
}

JUnInt JUnVector::Capacity(){
    return this->_Capacity;
}

JUnInt * JUnVector::Begin(){
    return this->_Array;
}

int JUnVector::Push(JUnInt Value){
    if(Value < __UINT32_MAX__){
        this->_Size++;
        if(this->_Size == this->_Capacity){
            this->_Capacity *= 2;
            JUnInt * Temp = new JUnInt[this->_Capacity];
            for(int i = 0; i < this->_Capacity; i++){
                Temp[i] = -1;
            }
            for(int i = 0; i < this->_Size; i++){
                Temp[i] = this->_Array[i];
            }
            delete [] this->_Array;
            this->_Array = Temp;
        }
        for(int i = 0; i < this->_Capacity; i++){
            if(this->_Array[i] == -1){
                this->_Array[i] = Value;
                return i;
            }
        }
    }
    return -1;
}

void JUnVector::Remove(int Index){
    this->_Size --;
    this->_Array[Index] = -1;
}

void JUnVector::SetCapacity(JUnInt Value){
    this->_Capacity = Value;
    JUnInt * Temp = new JUnInt[this->_Capacity];
    for(int i = 0; i < this->_Capacity; i++){
        if(i < this->_Size){
            Temp[i] = this->_Array[i];
        }else{
            Temp[i] = -1;
        }
    }
    delete [] this->_Array;
    this->_Array = Temp;
}

void JUnVector::Clear(){
    this->_Size = 0;
    delete [] this->_Array;
    this->_Array = new JUnInt[this->_Capacity];
    for(int i = 0; i < this->_Capacity; i++){
        this->_Array[i] = -1;
    }
}

bool JUnVector::IsEmpty(){
    for(int i = 0; i < this->_Size; i++){
        if(this->_Array[i] != -1){
            return false;
        }
    }
    return true;
}
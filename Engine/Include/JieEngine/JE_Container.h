#pragma once

/*
    根据构造函数设置的参数来表示在数据中的Null
    方法名:              用法:
    JEContainer          默认无参构造函数调用后 使用前必须调用SetNull 设置Null值否则程序会崩溃
    JEContainer          构造函数需要设置Null值
    JEContainer          拷贝构造函数
    At                  获取索引值
    Size                获取容器数据数量
    Capacity            获取容器容量
    []                  可以使用数组方式进行访问和修改
    =                   就是拷贝构造函数
    Add                 往容器添加数据会返回在容器中的索引 会寻找为Null值的空缺
    Remove              将索引数据设为Null值
    SetCapacity         设置容器容量
    Clear               清空容器数据并把所有数据初始化为Null
    IsEmpty             判断容器是否为空
    SetNull             设置Null值 使用无参默认构造函数后调用的
    begin               返回只有数据的数组没有Null值
    end                 返回begin数组结束的指针
*/

namespace JieEngine{
    template <typename T>
    class JEContainer final{
        public:
            JEContainer(){
                this->_Size = 0;
                this->_Capacity = 1;
                this->_Array = new T[this->_Capacity];
                this->_Iterate = new T[this->_Capacity];
            }
            JEContainer(T Type){
                this->_Size = 0;
                this->_Capacity = 1;
                this->_Array = new T[this->_Capacity];
                this->_Iterate = new T[this->_Capacity];
                this->SetNull(Type);
            }
            JEContainer(JEContainer *& Ptr){
                this->_Size = Ptr->_Size;
                this->_Capacity = Ptr->_Capacity;
                this->_Array = Ptr->_Array;
                this->_Iterate = Ptr->_Iterate;
                this->_Null = Ptr->_Null;
            }
            ~JEContainer(){
                delete [] this->_Array;
                delete [] this->_Iterate;
            }
            inline T At(int Index){
                return this->_Array[Index];
            }
            inline int Size(){
                return this->_Size;
            }
            inline int Capacity(){
                return this->_Capacity;
            }
            T & operator [] (int Index){
                if(Index >= this->_Capacity - 1){
                    this->_Capacity = Index;
                    T * Temp = new T[this->_Capacity];
                    for(int i = 0; i < this->_Capacity; i++){
                        if(i < this->_Size){
                            Temp[i] = this->_Array[i];
                        }else{
                            Temp[i] = this->_Null;
                        }
                    }
                    delete [] this->_Array;
                    this->_Array = Temp;
                }
                return this->_Array[Index];
            }
            void operator = (JEContainer *& Ptr){
                this->_Size = Ptr->_Size;
                this->_Capacity = Ptr->_Capacity;
                this->_Array = Ptr->_Array;
                this->_Iterate = Ptr->_Iterate;
                this->_Null = Ptr->_Null;
            }
            int Add(T Value){
                this->_Size ++;
                int EmptyPos = -1;
                if(this->_Size >= this->_Capacity){
                    this->_Capacity *= 2;
                    T * Temp = new T[this->_Capacity];
                    for(int i = 0; i < this->_Capacity; i++){
                        if(i < this->_Size){
                            Temp[i] = this->_Array[i];
                            if(Temp[i] == this->_Null){
                                EmptyPos = i;
                            }
                        }else{
                            Temp[i] = this->_Null;
                        }
                    }
                    delete [] this->_Array;
                    this->_Array = Temp;
                }else{
                    for(int i = 0; i < this->_Size; i++){
                        if(this->_Array[i] == this->_Null){
                            EmptyPos = i;
                            break;
                        }
                    }
                }
                if(EmptyPos != -1){
                    this->_Array[EmptyPos] = Value;
                }else{
                    EmptyPos = this->_Size - 1;
                    this->_Array[EmptyPos] = Value;
                }
                return EmptyPos;
            }
            void Remove(int Index){
                this->_Size --;
                this->_Array[Index] = this->_Null;
            }
            void SetCapacity(int Capacity){
                this->_Capacity = Capacity;
                T * Temp = new T[this->_Capacity];
                for(int i = 0; i < this->_Capacity; i++){
                    if(i < this->_Size){
                        Temp[i] = this->_Array[i];
                    }else{
                        Temp[i] = this->_Null;
                    }
                }
                delete [] this->_Array;
                this->_Array = Temp;
            }
            void Clear(){
                T * Temp = new T[this->_Capacity];
                for(int i = 0; i < this->_Capacity; i++){
                    Temp[i] = this->_Null;
                }
                delete [] this->_Array;
                this->_Array = Temp;
            }
            bool IsEmpty(){
                return !this->_Size;
            }
            void SetNull(T Value){
                this->_Null = Value;
                this->_Array[0] = this->_Null;
            }
            T * begin() {
                delete [] this->_Iterate;
                this->_Iterate = new T[this->_Size];
                int Count = 0;
                for(int i = 0; i < this->_Capacity; i++){
                    if(this->_Array[i] != this->_Null){
                        this->_Iterate[Count] = this->_Array[i];
                        Count++;
                    }
                }
                return this->_Iterate;
            }
            T * end() {
                return this->_Iterate + this->_Size;
            }
        private:
            T * _Array;
            T * _Iterate;
            T _Null;
            int _Size;
            int _Capacity;
    };
};

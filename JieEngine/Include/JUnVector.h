#pragma once

namespace JieEngine{

    using JUnInt = __UINT32_TYPE__;

    class JUnVector final {
        public:
            JUnVector();
            ~JUnVector();
            inline JUnInt At(int Index);
            JUnInt Size();
            JUnInt Capacity();
            JUnInt * Begin();
            int Push(JUnInt Value);
            void SetCapacity(JUnInt Value);
            void Remove(int Index);
            void Clear();
            bool IsEmpty();
        private:
            JUnInt _Size;
            JUnInt _Capacity;
            JUnInt * _Array;
    };
};
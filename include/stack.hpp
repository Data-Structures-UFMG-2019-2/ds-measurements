#include"./cell.hpp"

template<class T>
class Stack{
    private:
        int size;
        Cell<T>* top;
    public:
        Stack();
        ~Stack();
        int length();
        void push(T* object);
        T* pop();
        T* peek();
};

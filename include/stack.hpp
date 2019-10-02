#ifndef STACK_H
#define STACK_H

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

#endif
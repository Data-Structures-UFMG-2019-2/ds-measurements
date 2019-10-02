#include"../include/stack.hpp"
#include"../include/operation.hpp"

template<class T>
Stack<T>::Stack(){
    this->size = 0;
    this->top = nullptr;
}

template<class T>
Stack<T>::~Stack(){

}

template<class T>
int Stack<T>::length(){
    return this->size;
}

template<class T>
void Stack<T>::push(T* object){
    Cell<T>* cell = new Cell<T>(object);

    if(this->size == 0){
        this->top = cell;
    }
    else{
        this->top->next = cell;
        cell->prev = this->top;
        this->top = cell;
    }
    ++this->size;
}

template<class T>
T* Stack<T>::pop(){
    Cell<T>* cell = this->top;
    T* object = cell->object;
    this->top = cell->prev;
    --this->size;
    delete cell;
    return object;
}

template<class T>
T* Stack<T>::peek(){
    return this->top->object;
}

template<class T>
void Stack<T>::clear(){
    if(this->size > 0){
        this->top->cascade_clear(BACKWARD);
        delete this->top;
        this->top = nullptr;
        this->size = 0;
    }
}

template class Stack<Operation>;
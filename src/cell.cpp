#include "../include/cell.hpp"
#include "../include/vessel.hpp"

template<class T>
Cell<T>::Cell(T* object){
    this->object = object;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
Cell<T>::~Cell(){
}

template class Cell<Vessel>;
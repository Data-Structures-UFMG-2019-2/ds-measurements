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

template<class T>
void Cell<T>::cascade_clear(int direction){
    if(direction == FORWARD){
        if(this->next != nullptr){
            this->next->cascade_clear(FORWARD);
            delete this->object;
            delete this->next;
        }
    }
    else if(direction == BACKWARD){
        if(this->prev != nullptr){
            this->prev->cascade_clear(BACKWARD);
            delete this->prev;
            delete this->object;
        }
    }
}

template class Cell<Vessel>;
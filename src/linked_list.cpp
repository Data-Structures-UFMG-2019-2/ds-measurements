#include"../include/linked_list.hpp"

LinkedList::LinkedList(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

LinkedList::~LinkedList(){

}

int LinkedList::length(){
    return this->size;
}

template <class T>
void LinkedList::add(T* object){
    Cell<T> cell = new Cell<T>(object);

    if(this->size == 0){
        this->first = cell;
        this->last = cell;
    }
    else if(this->size > 0){
        cell->prev = this->last;
        this->last->next = cell;
        this->last = cell;
    }
}

template <class T>
T* LinkedList::get(int i){
    Cell<T>* cell;
    if(i < 0){
        i = this->size + i;
    }
    if(i >= this->size){
        return nullptr;
    }
    else{
        if(i <= (float)this->size/2.0){
            cell = this->from_front(i);
        }
        else{
            cell = this->from_back(i-this->size-1);
        }
        return cell != nullptr ? cell->object : nullptr;
    }
}

Cell<class T>* LinkedList::from_back(int i){
    int cell_i = 0;
    for (Cell<class T>* cell = this->last; cell != nullptr; cell = cell->prev, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

Cell<class T>* LinkedList::from_front(int i){
    int cell_i = 0;
    for (Cell<class T>* cell = this->first; cell != nullptr; cell = cell->next, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

void LinkedList::remove(int i){
    int cell_i = 0;
    if(i >= this->size){
        return;
    }
    else if(i == 0){

    }
    for (Cell<class T>* cell = this->first->next; cell != nullptr; cell = cell->next, cell_i++){
        if(cell_i == i){
            
        }
    }
}
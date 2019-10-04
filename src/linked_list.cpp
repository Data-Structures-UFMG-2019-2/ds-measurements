#include<string>
#include<sstream>
#include<iostream>

#include"../include/linked_list.hpp"
#include"../include/vessel.hpp"
#include"../include/operation.hpp"

template<class T>
LinkedList<T>::LinkedList(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList(){

}

template<class T>
int LinkedList<T>::length(){
    return this->size;
}

template<class T>
void LinkedList<T>::add(T* object){
    Cell<T>* cell = new Cell<T>(object);

    if(this->size == 0){
        this->first = cell;
        this->last = cell;
    }
    else{
        cell->prev = this->last;
        this->last->next = cell;
        this->last = cell;
    }
    ++this->size;
}

template<class T>
void LinkedList<T>::insert_after(Cell<T>* cell, T* object){
    Cell<T>* new_cell = new Cell<T>(object);
    if(cell == nullptr){ // Insert at the beginning of the list when cell == NULL
        if(this->size == 0){
            this->first = cell;
            this->last = cell;
        }
        else{
            new_cell->next = this->first;
            this->first->prev = new_cell;
            this->first = new_cell;
        }
    }
    else{
        new_cell->prev = cell;
        new_cell->next = cell->next;
        cell->next = new_cell;
        if(cell == this->last){
            this->last = new_cell;
        }
        else{
            new_cell->next->prev = new_cell;
        }
    }
    ++this->size;
}

template<class T>
void LinkedList<T>::insert_before(Cell<T>* cell, T* object){
    Cell<T>* new_cell = new Cell<T>(object);
    if(cell == nullptr){ // Insert at the end of the list when cell == NULL
        if(this->size == 0){
            this->first = cell;
            this->last = cell;
        }
        else{
            new_cell->prev = this->last;
            this->last->next = new_cell;
            this->last = new_cell;
        }
    }
    else{
        new_cell->next = cell;
        new_cell->prev = cell->prev;
        cell->prev = new_cell;
        if(cell == this->first){
            this->first = new_cell;
        }
        else{
            new_cell->prev->next = new_cell;
        }
    }
    ++this->size;
}

template<class T>
T* LinkedList<T>::get(int i){
    Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else{
        if(i < 0){ // negative indexes get cells from the back of the list
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){ // if the cell is closer to the front
            cell = this->from_front(i);
        }
        else{ // if the cell is closer to the back
            cell = this->from_back((this->size-i)-1);
        }
        return cell != nullptr ? cell->object : nullptr;
    }
}

template<class T>
Cell<T>* LinkedList<T>::begin(){
    return this->first;
}

template<class T>
Cell<T>* LinkedList<T>::get_cell(int i){ // negative values for i return cells from the back of the list
    Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else{
        if(i < 0){
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){
            cell = this->from_front(i);
        }
        else{
            cell = this->from_back((this->size-i)-1);
        }
        return cell;
    }
}

template<class T>
Cell<T>* LinkedList<T>::from_back(int i){ // return i-th cell (starting at the end)
    int cell_i = 0;
    for (Cell<T>* cell = this->last; cell != nullptr; cell = cell->prev, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
Cell<T>* LinkedList<T>::from_front(int i){ // return i-th cell (starting at the beginning)
    int cell_i = 0;
    for (Cell<T>* cell = this->first; cell != nullptr; cell = cell->next, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
T* LinkedList<T>::remove(int i){ // negative values for i remove itens from the back of the list
    Cell<T>* cell = nullptr;
    T* object = nullptr;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else if(this->size == 1){
        cell = this->first;
        this->first = nullptr;
        this->last = nullptr;
    }
    else if(i == 0 || i == -this->size){ // cases where the element is first in the list
        cell = this->first;
        cell->next->prev = nullptr;
        this->first = cell->next;
    }
    else if(i == this->size-1 || i == -1){ // cases where the element is last in the list
        cell = this->last;
        cell->prev->next = nullptr;
        this->last = cell->prev;
    }
    else{
        cell = this->get_cell(i);
        cell->prev->next = cell->next;
        cell->next->prev = cell->prev;
    }
    --this->size;
    object = cell->object;
    delete cell;
    return object;
}

template<class T>
void LinkedList<T>::clear(){
    if(this->size > 0){
        this->first->cascade_clear(FORWARD);
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
}

template<class T>
void LinkedList<T>::clear(int strategy){
    if(strategy == ITERATIVE){
        while(this->size > 0){
            delete this->remove(0);
        }
    }
    else if(strategy == RECURSIVE){
        if(this->size > 0){
            this->first->cascade_clear(FORWARD);
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
    }
}

template class LinkedList<Vessel>;
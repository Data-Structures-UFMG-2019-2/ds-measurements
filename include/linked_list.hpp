#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include"./cell.hpp"

template <class T>
class LinkedList{
    private:
        int size;
        Cell<T>* first;
        Cell<T>* last;
        Cell<T>* from_back(int i);
        Cell<T>* from_front(int i);
    public:
        LinkedList();
        ~LinkedList();
        int length();
        void add(T* object);
        T* get(int i);
        Cell<T>* begin();
        Cell<T>* get_cell(int i);
        T* remove(int i);
        void clear();
};

#endif
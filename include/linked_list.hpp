#include"./cell.hpp"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList{
    private:
        int size;
        Cell<T>* first;
        Cell<T>* last;
        Cell<T>* from_back(int i);
        Cell<T>* from_front(int i);
        Cell<T>* get_cell(int i);
    public:
        LinkedList();
        ~LinkedList();
        int length();
        void add(T* object);
        T* get(int i);
        void remove(int i);
        void clear();
};

#endif
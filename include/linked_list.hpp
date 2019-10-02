#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define RECURSIVE 1
#define ITERATIVE -1

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
        void insert_after(Cell<T>* cell, T* object);
        void insert_before(Cell<T>* cell, T* object);
        T* get(int i);
        Cell<T>* begin();
        Cell<T>* get_cell(int i);
        T* remove(int i);
        void clear();
        void clear(int strategy);
};

#endif
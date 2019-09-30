#ifndef CELL_H
#define CELL_H

template <class T> class LinkedList;
template <class T> class Stack;

template <class T>
class Cell{
    private:
        T* object;
        Cell* next;
        Cell* prev;

        friend class LinkedList<T>;
        friend class Stack<T>;
    public:
        Cell(T* object);
        ~Cell();
};

#endif
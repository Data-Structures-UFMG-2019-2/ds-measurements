#ifndef CELL_H
#define CELL_H

#define FORWARD 1
#define BACKWARD 0

template <class T> class LinkedList;
template <class T> class Stack;

template <class T>
class Cell{
    private:
        T* object;
        Cell* next;
        Cell* prev;
        void cascade_clear(int direction);

        friend class LinkedList<T>;
        friend class Stack<T>;
    public:
        Cell(T* object);
        ~Cell();
        Cell<T>* operator++();
        Cell<T>* operator--();
        T* get_object();
        Cell<T>* get_next();
};

#endif
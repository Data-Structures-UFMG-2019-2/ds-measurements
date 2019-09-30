#ifndef CELL_H
#define CELL_H

template <class T>
class Cell{
    private:
        T* object;
        Cell* next;
        Cell* prev;

        friend class LinkedList;
    public:
        Cell(T* object);
        ~Cell();
};

#endif
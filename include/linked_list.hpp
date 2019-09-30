#include"./cell.hpp"

class LinkedList{
    private:
        int size;
        Cell<class T>* first;
        Cell<class T>* last;
        Cell<class T>* from_back(int i);
        Cell<class T>* from_front(int i);
    public:
        LinkedList();
        ~LinkedList();
        int length();
        template<class T> void add(T* object);
        template<class T> T* get(int i);
        void remove(int i);
};

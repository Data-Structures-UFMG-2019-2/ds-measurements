#include<iostream>
#include"./include/linked_list.hpp"
#include"./include/stack.hpp"
#include"./include/vessel.hpp"

int main(int argc, char const *argv[]){
    
    Vessel* v1 = new Vessel(30);
    Vessel* v2 = new Vessel(50);
    Vessel* v3 = new Vessel(60);
    Vessel* v4 = new Vessel(80);
    Vessel* v5 = new Vessel(100);
    LinkedList<Vessel>* list = new LinkedList<Vessel>();
    Stack<Vessel>* stack = new Stack<Vessel>();
    list->add(v1);
    list->add(v2);
    list->add(v3);
    list->add(v4);
    list->add(v5);

    for (int i = 0; i < list->length(); i++){
        Vessel* vessel = list->get(i);
        std::cout << vessel->get_capacity() << std::endl;
        stack->push(vessel);
    }

    while(stack->length() > 0){
        Vessel* vessel = stack->pop();
        std::cout << vessel->get_capacity() << std::endl;
        std::cout << stack->length() << std::endl;
    }

    list->clear();
    delete list;
    delete stack;
    
    return 0;
}

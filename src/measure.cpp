#include"../include/measure.hpp"
#include"../include/linked_list.hpp"
#include"../include/operation.hpp"

Measure::Measure(){
}

Measure::~Measure(){
}

void Measure::add_vessel(LinkedList<Vessel>* vessels, int q){
    Vessel* vessel = new Vessel(q);
    vessels->add(vessel);
}

void Measure::remove_vessel(LinkedList<Vessel>* vessels, int q){
    int cell_i = 0;
    for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next(), cell_i++){
        if(it->get_object()->get_capacity() == q){
            Vessel* vessel = vessels->remove(cell_i);
            if(vessel != nullptr){
                delete vessel;
            }
        }
    }
}

int Measure::min_measure(LinkedList<Vessel>* vessels, int q){
    LinkedList<Operation>* operations = new LinkedList<Operation>();
    int used = 1;

    for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next()){
        Vessel* vessel = it->get_object();
        int amount = vessel->get_capacity();
        if(amount == q){
            operations->clear();
            delete operations;
            return used;
        }
        operations->add(new Operation(used, amount));
    }
    while(true){
        for (Cell<Operation>* it = operations->begin(); it != nullptr; it = it->get_next()){
            
        }
    }
    delete operations;
}

void Measure::execute(LinkedList<Vessel>* vessels, char type, int q){
    switch (type){
        case 'i':
            Measure::add_vessel(vessels, q);
            break;

        case 'r':
            Measure::remove_vessel(vessels, q);
            break;

        case 'p':
            Measure::min_measure(vessels, q);
            break;

        default:
            break;
    }
}
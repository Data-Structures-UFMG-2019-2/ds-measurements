#include"../include/measure.hpp"

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
    for (Cell<Vessel>* it = vessels->get_cell(0); it != nullptr; it = it->get_next(), cell_i++){
        if(it->get_object()->get_capacity() == q){
            Vessel* vessel = vessels->remove(cell_i);
            if(vessel != nullptr){
                delete vessel;
            }
        }
    }
}

void Measure::min_measure(LinkedList<Vessel>* vessels, int q){
    
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
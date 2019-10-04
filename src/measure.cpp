#include<iostream>
#include"../include/measure.hpp"
#include"../include/linked_list.hpp"
#include"../include/operation.hpp"

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
    Vessel* vessel;
    Operation* operation;
    int amount, measured_amount;

    for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next()){
        vessel = it->get_object();
        amount = vessel->get_capacity();
        if(amount == q){
            operations->clear(ITERATIVE);
            delete operations;
            return 1;
        }
        operations->add(new Operation(1, amount));
    }

    while(operations->length() > 0){
        operation = operations->remove(0);
        measured_amount = operation->get_measured_amount();
        for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next()){
            vessel = it->get_object();
            amount = vessel->get_capacity();
            if((measured_amount + amount == q) || (measured_amount - amount == q)){
                int result = operation->get_vessel_amount()+1;
                delete operation;
                operations->clear(ITERATIVE);
                delete operations;
                return result;
            }
            else{
                operations->add(new Operation(operation->get_vessel_amount() + 1, measured_amount + amount));
                if((measured_amount - amount) > 0){
                    operations->add(new Operation(operation->get_vessel_amount() + 1, measured_amount - amount));
                }
            }
        }
        delete operation;
    }
    operations->clear();
    delete operations;
    return -1;
}

void Measure::execute(LinkedList<Vessel>* vessels, char type, int q){
    switch (type){
        case 'i':
            Measure::add_vessel(vessels, q);
            // Measure::print_vessels(vessels);
            break;

        case 'r':
            Measure::remove_vessel(vessels, q);
            // Measure::print_vessels(vessels);
            break;

        case 'p':
            std::cout << Measure::min_measure(vessels, q) << std::endl;
            break;

        default:
            break;
    }
}

void Measure::print_vessels(LinkedList<Vessel>* vessels){
    int cell_i = 0;
    std::cout << '[';
    for (Cell<Vessel>* it = vessels->begin(); it != nullptr; it = it->get_next(), cell_i++){
        Vessel* vessel = it->get_object();
        if(vessel != nullptr){
            if(cell_i > 0){
                std::cout << ", ";
            }
            std::cout << vessel->get_capacity();
        }
    }
    std::cout << ']' << std::endl;
}